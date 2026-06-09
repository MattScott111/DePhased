# Memory Grid & SIMD Optimization
**Target:** Blistering Execution Speed & Cache Alignment
**Rule:** The engine strictly forbids arbitrary array sizes. All memory allocations must align perfectly with hardware-level CPU cache lines.

## 1. The SIMD Memory Ceiling (Power of 2)
To maximize L1/L2 cache prefetching, the maximum active entity limit is permanently locked to a strict power of 2.
* `MAX_ACTIVE_ENTITIES = 16384` ($2^{14}$).
* `MAX_ACTIVE_LIGHTS = 256` ($2^8$).

## 2. Hardware Cache Alignment
All parallel data arrays (Positions, Velocities, Mass) are enforced using the C++ `alignas(64)` keyword. 
* **The Yield:** This guarantees our data perfectly matches the 64-byte L1 cache lines of modern processors without trailing garbage data.
* **The Execution:** The CPU can pull and calculate the velocity and mass of 8 sequential entities in a *single hardware clock cycle* using Advanced Vector Extensions (AVX).
