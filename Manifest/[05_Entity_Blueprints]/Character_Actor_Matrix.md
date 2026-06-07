# Module: Character Actor Matrix
* **Designation**: Entity Form (Characters & Objects)
* **Status**: Locked
* **File Hook**: `Game/source/CharacterActor.cpp`
* **AI Context Vector**: GContext.ActorRegistry, InteractionMask, AllegianceID, MomentumVector

---

## 1. ABSTRACT & CONTEXT
The centralized definition for all character entities in the engine. It defines the physical presence, collision behavior, and relational status of all actors in the world.
* **Lore Integration**: Young Sir, as a geometric cylinder, prioritizes physical presence and weight over visual animation. Other actors (like the Spark Hound or Enforcement Guard) are defined by their ability to manipulate the environment’s data flow.

## 2. LOGIC ARCHITECTURE
Entities do not own their state. They are essentially indices in a Struct-of-Arrays (SoA) registry. All "behavior" is simply the character reading from the environment's `InteractionMask` and reacting accordingly, keeping the simulation decentralized and DOD-compliant.

## 3. DATA STRUCTURE
* **Actor SoA**: `struct Actor { Vector3 pos, Vector3 velocity, uint64_t interactionMask, uint32_t allegianceID }`
* **InteractionMask**: A bit-packed field defining whether an entity is 'Phased', 'Hostile', or 'Interactive'.

## 4. EXECUTION PIPELINE
1. **Update Phase**: Each entity reads its `MovementVector` from the physics array.
2. **Collision Resolution**: The `EnvironmentEngine` compares the actor's `InteractionMask` against environmental boundaries.
3. **Allegiance Check**: Hostility is determined by comparing `AllegianceID` against the faction relation matrix.

## 5. RELATIONAL DEPENDENCIES
* **Factions**: Actor allegiance is dynamically cross-referenced with `Faction_Relational_Matrix.md` for AI hostility checks.
* **Physics**: Actor movement is restricted by the current stratum's `Atmospheric_Conditions_Engine`.

## 6. STRICTURES
* Entities must not contain stateful logic controllers; they must act upon data in the `GContext` registry.
* Interaction masks must be bit-packed to fit within a single 64-bit register for rapid collision filtering.
