# Level Manifest Architecture (Procedural vs. Static)

## 1. Partitioned Memory Pages
To maintain a blisteringly fast Save/Load feature, our flat, contiguous memory blocks are strictly divided on boot:

* **Persistent Arrays (Saved):** Pre-allocated blocks holding Young Sir, locked/unlocked Anchor Pins (Base Camps), `g_AchievementMask`, and story-critical objects.
* **Volatile Arrays (Wiped):** Pre-allocated blocks holding procedurally generated enemies, dynamic scrap, and weather nodes. Overwritten entirely when a new seed is loaded. **Ignored during game saves.**

## 2. The Sector Blueprint
The ruleset for a procedural level generation. Instead of calling `new Enemy()`, the engine runs a nanosecond pipeline:
1. **Read Base Data:** Extracts default stats from the Threat Matrix (e.g., Base Mass).
2. **Apply Sector Multipliers:** Scales mass and velocity caps based on the level's specific threat tier.
3. **Memory Injection:** Drops the raw data into an available slot in the Volatile Arrays.

## 3. Spatial Validation (Anti-Overlap Check)
When the Volatile Arrays are populated via the mathematical seed, the engine reads Young Sir's singular $(X, Y, Z)$ coordinate in the Persistent Array.
* A "Dead Zone" radius is mathematically established around Young Sir.
* If a Volatile entity's generated coordinate falls within the radius, the vector is simply pushed outward. Zero complex physical collision detection is used during generation.
