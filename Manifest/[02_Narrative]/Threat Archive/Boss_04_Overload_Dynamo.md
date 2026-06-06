# Threat Specification: Gatekeeper 04 - Overload Dynamo

## 🔍 System Purpose
Governs the environmental physics magnetic pulling forces and mass collection vectors for the fourth gatekeeper.

## 🌀 Lore & Aesthetic Integration
A massive, spherical magnetic reactor core that has broken loose from its structural pillars. It floats 1 meter off the ground, its raw magnetic fields pulling iron structural rebar from the concrete walls and causing all loose salvage to spin wildly in the air.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Sphere Dimensions: $Radius = 2.5m$.
*   **Kinetic Mass Profile**: `float Mass = 4000.0f`.
*   **The Inward Vortex**: Applies a continuous, inward-facing gravitational force vector to all nearby **Layered_Inventory_Matrix.md** dynamic crates: $\vec{f} = \text{Dynamo.Pos} - \text{Crate.Pos} \times \text{ForceMultiplier}$.

## 🧠 Thought Process & Logic Architecture
The Dynamo updates its magnetic pull profiles once every 3 frames to optimize performance. It utilizes these pulled boxes as an orbital shield, spinning them around its perimeter to block incoming project vectors from hitting its core hull.

## ⛓️ Interconnected Dependencies
*   Forces the player's movement system into a constant forward-slipping traction profile due to the intense magnetic draw on their tactical backpack.

