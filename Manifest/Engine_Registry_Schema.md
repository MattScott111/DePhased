# Engine Registry Schema (GContext)
**Archetype:** Logic Processor / Global State
**Version:** v1.0.0

The `GContext` is the absolute master registry for `De-Phased`. All system engines (Movement, Ballistics, Environment) act as stateless operators that pull from and push to these contiguous memory blocks.

## Registry Memory Layout
- **ExecutionMask (uint32_t):** Bitfield controlling system activity (UI, Simulation, Cinematic).
- **SaveData (PersistentState):** The struct marked for binary serialization.
  - `Pos[MAX_ENTITIES]`: Contiguous Vector3 positions.
  - `StateMask[MAX_ENTITIES]`: Bitfield for phasal state and milestone progression.
  - `Achievements[128]`: Binary flags for milestone tracking.
- **Transients (Volatile):** - `MovementIntent[MAX_ENTITIES]`: Per-frame input vectors.
  - `Velocity[MAX_ENTITIES]`: Per-frame momentum.
  - `GlobalDeltaTime`: Cached frame timer for DOD synchronization.

## Access Protocol
Systems MUST NOT pass registry pointers as parameters. All systems access the globally scoped `DePhased::GContext` instance.
