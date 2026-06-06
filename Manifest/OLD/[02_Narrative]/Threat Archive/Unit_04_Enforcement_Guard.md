# Threat Specification: Unit 04 - Enforcement Guard

## 🔍 System Purpose
Establishes the physical attributes and close-quarters melee combat functions for the standard human patrol actor.

## 🌀 Lore & Aesthetic Integration
Pax Aegis security guards wearing heavy, insulated rubber-composite riot gear and opaque visors. They wield a thick, heavy carbon-fiber shock baton that crackles with yellow electricity, designed to physically batter and suppress lower-sector outcasts.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Cylinder Volume Dimensions: $Radius = 0.4m, Height = 1.8m$.
*   **Kinetic Mass Profile**: `float Mass = 95.0f` (High physical inertia).
*   **Baton Strike**: A successful swing triggers an immediate $1.5$-meter linear knockback vector against Young Sir, accompanied by a 1-second stamina regeneration freeze.

## 🧠 Thought Process & Logic Architecture
The guard utilizes basic pathfinding grids to close distances. If the player steps into an elevated position, the guard's logic uses the Sphere-Cast matrix to seek the closest ramp or stairs entity rather than attempting to jump.

## ⛓️ Interconnected Dependencies
*   Movement speed is directly reduced by heavy wind vectors tracked in the atmospheric engine.

