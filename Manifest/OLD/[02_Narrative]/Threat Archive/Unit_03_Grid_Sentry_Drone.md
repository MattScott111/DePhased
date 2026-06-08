# Threat Specification: Unit 03 - Grid-Sentry Drone

## 🔍 System Purpose
Manages the combat attributes and basic projectile trajectory spawning for the low-tier floating combat drone.

## 🌀 Lore & Aesthetic Integration
A compact, boxy drone floating via integrated magnetic-levitation ring-drives. Its chassis is painted in official Pax Aegis matte-grey, housing a low-caliber automatic rivet barrel that shoots sparking copper projectiles.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Box Dimensions: $Width = 0.6m, Height = 0.4m, Length = 0.6m$.
*   **Kinetic Mass Profile**: `float Mass = 25.0f`.
*   **Rivet Projectile Vector**: Spawns a physical primitive projectile with a linear velocity vector $\vec{v} = \text{TargetDirection} \times 12.0\text{ m/s}$.

## 🧠 Thought Process & Logic Architecture
To save cache lines, the drone does not calculate lead-targeting math. It points straight at Young Sir's active coordinates and fires at a fixed intervals (once every 2.5 seconds), running a minimal raycast to check for solid walls before launching a projectile.

## ⛓️ Interconnected Dependencies
*   Projectiles carry a small mass profile that applies a minute knockback vector to the player's movement system.

