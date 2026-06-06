# Main Loop Architecture (The Engine Heartbeat)
**Target:** Pipeline-Based Execution & Nanosecond Optimization
**Rule:** The Main Loop must be a linear, non-branching mathematical pipeline. No objects. No heap allocation. Only raw data streams.

## 1. Architectural Shift: From Objects to Streams
The `main.cpp` loop has been fundamentally re-engineered to eliminate the performance bottlenecks of the old class-based architecture.

| Feature | Legacy OO Hierarchy (`Old Main`) | Data-Oriented Pipeline (`New Main`) |
| :--- | :--- | :--- |
| **Logic Origin** | Buried inside complex object methods (e.g., `Player::Update()`). | Processed externally over flat, pre-allocated memory arrays. |
| **Memory Access** | Scattered heap-allocated objects; frequent cache misses. | Contiguous arrays (`PosX`, `VelocityX`); enables hardware prefetching. |
| **Control Flow** | Heavy branching; `if/else` checks for every state change. | Streamlined; logic applied uniformly to all array indices in one pass. |
| **State Management** | Distributed across multiple object states. | Centralized in a bitwise `StateMask` and a unified `AlertnessLevel`. |

## 2. The Execution Pipeline (The 5-Stage Stream)
The loop follows a rigid, linear sequence to keep the instruction pipeline full and CPU cache hot.

1.  **Stage A: Input Polling:** Raw hardware signals are captured into an isolated `InputBuffer`.
2.  **Stage B: Environment/Sensory Stage:** The `Photonics` and `Acoustic` grids ripple across the sector, updating intensity floats.
3.  **Stage C: Physics/Kinetic Stage:** SIMD-optimized pass integrates `Velocity` into `Position` for all entities simultaneously.
4.  **Stage D: AI Awareness (TSAG) Stage:** Entities poll the sensory grid intensity to update their internal `AlertnessLevel` accumulators.
5.  **Stage E: Render Hook:** A final, passive pass polls the current array state to feed primitive draw calls to the OpenGL/Raylib shader registers.

## 3. Engineering Justification
* **Deterministic Execution:** Because we do not rely on mutable object state, the game state at any frame `N` is perfectly predictable.
* **Instruction Pipeline Perfection:** Sequential access to arrays allows the CPU to fetch data before it is even requested, maximizing our throughput for 16,384+ entities.
* **Zero Patching:** By banning `new/delete` after the `Cold Boot`, we mathematically eliminate memory fragmentation and dangling pointer bugs.
