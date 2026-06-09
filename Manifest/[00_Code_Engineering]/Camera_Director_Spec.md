# Camera Director Specification
**Archetype:** Logic Processor (Cinematics)
**Version:** 1.2.0 | **Compliance:** Strictly Data-Oriented (DOD)

The Camera system is a stateless entity-tracking system. It is not tethered to the player; it is an observer reading directly from the `GContext` registry.

## 1. Registry Parameters (The Data)
All camera state is stored within the global `GContext`, allowing any system (Input, AI, Chapter) to shift the camera focus without direct dependencies.

- `CameraTargetID (uint32_t)`: Index in the Master Registry. (0 = Player, 15 = Boss, 99 = Terminal).
- `CameraZoom (float)`: Multiplier for FOV (0.0 = Wide, 1.0 = Default, 2.0 = Zoomed).
- `CameraOffset (Vector2)`: Cinematic panning (x, z) relative to target.
- `CameraLerpSpeed (float)`: Integration constant (1.0 = Snap, 0.05 = Heavy/Glide).

## 2. Cinematic Flow (The Logic)
The camera utilizes `EXEC_CINEMATIC` bitmasking to handle transitions seamlessly.

### The Handover Protocol
1. **Trigger:** An event modifies `GContext.CameraTargetID` and lowers `CameraLerpSpeed` (e.g., to 0.02f for a sweeping cinematic feel).
2. **Execution:** The camera reads `GContext` once per frame in the post-physics integration step of `main.cpp`.
3. **Interpolation:** The camera performs a `Vector3Lerp` from the previous frame's `cam.position` to the new `DesiredTargetPos`.

## 3. Performance & DOD Optimization
- **Statelessness:** The `CameraEngine` does not own any private variables. It reads from and writes to the global `GContext`.
- **Deterministic Drift:** By using `GContext.GlobalDeltaTime` in the interpolation math, the camera movement is frame-rate independent, ensuring consistency across varying hardware performance.

## 4. Implementation Rules
- NEVER create a `Camera` object in local scope. 
- ALWAYS modify `GContext` registry fields.
- The `RenderEngine` polls these registry values once per frame to update the `raylib` Camera3D structure.
