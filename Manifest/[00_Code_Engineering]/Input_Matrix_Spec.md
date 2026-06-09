# Input Matrix Specification
**Archetype:** Logic Processor (Input Abstraction)
**Version:** v1.0.0

The Input Matrix abstracts raw hardware events into persistent "Intent Vectors" that the Movement and Action engines can consume.

## Intent Registry
- **MovementIntent[MAX_ENTITIES]:** Vector3 representing the direction and magnitude of the desired input.
- **ActionTrigger[MAX_ENTITIES]:** A bitfield of active commands (e.g., Interact, Phase, Ability).

## Processing Flow
1. **Polling:** `InputEngine` scans hardware (Keyboard/Mouse) at the start of the frame.
2. **Normalizing:** Raw key presses are translated into `MovementIntent` vectors (clamped to 1.0 length).
3. **Consuming:** Systems (e.g., `MovementEngine`) read `MovementIntent`, apply transformations, and clear the vector to prevent ghost movement in the next frame.
