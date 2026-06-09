# Character Creation Lobby UI Specification
**Archetype:** Data-Driven Observer
**Version:** v1.1.0

The Lobby acts as a live engine state (`MenuChapter`) for protagonist instantiation, utilizing 3D previewing and direct registry injection.

## UI Components
- **Input Field:** `PlayerProfile.name` updated via keyboard polling.
- **Preview Widget:** Renders a 3D model scaled by `PreviewBlueprint` data.
- **Entropy Slider:** Configures difficulty (1-10); directly modulates global environmental scalars in the registry.

## Navigation Flow
- **Back Button:** If `PlayerProfile.isCustomized` is `true`, a `ConfirmDialog` overlay is invoked.
- **Handover:** Upon 'Start Game', the Lobby pushes `MSG_NEW_GAME` through the Messaging Matrix to trigger the Simulation state.
