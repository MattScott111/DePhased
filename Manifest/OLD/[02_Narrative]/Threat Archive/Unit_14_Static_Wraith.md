# Threat Specification: Unit 14 - Static Wraith

## 🔍 System Purpose
Manages the phase-swapping properties and tracking matrices for the low-tier network anomaly.

## 🌀 Lore & Aesthetic Integration
A flickering, humanoid silhouette woven entirely from crackling blue radio static and broken broadcast frequencies. It moves across the floor without touching it, its shape constantly de-phasing and filling the air with old audio distortion.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Capsule Volume Dimensions: $Radius = 0.4m, Height = 1.7m$.
*   **Kinetic Mass Profile**: `float Mass = 0.0f` (Ethereal state; completely unaffected by physical mass displacement forces).
*   **The Glitch Step**: Every 3 seconds, the unit checks its current vector, instantly teleporting $2.0$ meters sideways to clean its active tracking history.

## 🧠 Thought Process & Logic Architecture
The Wraith avoids standard physics integration. It updates its position matrices using a clean coordinate offset algorithm rather than applying forces, allowing it to move smoothly through physical obstacles like walls or crates.

## ⛓️ Interconnected Dependencies
*   Its visibility index drops to zero if the regional climate engine enters a clear sunlight state.

