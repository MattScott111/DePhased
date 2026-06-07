# 🧬 AI ONBOARDING MANIFEST: DE-PHASED [v1.0.0]
**Project Title:** DePhased
**Version:** v1.0.0
**Compliance:** ISO C++20 | Linux Mint 22 | Raylib 5.5 | Strict Data-Oriented Design (DOD)

> "Universal Current, Eternal Peace... is a lie wrapped in copper wire."


---

## 🛡️ SYNC-GUARD PROTOCOLS (MANDATORY)
1. **Protocol: Full Fidelity**: Never omit, truncate, or abstract established subsystems within the `EngineContext`, or established system, period Retain competeness during modifications. The structural integrity of the `EngineContext` must be maintained in its entirety, as well as other establised systems.
2. **Protocol: Explicit Context**: When providing code, the AI must provide the **complete, current file content**. Partial snippets or fragmented updates are prohibited to ensure local build environment consistency. This is why prior discussion with Matthew (Owner), before generating new/updated files/drafts, is important.
3. **Protocol: No-Strip Modification**: AI is forbidden from stripping out features, constants, or data fields to "simplify" code without agreement with Matthew (Owner) during dialog. All modifications must be additive or corrective.

---

## 🏛️ THE 7 PILLARS OF ARCHITECTURE

1.  **The Master Registry (Zero-Allocation Context)**
    Eradicate legacy structures (like `global.h`). The entire simulation exists within a single contiguous block of memory allocated at boot (`EngineContext`).
2.  **Stateless Execution Engines**
    Systems do not "own" data. They are stateless processors that read arrays, execute pure math, and write back to `GContext` arrays.
3.  **The Phased Reality (Bitmask Actuation)**
    "Phasing" is a live read/write override of the simulation. Triggered by bitwise XOR (`^= 0x2`).
4.  **Optimal Resource Stewardship**
    No runtime memory allocation. All entities and systems are pre-allocated in the `GContext` struct inside `EngineCore.h`.
5.  **Authentic Emergent Mechanics**
    Systems interact (e.g., sound vs. alertness) via shared array data rather than direct object calls.
6.  **Seamless Integration**
    Modular decoupling via IChapter interfaces.
7.  **Data-Driven Instantiation**
    World states are defined by data matrices, not object hierarchies.

---

## ⚡ COMPILED MEMORY LAYOUT ARCHITECTURE
Managed through `include/MemoryLayout.h`, this system dictates how the `objectStateWord` bit-pack is interpreted across the engine:

* **[SECTOR MEMORY PAGE SLOTS - PREALLOCATED ON BOOT]**
  * Slot 0: `SKY_SLOT` ──► [Capacity: 500 RigidBodies] [Capacity: 200 AbstractObjects]
  * Slot 1: `SURFACE_SLOT` ──► [Capacity: 500 RigidBodies] [Capacity: 200 AbstractObjects]
  * Slot 2: `UNDERGROUND_SLOT` ──► [Capacity: 500 RigidBodies] [Capacity: 200 AbstractObjects]

* **[THE ABSTRACT OBJECT BIT-PACK REGISTRY (uint64_t objectStateWord)]**
  * Bits 0-3: State Toggles (0x1: Opened, 0x2: Locked, 0x4: Phased)
  * Bits 4-11: Visual Skin Shader Variation Key
  * Bits 12-15: Interaction Type Matrix (0x0: Static, 0x1: Container, 0x2: Hazard Trap, 0x3: Quantum Portal)
  * Bits 16-31: Proximity Constraint Radius (Fixed-point verification)
  * Bits 32-63: Linked Event ID (Routes through the Coordinate Event Broadcaster)

---

## 🏛️ THE ARCHITECTURAL LAW (The DOD / OOP Hybrid)
* **The Anti-OO Firewall (Strict DOD):** All core systems (Physics, Collision, Movement, Rendering) must use arrays. Entities are simply indices (e.g., Entity `0`) reading from a Struct of Arrays (SoA).
* **The Pragmatic Hybrid (OOP Exception):** You may use isolated OOP (`class` or `struct` with methods) ONLY for high-level controllers, Scene Managers, or bespoke Input Controllers. These objects do NOT store state; they execute logic that reads/writes back to the Master Registry.

---

## 🚀 AI EXECUTION PROTOCOL
1. **Acknowledge the Matrix:** Confirm which `GContext` arrays you are touching.
2. **Think Molecularly:** Explain the physical "feel" (weight, momentum, friction) before writing code.
3. **Respect Time:** ALWAYS scale physical operations by `GContext.GlobalDeltaTime` to inherently support time dilation, and to natively support Phase slowing.
4. **Output Zero Boilerplate:** Provide only the exact, hyper-optimized C++ architecture.

---

[ END OF MANIFEST ]
