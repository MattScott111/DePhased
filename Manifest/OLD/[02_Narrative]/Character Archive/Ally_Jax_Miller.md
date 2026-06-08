# Character Dossier: Jax "The Ground" Miller

## 🔍 System Purpose
Outlines the combat assist logic, mass metrics, and structural barrier protection attributes for the workshop's defensive muscle.

## 🌀 Lore & Aesthetic Integration
A towering, soft-spoken mountain of a man who rarely speaks unless necessary. He wears a massive, dented industrial exoskeleton originally designed for lifting heavy-water cell arrays. He serves as the physical anchor for the underground workshop, standing as an unyielding wall between corporate drones and his friends.

## ⚙️ Mechanical Specification
*   **Unique Identifier**: `NPC_JAX_03`.
*   **Kinetic Mass Profile**: `float Mass = 350.0f` (Due to hydraulic framework weights).
*   **The Grounding Spike Ability**: During sandbox wave-defense events, Jax drives a massive copper grounding rod into the asphalt. This creates a spherical field vector with a $5.0$-meter radius that instantly locks the `isGrounded` property of any enemy unit stepping inside to a permanent `true`, completely halting their vertical or horizontal movement acceleration curves.

## 🧠 Thought Process & Logic Architecture
Jax’s AI routine operates as a high-priority structural defense barrier. He evaluates the crowd density vector within a close-quarters matrix cell, deploying his grounding spikes only when more than three standard enforcement units intersect his defensive quadrant.

