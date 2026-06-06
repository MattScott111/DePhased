# Module: Boss Anomaly Registry
* **Designation**: Entity Form (Boss Data)
* **Status**: Locked
* **File Hook**: `Game/source/CharacterActor.cpp`
* **AI Context Vector**: AnomalyData, RegistryIndex, AggressionMask

---

## 1. ABSTRACT & CONTEXT
High-level "Boss" entities that act as structural disruptors in the environment. These are not scripted encounters; they are reactive agents with high-density `AggressionMasks`.
* **Lore Integration**: These anomalies (e.g., *Iron Warden*, *Flux Node 09*) are essentially physical manifestations of engine errors—glitches that have acquired mass and agency.

## 2. LOGIC ARCHITECTURE
Bosses do not utilize complex behavior trees. They utilize an expanded `InteractionMask` that allows them to "read" the physics environment arrays at a macro-scale, allowing them to manipulate the environment (e.g., *Iron Warden* locking sectors).

## 3. DATA STRUCTURE
* **AnomalyData**: Extended SoA including `ShieldFrequency`, `PhaseState`, and `AreaOfEffectRadius`.

## 4. EXECUTION PIPELINE
1. **Sector Locking**: Upon anomaly detection, the `Stratum_Streaming_Matrix` locks the sector, preventing the player from exiting until the anomaly's `PhaseState` is nullified.
2. **Reactive Vectoring**: Boss reads wave-propagation data to predict player movement.

## 5. RELATIONAL DEPENDENCIES
* **Physics**: Directly commands sector memory locks.
* **Gear**: Anomalies have specific `SecurityOverride` vulnerabilities.

## 6. STRICTURES
* Boss entities must maintain reactivity; they cannot override the fundamental physics/DOD rules.
