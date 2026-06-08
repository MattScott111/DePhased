# Module: Kinetic Actor Engine
* **Designation**: Environmental Stratum (Physics)
* **Status**: Locked
* **File Hook**: `Game/source/MovementEngine.cpp`
* **AI Context Vector**: GContext.RigidBodyArray, GravityScale, MomentumVector

---

## 1. ABSTRACT
Defines the physical presence and movement logic for all entities (including Young Sir). Focuses on mass, traction, and physical momentum rather than complex 3D animation state machines.

## 2. DATA ARCHITECTURE
* **RigidBody SoA**: A Struct of Arrays containing `Position`, `Velocity`, `Mass`, and `FrictionCoefficient`.

## 3. EXECUTION PIPELINE
1. **Force Accumulation**: Read current input/environmental forces (gravity, wind, drag).
2. **Integration**: Apply velocity to position, scaled by `GContext.GlobalDeltaTime`.
3. **Friction Application**: Apply ground-contact friction based on material resonance.

## 4. INTEGRATION HOOKS
* Informs the `[06_Gear]` resonance registry when actors impact surfaces.

## 5. STRICTURES
* Physics calculations must be independent of the graphics tick rate.
