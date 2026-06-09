# Lobby & Pre-Game Flow Specification
**Archetype:** Data-Driven Observer
**Version:** v1.0.0

The Lobby acts as a bridge between the Main Menu and the Simulation Layer. It utilizes a state-driven approach to configure the protagonist.

## Component Configuration
- **Profile Management:** Input fields mapped to `GContext.SaveData.PlayerProfile.name`.
- **Race/Type Selection:** Integer-based state machine (RaceID: 0-2, TypeID: 0-4).
- **Entropy Index (Difficulty):** Configurable slider (1–10) directly influencing `GContext.Environment` multipliers.

## Interaction Loop
1. **Selection:** User hovers over species/type. `LobbyEngine` calculates `previewSpeed` and `previewStability` based on the chosen Blueprint.
2. **Confirmation:** If `isCustomized` is true, the `Back` button triggers a confirmation modal to protect progress.
3. **Handover:** Upon 'Start Game', the `LobbyEngine` flips `GContext.ExecutionMask` from `EXEC_UI` to `EXEC_SIMULATION`, immediately triggering the `Chapter_01` update loop.
