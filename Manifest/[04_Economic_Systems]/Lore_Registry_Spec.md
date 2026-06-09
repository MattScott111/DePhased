# Lore Registry Specification
**Archetype:** Resource Matrix (Narrative Data)
**Version:** 1.0.0

The Lore Registry tracks the narrative discovery of the player. It is part of the persistent binary dump.

## 1. Storage
- **UnlockedLore[256]:** A contiguous array of booleans.
- **Access:** System `AchievementEngine` sets `bool` flags based on `MilestoneID`.

## 2. Usage
- UI elements (via `HUD_Telemetry`) read these flags to populate codex entries.
- No string data is stored in the registry; only index IDs that map to external localization tables.
