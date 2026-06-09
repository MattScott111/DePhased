# Module: Boss Anomaly Registry
* **Designation**: Entity Form (Boss Data)
* **Status**: Locked
* **File Hook**: `Game/source/BossEngine.cpp`
* **AI Context Vector**: AnomalyData, RegistryIndex, AggressionMask

---

## 1. ABSTRACT & CONTEXT
High-level "Boss" entities that act as structural disruptors. These are not scripted encounters; they are reactive agents with high-density `AggressionMasks` polling the registry directly.
* **Lore Integration**: Anomalies (e.g., *Iron Warden*, *Flux Node 09*) are physical manifestations of engine errors—glitches that have acquired mass and agency.

## 2. LOGIC ARCHITECTURE
Bosses utilize an expanded `InteractionMask` that allows them to "read" the physics environment arrays at a macro-scale, allowing them to manipulate the environment (e.g., *Iron Warden* locking sectors by modifying `GContext.ExecutionMask`).

## 3. DATA STRUCTURE
* **AnomalyData**: Extended SoA including `ShieldFrequency`, `PhaseState`, and `AreaOfEffectRadius`.

## 4. EXECUTION PIPELINE
1. **Sector Locking**: Upon anomaly detection, the `Stratum_Streamer` locks the sector, preventing the player from exiting until the anomaly's `PhaseState` is nullified.
2. **Reactive Vectoring**: Boss reads wave-propagation data to predict player movement.

## 5. RELATIONAL DEPENDENCIES
* **Physics**: Directly commands sector memory locks.
* **Gear**: Anomalies have specific `SecurityOverride` vulnerabilities.

## 6. STRICTURES
* Strictly ZERO runtime memory allocation.
* Boss entities must maintain reactivity; they cannot override the fundamental physics/DOD rules.
