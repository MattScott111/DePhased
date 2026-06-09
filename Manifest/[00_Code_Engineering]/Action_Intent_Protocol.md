# ⚙️ ARCHETYPE: Logic Processor
## FILE: Action_Intent_Protocol
**Version:** 1.1.0 | **Compliance:** Strictly Data-Oriented (DOD)

### 1. Decoupling Input from Actors
The Input Engine does not directly move the player. Instead, it reads hardware states (WASD, Space) and compiles them into an **Action Intent Bitmask** (`Action` enum). 

### 2. The Action Bitmask
Input translates into binary flags:
- `MOVE_FORWARD  = 1 << 0`
- `PHASE_TOGGLE  = 1 << 4`

### 3. Execution Dependency
The Input Engine strictly checks `GContext.ExecutionMask`. 
- If `EXEC_CINEMATIC` is active, player inputs are ignored.
- If `EXEC_SIMULATION` is active, the Movement Engine reads the Intent Bitmask and applies velocity to `Velocity[0]`. This prevents the player from moving during cutscenes or menu interactions without requiring boolean lockouts.
