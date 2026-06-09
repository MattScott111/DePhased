# ⚙️ ARCHETYPE: Logic Processor
## FILE: Engine_MainLoop_Architecture
**Version:** 1.2.0 | **Compliance:** Strictly Data-Oriented (DOD)

### 1. The Universal Router Concept
The main loop in De-Phased has been completely decoupled from hardcoded scene logic. It acts as a **Universal Router**. It does not care *what* is being updated or drawn; it only cares about delegating Execution permissions based on the Master Registry (`GContext.ExecutionMask`).

### 2. Zero-Allocation Pointer Swapping
Instead of destroying and instantiating chapter classes (which fragments memory), all core systems (Menus, Chapters, Terminals) are instantiated once on the stack prior to the main loop.
- A single `IChapter* activeSystem` pointer tracks the active node.
- When `GContext.ActiveUI_ID` or chapter state changes, the pointer is swapped in one CPU cycle.
- **Result:** Nanosecond-fast scene transitions with zero loading screens.

### 3. Loop Execution Order
1. **Delta Time Cache:** `GetFrameTime()` is pulled and stored in `GContext.GlobalDeltaTime`.
2. **Dynamic Routing:** Pointer swaps occur if Execution Masks dictate a scene change.
3. **Simulation Layer Update:** Physics, Movement, and Collisions run *only* if `EXEC_SIMULATION` is true.
4. **UI Layer Update:** Menus and Overlays process input if `EXEC_UI` is true.
5. **3D Render Hook:** The Realm (Grid/Atmosphere) and Entities are drawn.
6. **2D Overlay Hook:** UI draws over the 3D projection.
