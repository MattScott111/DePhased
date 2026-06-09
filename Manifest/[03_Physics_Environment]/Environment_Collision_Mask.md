# Environment Collision Mask Specification
**Archetype:** Environmental Stratum
**Version:** v1.0.0

The collision system utilizes bitmask branching to support "Dephased" traversal, allowing the player to pass through physical objects when in the spectral state.

## Collision Masking
- **Solid Mask (0x0):** Standard collision; triggers physical response.
- **Phased Mask (0x1):** Spectral transparency; `EnvironmentEngine` disables collision response for entities with the Phased bit set.
- **Trigger Zones:** Sensors (e.g., portals) exist on a separate overlay mask, allowing interaction regardless of phasal state.

## Logic Implementation
- `EnvironmentEngine` iterates over `GContext.SaveData.StateMask`. 
- If `StateMask & 0x4` (Phased) is true, the engine skips the collision solver for that entity in the `Phased` environmental stratum.
