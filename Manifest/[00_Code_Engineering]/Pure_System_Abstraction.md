# Low-Level Specification: Pure System Abstraction & Namespace Isolation

## 🔍 System Purpose
Enforces an absolute structural firewall between runtime mathematical execution loops and level description layouts, ensuring the engine remains fully decoupled and moddable without compilation side-effects.

## 🌀 Lore & Aesthetic Integration
The universe operates on an underlying matrix of numbers. The core grid does not care if a localized current density manifests as a copper transformer, a surveillance node, or a metal safe; it only registers its underlying physical mass, spatial coordinates, and vibrational resonance frequency.

## ⚙️ Mechanical Specification
*   **The Namespace Firewall**: Every file inside the engine framework is encapsulated within `namespace DePhased`. This completely isolates our high-performance plain data structures from external library naming collisions while maintaining zero third-party dependencies.
*   **The Decoupled Mirror Interface**: In `src/main.cpp`, data translation occurs explicitly at the primitive boundary. Our `DePhased::Vector3` floating-point components are read sequentially and mirrored directly into the graphics card rendering structs via explicit scalar token copying.
*   **Zero Game-Layer Vernacular**: The core engine codebase is strictly forbidden from referencing explicit asset names, item categories, narrative quests, or faction titles.
*   **Primitive Token Mapping**: All interactive and environmental entities are stripped of abstract class behaviors and identified solely via a raw integer variable (`genericTypeID`).
*   **The 64-Bit Packed Object State Word**: To minimize memory footprints inside parallel storage rows, attributes are compressed inside a single `uint64_t objectStateWord`:
    *   *Bits 0-3 (4 bits)*: Active State Flags (e.g., 0x1: Opened, 0x2: Locked, 0x4: Interacted).
    *   *Bits 4-11 (8 bits)*: Visual Skin Variant (Supports up to 256 unique visual shaders/textures).
    *   *Bits 12-15 (4 bits)*: Interaction Type (0x0: Static Decoration, 0x1: Container, 0x2: Hazard, 0x3: Transit Portal Node).
    *   *Bits 16-31 (16 bits)*: Proximity Constraint Radius (Fixed-point scale; default 2.0-meter validation ring).
    *   *Bits 32-63 (32 bits)*: Linked Coordinate Event Broadcaster ID.
*   **Flat Payload Buffers**: Structural entities utilize a fixed-allocation parallel integer array (`dataPayload`) to house custom data markers (e.g., loot indices, portal destination vectors) without heap reallocation.

## 🧠 Thought Process & Logic Architecture
### The Compilation Coupling Trap
Hardcoding individual game items or locker logic inside environmental solvers permanently chains the engine to a single game configuration. Any modification to an asset or vendor requires recompiling the entire framework.

### The Decoupled Spatial Solution
By reducing levels down to numeric blueprint structures that write straight into preallocated parallel streaming pages, the engine transforms into a clean memory-writing tool. Objects handle interaction via an abstract parameterless proximity check, passing raw data arrays through a central context matrix to external game-layer interpreters.

## ⛓️ Interconnected Dependencies
*   Establishes the structural array parameters populated inside **Level_Manifest_Architecture.md**.
*   Provides the abstract data payload fields evaluated by the spatial partition grids inside **[04_Code_Engineering]/Multi_Sector_Streaming.md**.
