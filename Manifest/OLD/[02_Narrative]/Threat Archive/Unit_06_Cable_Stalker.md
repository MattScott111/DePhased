# Threat Specification: Unit 06 - Cable-Stalker

## 🔍 System Purpose
Manages the vertical ceiling navigation and ambush behaviors for the mechanical spider unit.

## 🌀 Lore & Aesthetic Integration
A horrifying, multi-jointed steel arachnid drone designed to cling to the underside of heavy industrial conduits and girders. It remains completely stationary in the high shadows, waiting for unmetered currents to pass directly underneath its position.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Sphere Dimensions: $Radius = 0.7m$.
*   **Kinetic Mass Profile**: `float Mass = 55.0f`.
*   **The Drop Ambush**: Fires a down-facing raycast. If Young Sir breaks the ray, the unit disables its ceiling lock, applying a high downward acceleration vector to drop directly onto his position.

## 🧠 Thought Process & Logic Architecture
To maintain absolute CPU optimization, the unit's AI script remains in a dormant state while hanging from ceilings. It performs no pathfinding checks or movement updates until its simple vertical trigger ray is tripped.

## ⛓️ Interconnected Dependencies
*   If the ambush connects, it forces Young Sir into a temporary pinned down state, instantly increasing local Fatigue index variables.

