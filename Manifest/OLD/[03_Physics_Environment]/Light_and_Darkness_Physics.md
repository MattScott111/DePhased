# Light & Darkness Physics Matrix
**Target:** Zero-Allocation Photonics & "Felt" Illumination
**Rule:** Light and Darkness are not just visual shaders; they are physical, active data arrays that influence kinetic and survival matrices.

## 1. The Photonics Array Structure
Lighting is tracked natively in the raw data grid alongside physical entities.
* `float PositionX/Y/Z[MAX_ACTIVE_LIGHTS]`
* `float LightIntensity[MAX_ACTIVE_LIGHTS]` (Positive float = Illumination, Negative float = Active Darkness)
* `float Radius[MAX_ACTIVE_LIGHTS]`
* `uint32_t ColorHex[MAX_ACTIVE_LIGHTS]`

## 2. "Felt" Light Physics (The Overlap Yield)
The engine executes a squared-distance check between entities and the `Radius` array. If an entity overlaps, the data directly alters their state.
* **Revitalization (Young Sir):** Standing in a warm light radius injects the `LightIntensity` float directly into his `Survival_Fatigue_Matrix`, accelerating energy recovery.
* **Photonic Decay (Vampire Types):** Entities with a light-sensitive `EntityStateMask` (e.g., Static Wraiths) have the `LightIntensity` float instantly inverted into a heavy Damage-Over-Time (DoT) penalty.

## 3. Active Darkness (The Inverse Matrix)
Darkness is not merely an absence of light; it can be an active, generated field (e.g., a "Null Specter" projecting a blackout zone).
* If `LightIntensity` is a negative float, it acts as a Darkness Emitter.
* **The Yield:** Darkness overlaps drain Young Sir's sanity/fatigue matrices while granting massive velocity and traction multipliers to entities flagged with a nocturnal `EntityStateMask`.
