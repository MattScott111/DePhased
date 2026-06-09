# Entropy Index (Difficulty) Scaling
**Archetype:** Environmental Stratum
**Version:** v1.0.0

The Entropy Index (1–10) provides a global difficulty scalar. It is not an arbitrary modifier, but a frequency-based disruption of the game's physical strata.

## Scaling Effects
- **Kinetic Drift:** `MovementEngine` friction scalar reduced by `(1.0 - (EntropyIndex * 0.05))`.
- **Phased Cost:** `EnvironmentEngine` increases Deuterium burn rate by `EntropyIndex * 0.1` per frame.
- **Ballistic Sway:** `BallisticsEngine` multiplier for `ApplyWindAndSway` increased linearly with `EntropyIndex`.

## Implementation
Engines poll `GContext.SaveData.PlayerProfile.entropyIndex` at the start of their `Update()` cycle. No hardcoded logic—all physics constants are calculated as `BaseValue * EntropyMultiplier`.
