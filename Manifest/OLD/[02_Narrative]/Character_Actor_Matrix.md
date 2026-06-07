# Low-Level Specification: Character Actor Memory Matrix & Input Decoupling

## 🔍 System Purpose
Defines the non-physical component attributes, cylinder collision geometries, and cognitive memory bitfields for the player protagonist.

## ⚙️ Mechanical Specification
*   **Volumetric Capsule Constraints**: The character's physical presence is defined as a uniform mathematical primitive cylinder matching $Height = 1.8m$ and $Radius = 0.3m$.
*   **Cognitive Memory Bitfield**: Historical timeline logs and unlocked identity strings are compressed into a single `uint32_t cognitiveMemoryMask` switch matrix.
*   **The Proximity Intersect Hook**: Rotational inputs ($Pitch / Yaw$) are evaluated in raw radians inside the component block, driving camera focal offsets seamlessly via the shared context layer.

## 🧠 Thought Process & Logic Architecture
Traditional character programming wraps the character inside heavy, bloated objects containing animation data, visual meshes, and script listeners. This creates rigid dependencies that slow down processing. By extracting the character's core states into a clean, primitive component block, movement vectors can be computed directly in registers, keeping execution speeds lightning fast.

## ⛓️ Interconnected Dependencies
*   Supplies the raw directional input and look vectors read by **[03_Physics_Environment]/Dynamic_Camera_Observer.md**.
*   Triggers memory-state evaluation switches handled in **[05_Progression_Rewards]/Achievement_Trophy_Matrix.md**.
