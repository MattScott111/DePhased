# Game Menu Architecture
**Target:** Pure UI Data Reflection
**Rule:** The UI is a read-only mirror. We strictly adhere to the Zero-Allocation mandate. Dynamic widget objects are banned.

## 1. The Zero-Allocation Global State Machine
The main menu and pause screens do not consist of clickable "Button Objects" initialized in RAM. Navigation is driven by a raw integer state tracker residing in the global context.

* **State Tracker:** `uint8_t g_CurrentMenuState` 
  * `0` = In-Game (Execution Loop Active)
  * `1` = Main Menu (Simulation Paused, Background Hook Active)
  * `2` = Pause/Settings Menu
* **Navigation Index:** `uint8_t g_MenuCursorIndex`
  * `0` = New Game (Triggers Cold Boot Chapter Initialization)
  * `1` = Load Game (Triggers Binary RAM Dump)
  * `2` = Settings (Cosmetic placeholder / Unselectable)

## 2. The Decoupled Render Hook
The Raylib 5.5 and OpenGL rendering pipeline runs completely blind to game logic. It simply reads the `g_MenuCursorIndex` integer every frame.
* Based on the index, Raylib dynamically draws primitive geometric highlight boxes around raw text on the screen. 
* **Execution:** Zero UI widgets are dynamically allocated, updated, or destroyed. The memory footprint remains perfectly static.

## 3. Cold Boot Initialization ("New Game")
Loading a new chapter acts as the bridge between static design and the raw memory grid.
* **The Template Read:** When the user selects "New Game," the engine reads a human-readable config template (e.g., `.ini` or `.csv`) from the `chapters` folder.
* **Data Instantiation:** It parses the initial static parameters (Young Sir's drop coordinates on the "Iron Awakening Workbench", his starting mass, and the default sector states).
* **Grid Injection:** These primitive values are injected directly into Index `0` of the active, pre-allocated memory arrays. Once booted, the game hands off all future saving to the binary memory protocol.
