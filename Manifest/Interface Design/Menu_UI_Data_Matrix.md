# 🖥️ ARCHETYPE: Interface Design
## FILE: Menu_UI_Data_Matrix
**Version:** 1.0.0 | **Compliance:** Strictly Data-Oriented (DOD)

### 1. UI as an Execution Layer
The Menu is not a separate application or isolated scene. It is merely a subset of drawing commands that execute when `GContext.ExecutionMask` possesses the `EXEC_UI` bit.

### 2. Live-Rendered Backgrounds
Because the UI exists in the same loop as the simulation, pausing the game (`ExecutionMask = EXEC_UI`) leaves the 3D Realm and entities frozen in the background. The Menu naturally renders over the live game state, utilizing `GContext.Environment.SkyHorizon` and `AcousticIntensity` to ripple the interface natively.

### 3. State Navigation
Navigating the menu hierarchy does not load new files. It simply updates an integer pointer:
- `GContext.ActiveUI_ID = 0`: Main Menu
- `GContext.ActiveUI_ID = 1`: Settings
- `GContext.ActiveUI_ID = 2`: Terminal / Lore Hub
