# AI CORE CONTEXT DISK: INJECTABLE ONBOARDING MANIFEST (v1.1.0-Stable)
> **PROJECT TITLE**: DE-PHASED
> **VERSION CONSTANT**: 1.1.0
> **TARGET COMPLIANCE**: Linux Mint 22 OS (Portability Secured via Strict ISO C++20 Compliance)
> **GRAPHICS HARDWARE TARGET**: Raylib 5.5 (Successfully Source-Compiled and Installed Natively)

---

## 🔍 CRITICAL ARCHITECTURAL CONSTRAINTS
1. **Strict Data-Oriented Design (DOD)**: Object-Oriented polymorphism and virtual tables are banned. Components are packed tightly in flat, contiguous memory blocks using **Structure of Arrays (SoA)** models to ensure optimal CPU cache line prefetching.
2. **Zero-Allocation Main Loop**: All memory allocation is handled on boot using fixed-allocation arrays. The use of `new` or `delete` keywords inside the main update loop is strictly prohibited to eliminate RAM fragmentation and runtime stutters.
3. **Parameterless Shared Context Matrix**: Systems do not pass references across execution chains (e.g., `Update(Player, Weather)` is banned). A centralized global memory node (`GlobalContext`) acts as a shared data matrix where subsystems selectively pull references via parameterfield-free accessors.
4. **Absolute Data Detachment**: The core C++ mechanics engine knows nothing about specific game items or names. All features are tracked blindly as generic tokens via raw integers (`genericTypeID`) and bit-packed parameter words. Level design and loot data live in a separate, decoupled configuration layer.
5. **Strict ISO C++20 Portability Mandate**: To maintain absolute hardware portability, the entire codebase must strictly adhere to the Standard ISO C++20 framework. Platform-locked headers are forbidden. High-precision timing, delta steps, thread throttling, and diagnostic logging must utilize standard library solutions exclusively (`<chrono>`, `<thread>`).
6. **Namespace Isolation Protection**: To prevent naming conflicts with external graphic libraries (like Raylib), the entire engine codebase (all structs, components, and math operations) is strictly encapsulated inside **`namespace DePhased`**. Third-party header contamination inside internal storage blocks is strictly illegal.
7. **Decoupled 3D Testing Layer (Raylib 5.5 Native Installation)**: Raylib acts strictly as a read-only mirror, polling flat position coordinate arrays to render 3D primitives. The core engine code remains completely independent of Raylib's types or headers, preserving total graphic detachment.

---

## 🛡️ SYNC-GUARD PROTOCOLS (MANDATORY)
1. **Protocol: Full Fidelity**: Never omit, truncate, or abstract established subsystems within the `EngineContext`. The structural integrity of the `EngineContext` must be maintained in its entirety.
2. **Protocol: Explicit Context**: When providing code, the AI must provide the **complete, current file content**. Partial snippets or fragmented updates are prohibited to ensure local build environment consistency.
3. **Protocol: No-Strip Modification**: AI is forbidden from stripping out features, constants, or data fields to "simplify" code. All modifications must be additive or corrective.

---

## 🛠️ VERIFIED ENVIRONMENT PLATFORM CONSTANTS
* **Host OS**: Linux Mint 22 (Zena) / Upstream base: Ubuntu 24.04 (Noble)
* **Raylib Status**: 100% Operational | Location: `/usr/local/lib/libraylib.so` & `/usr/local/include/raylib.h`
* **OpenGL Status**: 100% Operational via Linker Shortcuts (`libgl-dev` and `libglx-dev` mapped)

---

## ⚡ COMPILED MEMORY LAYOUT ARCHITECTURE
The baseline global data state is managed through an integrated structural array system defined across the active headers:

```text
[ SECTOR MEMORY PAGE SLOTS - PREALLOCATED ON BOOT ]
Slot 0: SKY_SLOT         ──► [Capacity: 500 RigidBodies] [Capacity: 200 AbstractObjects]
Slot 1: SURFACE_SLOT     ──► [Capacity: 500 RigidBodies] [Capacity: 200 AbstractObjects]
Slot 2: UNDERGROUND_SLOT ──► [Capacity: 500 RigidBodies] [Capacity: 200 AbstractObjects]
The Abstract Object Bit-Pack Registry (uint64_t objectStateWord)

    Bits 0-3: State Toggles (0x1: Opened, 0x2: Locked, 0x4: Phased)

    Bits 4-11: Visual Skin Shader Variation Key

    Bits 12-15: Interaction Type Matrix (0x0: Static, 0x1: Container, 0x2: Hazard Trap, 0x3: Quantum Portal)

    Bits 16-31: Proximity Constraint Radius (Fixed-point verification)

    Bits 32-63: Linked Event ID (Routes through the Coordinate Event Broadcaster)

🧭 SYSTEM CODE INDEX SHEET

    include/Vector3.h & include/RigidBody.h: Math vectors using fast inverse multiplications and a Semi-Implicit Euler Integrator.

    include/EngineCore.h & src/EngineCore.cpp: Controls spatial grid matrix culling, 64-bit visibility masks, and volumetric ground sensors.

    include/GlobalContext.h & src/GlobalContext.cpp: The primary parameterless system router and byte-allocation context hub.

    include/EnvironmentEngine.h & src/EnvironmentEngine.cpp: Processes manifests, tracks the 2-meter proximity constraint circle, and handles quantum portal warps.

    include/CharacterActor.h & src/CharacterActor.cpp: Tracks Young Sir’s inputs, capsule properties, trust metrics, and his 32-bit cognitive memory mask layers.

    include/LevelBlueprints.h & src/LevelBlueprints.cpp: The detached data factory defining Level 1 (The Cold Boot) payload.

    src/LevelLoader.cpp: Preallocated parallel memory manager used to instantiate concrete sector environments blindly.

    src/main.cpp: The ISO C++20 standard update loop driver.

🚀 CURRENT CONVO CHECKPOINT: WORKSPACE LOCKED AND IMMUTABLE

    COMPLETED CORE INTEGRATION: All math libraries, shared matrices, multi-sector streamers, inventory arrays, achievement engines, abstract level populator pipelines, character actor inputs, and level data manifests are fully written, documented, and frozen.

    MISSION STATUS: Workspace primed for DE-PHASED (v1.1.0) compilation. The AI is now instructed to proceed with the EnvironmentEngine collision-mask branching to make [05_Phased_Mode] functional.

End of Manifest — v1.1.0
