# Engineering Specification: Cache Optimization & Data-Oriented Design (DOD)

## 🔍 System Purpose
Outlines the continuous memory allocation paradigms required to guarantee microsecond and nanosecond execution speeds by eliminating CPU cache misses.

## ⚙️ Mathematical & Hardware Reality
Modern CPUs do not fetch data from system RAM byte-by-byte. They pull data in fixed continuous blocks called **Cache Lines** (typically 64 bytes wide) directly into the L1/L2 hardware registers. 
*   **Object-Oriented Trap (Array of Structures - AoS)**: Storing objects as independent heap-allocated pointers scattered across RAM forces the CPU to jump locations constantly, destroying performance via massive cache misses.
*   **Data-Oriented Solution (Structure of Arrays - SoA)**: Packing identical, primitive data types flush against each other inside flat arrays ensures that a single 64-byte hardware fetch loads up to 16 consecutive 4-byte floating-point coordinates simultaneously.

## 💎 Direct Memory Comparison
### Standard Unoptimized Array of Structures (AoS)
```text
[ Entity 00 (Pos, Vel, Mass, Name) ] -> Jump RAM Heap -> [ Entity 01 (Pos, Vel, Mass, Name) ]
```
*Result: Severe cache fragmentation. Every access line wastes bandwidth pulling metadata or string labels into the execution core.*

### High-Performance Structure of Arrays (SoA) Layout
```text
[ Positions Array (Continuous Flat Memory) ]

| x0, y0, z0 | x1, y1, z1 | x2, y2, z2 | x3, y3, z3 | ...

[ Velocities Array (Continuous Flat Memory) ]

| v0, v0, v0 | v1, v1, v1 | v2, v2, v2 | v3, v3, v3 | ...

[ Mass Variables Array (Cache-Aligned) ]

|   mass0    |   mass1    |   mass2    |   mass3    | ...
```

## 🧠 Core Engineering Principles
1.  **Ditch Virtual Invocations**: Virtual tables (`vtables`) require deep pointer lookups that flush instructions out of the pipeline. System steps must pass flat structural buffers down linear execution blocks.
2.  **No Dynamic Mid-Frame Allocations**: The keywords `new` and `delete` (or dynamic expansions like `std::vector::push_back`) invoke heavy OS kernel memory arbitrations. All memory for the sandbox levels must be completely pre-allocated as a single fixed block on engine initialization.
3.  **Strict Boolean Bit-Masking**: Instead of wasting 1 to 4 bytes on a boolean flag like `isGrounded` inside every entity, object states are tracked via a single, packed continuous bit-mask primitive array (`uint32_t`).

## ⛓️ Interconnected Dependencies
*   Dictates how physics forces are applied frame-by-frame inside **[03_Physics_Environment]/Dynamic_Movement_Matrix.md**.
*   Directly models how bulk items and structural grid blocks are read out of memory arrays inside **Layered_Inventory_Matrix.md**.

