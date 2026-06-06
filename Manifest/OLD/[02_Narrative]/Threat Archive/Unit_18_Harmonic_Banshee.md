# Threat Specification: Unit 18 - Harmonic Banshee

## 🔍 System Purpose
Defines the audio scream volume bounds and stamina regeneration lock conditions for the sound anomaly.

## 🌀 Lore & Aesthetic Integration
A floating, weeping specter whose torso transitions into a chaotic mesh of vibrating speaker membranes and audio wires. It lets out a piercing, high-frequency acoustic scream that shatters glass tubes and causes Young Sir's ears to ring painfully.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Cylinder Volume Dimensions: $Radius = 0.5m, Height = 2.0m$.
*   **Kinetic Mass Profile**: `float Mass = 5.0f`.
*   **Stamina Suppressor Field**: While the banshee is executing its scream animation, Young Sir’s stamina regeneration coefficient is forced to hard `0.0`, blocking sprint inputs completely.

## 🧠 Thought Process & Logic Architecture
The Banshee uses a basic line-of-sight raycast. When it detects an unobstructed line to the player within a $12$-meter range, it stops all forward movement, roots its coordinate space, and channels its scream wave for a fixed 3-second cycle.

## ⛓️ Interconnected Dependencies
*   Its audio waves physically push away lightweight objects like dynamic crates, applying a minor outward velocity vector.

