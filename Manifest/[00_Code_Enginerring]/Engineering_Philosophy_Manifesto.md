# Module: Engineering Philosophy Manifesto
* **Designation**: Logic Processor (Core Principles)
* **Status**: Locked
* **File Hook**: N/A (Meta-Documentation)
* **AI Context Vector**: DOD, Zero-Allocation, Performance, Data-Oriented Design

---

## 1. ABSTRACT
This document defines the constraints for all C++ development in *De-Phased*. We prioritize cache-friendly data layouts and deterministic memory management over Object-Oriented convenience.

## 2. THE 7 PILLARS
1. **Zero Boilerplate**: If it doesn't process data, it doesn't exist.
2. **Nanosecond Optimization**: All hot-paths must be CPU cache-aligned.
3. **Optimal Resource Stewardship**: No runtime allocations in the Main Loop.
4. **Authentic Emergent Mechanics**: Systems interact via shared data buffers, not method calls.
5. **Seamless Integration**: The engine is a single stream of predictable memory.
6. **The Universal Port**: Logic must be agnostic to the graphics/input backend.
7. **Data-Driven Instantiation**: Entities are just indices in an array; logic is in the Systems.

## 3. STRICTURES
* No virtual functions in the inner loop.
* No raw pointer chasing; use array indices or contiguous memory structures (SoA).
