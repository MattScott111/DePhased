# Threat Specification: Unit 20 - Null-Specter

## 🔍 System Purpose
Manages the environmental material occlusion and alpha visibility states for the advanced specter.

## 🔍 Lore & Aesthetic Integration
The ultimate ghost in the lower networks. A tall, slender silhouette that absorbs all incoming light rays. It is completely invisible to both the player's eye and camera systems, leaving behind nothing but a quiet cold mist as it stalks its targets.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Cylinder Volume Dimensions: $Radius = 0.4m, Height = 2.0m$.
*   **Kinetic Mass Profile**: `float Mass = 60.0f`.
*   **The Vector Occlusion Reveal**: Its structural transparency index is forced to hard `1.0` (Fully Visible) only when its grounding coordinates overlap a wet surface matrix block or an active rain splash vector.

## 🧠 Thought Process & Logic Architecture
The Specter uses a silent approach algorithm, tracking the player from behind along their exact negative forward vector. It halts its movement whenever the player rotates to face its general direction, mimicking a psychological shadow predator.

## ⛓️ Interconnected Dependencies
*   Striking the specter while it is invisible triggers an instant critical breakthrough experience point bonus due to the tactical tracking required.

