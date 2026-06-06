# Module: Menu State Observer
* **Designation**: Data-Driven Observer (Game State)
* **Status**: Locked
* **File Hook**: `Game/chapters/MenuChapter.cpp`
* **AI Context Vector**: MenuStateIndex, SelectionPointer, ActiveChapterPointer

---

## 1. ABSTRACT
Manages the pausing, chapter selection, and meta-game state transitions. It operates as a high-level controller that modifies the `ActiveChapterPointer` in the state machine.

## 2. DATA ARCHITECTURE
* **Selection Registry**: Maintains `selectedOption` index.
* **State Control**: Holds the pointer to the current game state (`MenuChapter` vs. `GameChapter`).

## 3. EXECUTION PIPELINE
1. **Input Polling**: Queries the `InputEngine` for menu navigation commands.
2. **Index Update**: Adjusts the `SelectionPointer` index.
3. **State Transition**: On "Select", triggers the pointer swap to move from the menu into the `Chapter_01` play-state.

## 4. INTEGRATION HOOKS
* Observes the `[03_Physics_Environment]` for background "Live Data" (e.g., rendering current sector's atmospheric state).

## 5. STRICTURES
* This menu must not perform heavy asset loading during the render loop.
