# Camera Director Logic

## Meta-Data
- **Archetype:** Logic_Processor
- **Classification:** Camera_System
- **Status:** Locked
- **Focus:** Spring-Damper Interpolation & Scripted Control

---

## 1. Modes
* **MODE_PLAYER_FOLLOW:** Default. Uses `DampedSpring` to interpolate to the `TargetTransform`.
* **MODE_SCRIPTED:** Direct camera control via `Camera_Path_Node` array.

## 2. Camera Weight Mechanics
* **Look-Ahead Vector:** The camera `TargetTransform` is offset by `(Velocity * LookAheadFactor)`. 
* **Seamless Zoom:** `MouseWheel` input modifies the `ZoomLevel` (0.0 to 2.0). The `CameraEngine` performs a `Slerp` across the Three-State Lens (Tight, Third-Person, Eagle-Eye).
