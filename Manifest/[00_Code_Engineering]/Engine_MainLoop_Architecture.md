# Module: Engine Main Loop Architecture
* **Designation**: Logic Processor (Main Loop)
* **Status**: Locked
* **File Hook**: `Game/source/EngineCore.cpp`
* **AI Context Vector**: GContext.Tick, MainLoop, DeltaTime, Pipeline

---

## 1. ABSTRACT
The heartbeat of *De-Phased*. It is a linear, branchless pipeline designed for maximum deterministic throughput.

## 2. EXECUTION PIPELINE
1. **Input Phase**: `InputEngine` polls hardware, writes to `InputBuffer`.
2. **Physics Phase**: `Kinetic_Actor_Engine` updates `RigidBody` arrays.
3. **Environment Phase**: `EnvironmentEngine` resolves collisions/streaming.
4. **Logic Phase**: `ProgressionEngine` and `EconomyEngine` run state updates.
5. **Render Phase**: `Renderer` (Raylib) reads arrays and performs draw calls.

## 3. DATA STRUCTURE
* **Context**: `GContext` (The Master Registry).
* **Sync**: Every phase is synchronized via `GContext.GlobalDeltaTime`.

## 4. STRICTURES
* Total frame time must be < 16.6ms (for 60fps) or 8.3ms (for 120fps).
* If a subsystem exceeds time-budget, it is truncated.
