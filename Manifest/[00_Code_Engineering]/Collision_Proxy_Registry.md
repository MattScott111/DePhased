# Collision Proxy Registry

## Meta-Data
- **Archetype:** System_Abstraction
- **Classification:** Physics_Subsystem
- **Status:** Locked
- **Focus:** Geometry-Agnostic Movement

---

## 1. Proxy Concept
The `Kinetic_Actor_Engine` does not act on a "Character." It acts on a `PhysicsProxy`. 

## 2. Proxy Types
* `PROXY_CYLINDER` (Current: Weight, Traction, Momentum)
* `PROXY_BOX` (Future: Stability, Cornering)
* `PROXY_MESH` (Future: Complex Interaction)

## 3. Data Flow
1. `Kinetic_Actor_Engine` polls `GContext.ActiveProxyType`.
2. Engine reads `Proxy_Dimensions` from the struct.
3. Logic performs collision resolution against the `Stratum_Memory_Matrix`.
*Movement logic remains immutable regardless of the Proxy shape.*
