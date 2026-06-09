# 🖥️ ARCHETYPE: Interface Design
## FILE: Terminal_Branching_Logic
**Version:** 1.0.0 | **Compliance:** Strictly Data-Oriented (DOD)

### 1. The Hub Hierarchy
The flow of the engine is designed to accommodate branching nodes seamlessly. The master flow is:
`Boot Sequence -> Main Menu -> Branch Selection -> Deep Node (Terminal / Level)`

### 2. The Terminal UI Node
The Terminal is a deep UI node (`ActiveUI_ID = 2`). It acts as an interactive database for Achievements, Lore, and Bestiary profiles.
- When accessed, it reads directly from `GContext.SaveData.UnlockedLore[]`.
- There are no loading screens to access the Terminal. The Universal Router simply shifts the active drawing pointer, keeping the engine running at 60+ FPS during the transition.
