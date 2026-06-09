# Race & Archetype Matrix
**Archetype:** Entity Form
**Version:** v1.1.0

Defines the biological and tactical capabilities of the protagonist.

## Matrix Permutation
| Race | Type | Ability Name | Description |
| :--- | :--- | :--- | :--- |
| **Terran** | Titan | Adrenaline Surge | Rage-colored visual distortion, time dilation, and massive temporary stat boost. |
| **Veylarian**| Auric | Aura-EMP | EMPs local environment; digital enemies in data plane converted to friendly/neutral 'Devas'. |
| **Chitin-Kreen**| Stealth | Bio-Binding Spit | Projects a 'Venom' substance that binds, consumes, degrades, and absorbs infected enemies. |

## Data Implementation
- **Registry Mapping:** Species data is stored in `GContext.Blueprints` and resolved at instantiation.
- **Ability Logic:**
  - **Adrenaline Surge:** Triggers `CameraZoom` change and alters `PostProcessShader` (magenta/rage spectrum) while slowing `GContext.GlobalDeltaTime`.
  - **Aura-EMP:** Iterates through `GContext` registry indices to flip enemy `InteractionMask` bits.
  - **Bio-Binding Spit:** Projectile-path integration that applies an "InfectionStatus" flag, triggering a decay loop in the `StatusEngine`.
- **Masking:** Logic gated by `ActiveAbilityMask` bitfields in the `EntityBlueprint` struct.
