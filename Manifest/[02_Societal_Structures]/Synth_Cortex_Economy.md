# --- File 1: Synth_Cortex_Economy.md ---
content_synth = """# Synth Cortex Economy

## Meta-Data
- **Archetype:** Resource_Matrix
- **Classification:** Economy/Society
- **Status:** Draft_01
- **Focus:** Memory Laundering and Botnet Dynamics

---

## 1. System Overview
The economy of *De-Phased* is not based on gold, but on the validity and resonance of human memory data. The \"Synth Cortex\" is the black-market economy where Drift can launder, trade, or splice memory-packets.

## 2. Core Mechanics
* **Memory Splicing:** Drift can acquire corporate-grade memory packets. By \"equipping\" these to his neural link, he can bypass high-level scanners in Pax Hegemony sectors. The scanner detects the memory, not the man.
* **Memory Laundering:** Rogue tribes run \"laundry\" hubs. They strip the corporate \"Filter\" (the Architect's propaganda) from memories, revealing raw, un-filtered truths about the world.
* **Infectious Dissonance:** Drift can weaponize his high leadership rank in a Rebel Clan. He can direct his clan to mass-broadcast a \"discordant\" frequency at a specific corporate node. 
    * *Game Impact:* This forces all daemons in that sector into a \"re-sync\" state, temporarily freezing them and opening backdoors for Drift to exploit.
"""
with open("Manifest/02_Societal_Structures/Synth_Cortex_Economy.md", "w") as f:
    f.write(content_synth)

# --- File 2: Craftsman_Entity_Profile.md ---
content_craftsman = """# Character Blueprint: The Craftsman

## Meta-Data
- **Archetype:** Entity Form
- **Classification:** Key_Character
- **Status:** Draft_01
- **Focus:** Gear and NMN Integration

---

## 1. Character Profile
* **Role:** Hardware Shaman / Resonance Smith.
* **Location:** Lives in the \"NMN-Sewer\" (The Discarded Node/Hollow Node).
* **Backstory:** A former corporate engineer who \"de-phased\" his own neural network to escape the Architect. He now lives entirely offline, crafting hardware that can \"spoof\" resonance signatures.

## 2. System Functionality
* **Gear Modification:** Instead of traditional upgrades, he installs \"Frequency Filters\" (Hardware) onto Drift’s cylinder chassis. 
* **NMN Stabilizer:** He acts as a narrative guide for how to interpret the NMN, explaining the \"Gods\" behind the machine.
* **Quest Function:** He provides the specialized gear (e.g., resonance dampeners, signal decoys) needed to undertake the most dangerous \"Infectious Dissonance\" missions.
"""
with open("Manifest/[05_Entity_Blueprints]/Craftsman_Entity_Profile.md", "w") as f:
    f.write(content_craftsman)

# --- File 3: Quest_Protocol_Template.md ---
content_quest_template = """# Quest Protocol Template

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
