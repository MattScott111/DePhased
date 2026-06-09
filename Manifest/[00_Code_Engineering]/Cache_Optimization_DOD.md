# Module: Cache Optimization (DOD)
* **Designation**: Logic Processor (Performance)
* **Status**: Locked
* **File Hook**: `Game/source/EngineCore.cpp`
* **AI Context Vector**: CacheLine, StructOfArrays, MemoryLayout

---

## 1. ABSTRACT
The guidelines for structuring memory to ensure our CPU never stalls waiting for RAM.

## 2. MEMORY LAYOUT STRATEGY
* **SoA (Struct of Arrays)**: We prefer SoA over AoS (Array of Structs) to ensure that when we update a component (like `Position`), we load only the relevant data into the cache, not the entire entity object.

## 3. PERFORMANCE RULES
1. **Contiguity**: All entity data must be contiguous in memory.
2. **Predictability**: Use linear iteration for all system updates.
3. **Alignment**: Ensure structs are padded for 64-byte cache line alignment where necessary.

## 4. STRICTURES
* If you see `new` or `malloc` in the main loop, that is a violation of DOD principles.
