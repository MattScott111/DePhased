markdown_content = """# 🗂️ UNIVERSAL MANIFEST DOCUMENTATION PROTOCOL (UMDP)
**Version:** 1.0.0 | **Design Paradigm:** Data-Oriented Design (DOD)

*This meta-protocol dictates the absolute structural law for all engine documentation. Every feature, system, and entity must be documented using its corresponding archetype to ensure zero Object-Oriented bloat and maximum Data-Oriented clarity for both human architects and AI agents.*

---

### **[GLOBAL HEADER]** *(Mandatory at the top of ALL documents)*
* **Module:** `[System/Feature Name]`
* **Designation:** `[Core Engine / UI / Physics / Economy / Entity]`
* **Status:** `[Draft / Locked / Implemented]`
* **File Hook:** `[Exact file path, e.g., source/MovementEngine.cpp]`
* **AI Context Vector:** `[Comma-separated keywords for LLM attention, e.g., Lerp, GContext.VelocityX, rawDelta]`

---

## ⚙️ FOLDER: `[00_Code_Engineering]`
### **Archetype: The Logic Processor**
*Use for core engine loops, system pipelines, and raw mathematical engines.*

1. **ABSTRACT & VIBE:** Mathematical purpose and the kinetic "feel" for the player.
2. **DATA ARCHITECTURE & DEPENDENCIES:**
   * **Reads:** `[GContext arrays queried]`
   * **Writes:** `[GContext arrays mutated]`
   * **Cross-Pollination:** `[Which external systems rely on the data this engine writes?]`
3. **EXECUTION PIPELINE:** Chronological, step-by-step logic executed per frame.
4. **THE FAILURE CASCADE:** How the math weaponizes or visualizes failure when pushed to extreme limits (e.g., infinite velocity).
5. **STRICTURES:** Unbreakable DOD engineering rules (e.g., "Must multiply by TimeDilation").

---

## 🖥️ FOLDER: `[01_Interface_Design]`
### **Archetype: The Data-Driven Observer**
*Use for HUDs, Menus, and Diegetic UI. UI has no state; it merely observes the registry.*

1. **ABSTRACT & VIBE:** Aesthetic intent (e.g., raw data stream, hacked terminal).
2. **REGISTRY HOOKS:** Exact `GContext` variables rendered to screen space.
3. **INPUT INTERCEPTION:** How menu keystrokes mutate state without allocating objects.
4. **THE GLITCH PROFILE:** How this UI visually corrupts when `PhaseStability` or system health decays.
5. **STRICTURES:** Rendering execution rules (e.g., Screen-space overlay bypassing 2D camera).

---

## 🌍 FOLDER: `[03_Physics_Environment]`
### **Archetype: The Environmental Stratum**
*Use for level topographies, collision matrices, and environmental memory blocks.*

1. **ABSTRACT & VIBE:** Atmospheric weight and geometric architecture.
2. **TOPOGRAPHY MATRIX:** How static collision is stored in memory.
3. **ENTITY POPULATION:** Initial Entity Blueprints injected upon load.
4. **THE ALGORITHMIC PULSE:** The mathematical sine-wave "heartbeat" of the environment (e.g., timed flickering lights, shifting logic nodes).
5. **TRANSITION HOOKS:** Bitmasks required to unload this memory block and jump to the next chapter.

---

## 💎 FOLDER: `[04_Economic_Systems]`
### **Archetype: The Resource Matrix**
*Use for inventory arrays, currencies, and upgrade progression.*

1. **ABSTRACT & VIBE:** Lore and psychological weight of harvesting/trading.
2. **THE DATA FOOTPRINT:** Arrays allocated to track accumulation.
3. **THE EXCHANGE PIPELINE:** Math for transacting, looting, or transferring values.
4. **THE DEFICIT/CORRUPTION STATE:** Gameplay consequences of maxing out or carrying "heavy" data (e.g., slowing movement speed).
5. **STRICTURES:** Data serialization (Save/Load) constraints.

---

## 🧬 FOLDER: `[05_Entity_Blueprints]`
### **Archetype: The Entity Form**
*Use for Characters, Enemies, and interactive Logic Nodes.*

1. **ABSTRACT & VIBE:** Narrative threat and psychological presence.
2. **THE DATA FOOTPRINT:** Exact float/int default values injected into `GContext` at spawn (Mass, Radius, Speed).
3. **ALGORITHMIC INTENT (AI):** How it natively mutates its own data to interact with the world (e.g., Pathfinding vectors).
4. **THE ORPHAN STATE:** What data remains frozen in memory when its `ActiveMask` drops to `0` (for player scavenging/harvesting).
5. **RESONANCE SHIFT:** How it renders in standard Physical mode vs. De-Phased mode.
"""

file_path = "UMDP_Meta_Protocol_v1.0.0.md"
with open(file_path, "w") as f:
    f.write(markdown_content)

print(f"Successfully generated {file_path}")
