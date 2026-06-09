# Quest Protocol Template

## Meta-Data
- **Archetype:** Logic_Processor
- **Classification:** Quest_Architecture
- **Status:** Locked_Template
- **Focus:** Protocol for Job Instantiation

---

## 1. System Protocol
All jobs must be instantiated via the `Tension_Response_Job_System`. Quests are data objects, not static scripts.

## 2. Structure Requirements (All Quests)
* **Trigger:** [NMN_Dissonance_Value] (e.g., Sector_Stability < 20%)
* **Target:** [Faction_Node_ID] (e.g., Aegis_Processor_01)
* **Plane_Association:** [PLANE_A_PHYSICAL / PLANE_B_DIGITAL]
* **Reward_Registry:** [Resonance_Adjustment / Data_Packet_Bit]

## 3. Implementation
The `Quest_Engine` checks the `GContext` at every sector entry for dissonance spikes. If found, it spawns the relevant objective automatically.
