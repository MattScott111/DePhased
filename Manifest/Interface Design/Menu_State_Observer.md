# Module: Menu State Observer
* **Designation**: Data-Driven Observer (Game State)
* **Status**: Locked
* **File Hook**: `Game/chapters/MenuChapter.cpp`
* **AI Context Vector**: MenuStateIndex, SelectionPointer, ActiveChapterPointer

---

## 1. ABSTRACT
Manages high-level state transitions. Acts as a controller to modify the `ActiveChapterPointer` in the state machine based on user interaction.

## 2. DATA ARCHITECTURE
* **Selection Registry**: Maintains `selectedOption` index.
* **State Control**: Holds the pointer to current game state (`MenuChapter` vs `GameChapter`).

## 3. EXECUTION PIPELINE
1. **Input Polling**: Queries `InputEngine` for menu navigation.
2. **Index Update**: Adjusts `SelectionPointer`.
3. **State Transition**: On "Select", triggers pointer swap to transition to the chosen Chapter.

## 4. INTEGRATION HOOKS
* Polls `[03_Physics_Environment]` for background "Live Data" (atmospheric rendering).

## 5. STRICTURES
* No asset loading permitted within the render loop.
