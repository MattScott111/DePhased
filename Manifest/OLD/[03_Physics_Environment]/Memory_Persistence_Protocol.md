# Memory Persistence Protocol (Save/Load)
**Target:** Blisteringly Fast Disk I/O
**Rule:** Saving and loading bypasses traditional JSON/XML serialization entirely to eliminate parsing overhead. Persistence is a raw binary dump.

## 1. Partitioned Memory Targeting
To keep save files tiny and loading times instantaneous, we separate our flat memory blocks.
* **Persistent Arrays:** Holds Young Sir, unlocked Anchor Pins, essential NPCs, and the `g_AchievementMask`. **This is the only memory block that gets saved.**
* **Volatile Arrays:** Holds procedurally generated enemies, dynamic scrap, and weather nodes. This block is entirely ignored by the save function and wiped when a new mathematical seed is loaded.

## 2. The Binary Dump Mechanism
In traditional engines, saving loops through objects to extract data. In De-Phased, we utilize a direct RAM-to-Disk pipeline.
* **The Save:** A literal `std::memcpy` of the Persistent Array block directly to a binary `.sav` file on the disk.
* **The Load:** Reading the binary file and dumping it straight back into the exact same pre-allocated array indices.

## 3. Structural Security & Array Optimization
A blind memory dump introduces versioning and corruption risks. To maintain a "holy" engine, our pipeline strictly enforces three security layers:

| Security Layer | Execution Strategy | System Purpose |
| :--- | :--- | :--- |
| **1. Binary Header** | Prepends `uint16_t g_SaveVersion`, `int32_t activeSectorSlot`, and `uint32_t blueprintSeed` to the top of the file. | Prevents fatal struct-size crashes on load. Ensures the exact procedural grid and vertical stratum load identically. |
| **2. Active Packing** | Tracks a `High-Water Mark` (an integer pointing to the last active index in the array). The `memcpy` stops exactly at this index limit. | Prevents writing megabytes of empty, pre-allocated zeroes to the disk. Save files remain in the kilobyte range. |
| **3. Integrity Checksum** | Calculates a 32-bit hash (e.g., MurmurHash32) of the raw array data and appends it to the tail of the binary file. | RAM Security. If the loaded file's hash fails to match, the engine aborts and throws a "Corrupted Save" error before injecting volatile memory addresses. |
