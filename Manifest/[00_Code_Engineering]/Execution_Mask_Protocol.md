# ⚙️ ARCHETYPE: Logic Processor
## FILE: Execution_Mask_Protocol
**Version:** 1.0.0 | **Compliance:** Strictly Data-Oriented (DOD)

### 1. The Problem with State Enums
Traditional engines use flat enums (e.g., `STATE_PLAYING`, `STATE_PAUSED`). This creates rigid boundaries where pausing the game requires writing exception code to keep drawing the background while stopping the physics.

### 2. The Execution Layer Solution
De-Phased uses a 32-bit `ExecutionMask` to grant real-time permission to engine layers. Multiple layers can run simultaneously.

**The Bitmask Designations:**
- `EXEC_NONE (0)`: System halt.
- `EXEC_UI (1 << 0)`: Allows Menu, Terminal, and HUD updates.
- `EXEC_SIMULATION (1 << 1)`: Allows Player Input, Movement Engine, and Physics.
- `EXEC_CINEMATIC (1 << 2)`: Hijacks the camera and disables player input for scripted events.
- `EXEC_DEV_TOOLS (1 << 3)`: Renders hitboxes, performance telemetry, and node graphs.

### 3. Elegant Overlapping
To pause the game, the UI system simply drops the simulation bit:
`GContext.ExecutionMask = EXEC_UI;`
Because the simulation bit is gone, physics stops updating, but the rendering loop still sees the entities and draws them frozen in the background while the UI draws on top.
