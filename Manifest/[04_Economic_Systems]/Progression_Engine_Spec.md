# Progression Engine Specification
**Archetype:** Resource Matrix
**Version:** v1.0.0

Governs the evolution of the player character, including XP thresholds and achievement unlocking logic.

## Progression Matrix
- **CurrentXP:** `float[MAX_ENTITIES]` tracked per-entity.
- **Thresholds:** Progression is checked every `EvaluateAttributeRewards()` call.
- **Milestone Bitmask:** - Bit 0x10: 'First Step' Achievement.
  - Bit 0x20: 'Market Tycoon' Achievement.
  - Bits are persisted via `StateMask` and binary-dumped into the `PersistentState` registry.

## Logic Flow
1. Engines push state to `CurrentXP`.
2. `AchievementEngine` polling compares `CurrentXP` against the static threshold constants.
3. If criteria met, `RegisterMilestone` updates `StateMask` and `UnlockedLore` flags.
