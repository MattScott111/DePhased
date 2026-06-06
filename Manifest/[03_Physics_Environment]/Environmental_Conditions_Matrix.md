# Environmental Conditions & Barometric Matrix
**Target:** Data-Driven Instantiation & Physics Yield
**Philosophy:** The environment is not a script. It is a set of raw data multipliers that dynamically throttle the physics matrices.

## 1. Barometric Pressure (Altitude & Stratums)
[cite_start]Vertical coordinate data points ($Y$) calculate localized atmospheric pressure equations instantly without volumetric fluid gas computing loops[cite: 420].

* [cite_start]**Sky Stratum ($Y > 20m$):** $P = 0.5\text{atm} \rightarrow 0.7\text{atm}$[cite: 420]. 
  * *Effect:* Low drag, fast projectiles. [cite_start]Player energy recovery drops by 25%[cite: 421].
* **Surface Stratum ($0m \le Y \le 20m$):** $P = 1.0\text{atm}$ (Baseline).
  * *Effect:* Standard 1.0x multiplier on all dynamic movement matrices.
* [cite_start]**Underground Stratum ($Y < 0m$):** $P = 1.3\text{atm} \rightarrow 2.0\text{atm}$[cite: 421].
  * *Effect:* High fluid air density; [cite_start]30% projectile drag penalty[cite: 422]. [cite_start]Acoustic resonance wave propagation multiplies kinetic combat vectors by $+30\%$[cite: 423].

## 2. Surface Traction & Friction Multipliers
Traction is a pure float applied to the `Dynamic_Movement_Matrix`. When entities with heavy mass (e.g., Scrap-Hauler) engage with altered terrain, their momentum dictates slip.

| Condition | Friction Float | Kinetic Yield |
| :--- | :--- | :--- |
| **Standard Grid** | `1.0f` | Perfect cache-aligned movement tracking. |
| **Coolant Spill** | `0.3f` | Heavy mass units retain forward momentum; severe turning radius degradation. |
| **Static Storm** | `0.6f` | Ground friction reduced; applied electrical drag increases jitter in velocity vectors. |

## 3. Visibility & Performance Culling Interference
[cite_start]Weather conditions directly throttle CPU workload by interacting with entity bitmasks[cite: 417, 418].

* [cite_start]**Dense Fog / Signal Jamming:** Instantly flips the visibility tracking bit in an entity's mask to `0`[cite: 418]. 
* [cite_start]**Result:** The AI finite state machines drop calculations for that actor instantly, saving critical cycles by skipping line-of-sight raycasts and pathfinding code arrays entirely[cite: 418].
