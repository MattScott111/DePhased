# Threat Specification: Unit 02 - Patrol Tracker

## 🔍 System Purpose
Defines the technical attributes, detection cones, and logic loops for the standard airborne scout mechanism.

## 🌀 Lore & Aesthetic Integration
The Patrol Tracker is a hovering, copper-shielded orb utilizing a single, high-intensity halogen spotlight. Built by the Pax Aegis Consortium, it hums with a high-pitched drone, casting a sweeping white cone across the rain-slicked concrete floor to find unmetered electrical signals.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Sphere Dimensions: $Radius = 0.3m$.
*   **Kinetic Mass Profile**: `float Mass = 12.0f` (Ultra-light airborne hull).
*   **The Spotlight Intersect**: Evaluates a mathematical cone vector matrix. If the player capsule enters this geometric cone, the tracker transitions into `AlertState = true`, flashing a harsh crimson light.

## 🧠 Thought Process & Logic Architecture
The Tracker avoids complex pathfinding by utilizing a simple fixed-point lerping sequence between predetermined patrol markers. This completely eliminates CPU calculation overhead unless its detection cone is tripped.

## ⛓️ Interconnected Dependencies
*   Alert status signals nearby **Unit_01_Spark_Hound.md** instances to alter their AI vectors directly toward the player's spatial position.

