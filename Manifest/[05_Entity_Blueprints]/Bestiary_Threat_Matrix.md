# Module: Bestiary Threat Matrix
* **Designation**: Entity Form (Threat Registry)
* **Status**: Locked
* **File Hook**: `Game/source/CharacterActor.cpp`
* **AI Context Vector**: ThreatRegistry[MAX_THREATS], AwarenessLevel, AggressionMask

---

## 1. ABSTRACT & CONTEXT
A centralized registry of all non-player entities, ranging from basic *Spark Hounds* to high-level *Digital Phantoms*.
* **Lore Integration**: Threats in *De-Phased* are defined by their sensory interaction with the environment. An *Echo Phantom* reacts to acoustic signatures; a *Breaker Drone* reacts to pressure waves. They do not have "AI Scripts"; they have "Response Vectors" triggered by environmental data.

## 2. LOGIC ARCHITECTURE
Entities utilize an `AggressionMask` bit-field to determine how they filter sensory data. This allows for $O(1)$ response time. Instead of "checking for players," the engine compares the entity’s `AwarenessLevel` against the global `Spatial_Event_Broadcaster` queue.

## 3. DATA STRUCTURE
* **Threat SoA**: `struct Threat { uint32_t unitID, uint32_t awarenessLevel, uint64_t aggressionMask }`
* **Registry**: `ThreatRegistry[MAX_THREATS]` (Static pre-allocated array).

## 4. EXECUTION PIPELINE
1. **Event Detection**: Entity monitors the `Spatial_Event_Broadcaster` for specific wave-signatures (Acoustic/Pressure/Kinetic).
2. **Frequency Match**: If signature matches `AggressionMask`, entity changes state to `Active`.
3. **Behavioral Update**: Entity reads `[03_Physics_Environment]` to navigate toward the source-point of the signature.

## 5. RELATIONAL DEPENDENCIES
* **Physics**: Reads wave data (Acoustics/Pressure) from `[03_Physics_Environment]`.
* **Narrative**: Linked to `Boss_Anomaly_Registry.md` for elite unit behavior-state triggers.

## 6. STRICTURES
* Threat entities must not store complex behavioral state machines; they must remain reactive to environmental registry changes.
* Maximum entity count per sector is capped at `MAX_THREATS` to preserve the zero-allocation pipeline.
