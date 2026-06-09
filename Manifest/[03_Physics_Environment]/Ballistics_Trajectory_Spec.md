# Ballistics Trajectory Specification
**Archetype:** Logic Processor (Kinematics)
**Version:** 1.0.0

The Ballistics Engine manages projectile physics, calculating paths that respect both the standard physical stratum and the Phased state.

## 1. Mathematical Logic
- **Integration:** Semi-Implicit Euler integration applied to projectile `Velocity[]` and `Pos[]` blocks.
- **Entropy Influence:** Trajectory variance (sway) is multiplied by `GContext.EntropyIndex`.

## 2. Collision Interaction
- Projectiles poll the target entity's `StateMask`. If the target is `Phased (0x2)`, the projectile logic branches to a "Spectral Hit" routine instead of a standard physical collision solver.
