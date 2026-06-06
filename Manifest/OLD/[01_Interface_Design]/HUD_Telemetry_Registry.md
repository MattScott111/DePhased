# HUD Telemetry Registry

## Concept: The "Developer's Eyes" HUD
In a Data-Oriented (DOD) environment, the internal memory state *is* the game. The `HUD_Telemetry_Registry` acts as a high-performance visual debugging device.

## Design Specification
- **Mechanism**: Performed via direct, read-only memory queries on the `GContext` struct.
- **Visualization**: Raw bytes (such as `AcousticIntensity`, `AlertnessLevel`, or `StateMask`) are interpreted and rendered as real-time heatmaps or diagnostic wireframe overlays.
- **Functionality**: Provides a telemetry view of the engine's "thought process," turning abstract data into immediate, actionable visual feedback without impacting the primary physics loop.
