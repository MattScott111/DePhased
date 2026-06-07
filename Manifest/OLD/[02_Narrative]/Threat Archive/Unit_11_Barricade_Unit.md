# Threat Specification: Unit 11 - Barricade Unit

## 🔍 System Purpose
Defines the deployable shield properties and blocking logic for the stationary defense frame.

## 🌀 Lore & Aesthetic Integration
A heavy, low-slung mechanical bulwark that drops stabilizer spikes directly into the asphalt. Once locked, it projects a wide, semi-translucent orange static mesh wall that completely deflects incoming energy and kinetic vectors.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Base Hull Box: $Width = 2.0m, Height = 1.2m$. Shield Wall Plane: $Width = 4.0m, Height = 2.5m$.
*   **Kinetic Mass Profile**: `float Mass = 500.0f` (Hard anchored state).
*   **The Energy Deflector**: Incoming kinetic project matrices intersecting the orange shield plane have their velocity vectors instantly mirrored or nullified.

## 🧠 Thought Process & Logic Architecture
The unit is entirely stationary once deployed. It reads the position vector of nearby squad mates, dropping its shield wall to face the player and block line-of-sight paths, forcing the player to seek flank paths.

## ⛓️ Interconnected Dependencies
*   The shield wall plane can be completely bypassed by utilizing high-zoom vertical camera look vectors.

