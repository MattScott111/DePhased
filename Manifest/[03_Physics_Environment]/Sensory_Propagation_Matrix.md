# Module: Sensory Propagation Matrix
* **Designation**: Environmental Stratum (Wave Physics)
* **Status**: Locked
* **File Hook**: `Game/source/BallisticsEngine.cpp`
* **AI Context Vector**: WaveEmitterRegistry, MaterialZIndex, AcousticOutput

---

## 1. ABSTRACT
This module implements **Source-Point Propagation**. Wave events (Acoustic, Pressure, Kinetic) emerge from the source (muzzle, impact point) and propagate through the environment. The weapon acts as the primary wave emitter, creating phenomena that exist before collision resolution.

## 2. DATA ARCHITECTURE
* **Emission Source**: `WaveEmitter` contains `OriginPoint`, `Amplitude`, and `WaveType`.
* **Periodic Registry**: Materials mapped via Atomic $Z$-index (e.g., Lead=High absorption, Carbon=High resonance).

## 3. EXECUTION PIPELINE
1. **Source Emission**: Weapon/Actor fires an event; `WaveEmitter` records the origin point.
2. **Propagation**: Waves ripple outward as data packets through the environment.
3. **Material Interaction**: On contact with a material surface, the `AcousticSignature` triggers reflection (hard surfaces) or absorption (soft surfaces).

## 4. INTEGRATION HOOKS
* Alerts the `Passive_Awareness_Registry`. Entities detect specific wave-frequencies (e.g., electronic hum vs. mechanical thud).

## 5. STRICTURES
* Source-point generation must be atomic to ensure signal integrity across the environment.
