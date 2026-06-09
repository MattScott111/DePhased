# ⚙️ ARCHETYPE: Logic Processor
## FILE: Memory_Persistence_Protocol
**Version:** 1.2.0 | **Compliance:** Strictly Data-Oriented (DOD)

### 1. The Persistence Boundary Concept
In Object-Oriented engines, saving the game requires traversing a complex web of object pointers and serializing them individually. De-Phased eliminates this overhead by establishing a strict **Persistence Boundary** within the Master Registry.

### 2. The PersistentState Struct
All data that must survive an application restart is grouped into a single, contiguous block of memory: `GContext.SaveData`.
- `SaveVersion`: Ensures future updates don't break old saves.
- `ActiveChapterID`: The current node in the narrative routing.
- `Pos[MAX_ENTITIES]`: The spatial coordinates of all persistent entities.
- `StateMask[MAX_ENTITIES]`: Tracks which entities are dead, phased, or active.
- `DeuteriumReserve`: The player's currency.
- `UnlockedLore[]`: Boolean arrays tracking achievements and terminal discoveries.

### 3. The 1-Click Save/Load Operation
Because the saveable data is physically isolated in memory, saving the game is a single execution line:
`fwrite(&GContext.SaveData, sizeof(PersistentState), 1, saveFile);`
Loading the game pulls the binary block directly back into RAM in exactly one CPU cycle. Zero parsing, zero allocation.
