# Threat Specification: Unit 12 - Scrap-Hauler

## 🔍 System Purpose
Governs the high-mass momentum tracking and crushing collision loops for the industrial transport rig.

## 🔍 Lore & Aesthetic Integration
An oversized, yellow industrial loader vehicle with open hydraulic pistons and an massive iron plow blade mounted to its front grille. It drives with low traction, its engine throwing thick black diesel smoke as its heavy tires tear up the street grid.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Box Dimensions: $Width = 2.2m, Height = 2.0m, Length = 3.5m$.
*   **Kinetic Mass Profile**: `float Mass = 3500.0f`.
*   **The Momentum Crush**: Deals massive impact force scaling directly with its active forward velocity vector: $\text{Force} = \text{Mass} \times \vec{v}$.

## 🧠 Thought Process & Logic Architecture
The Scrap-Hauler relies entirely on long acceleration curves. Because of its massive inertia, it cannot make sharp turns. When it misses Young Sir, it requires a large turning arc to re-align its forward orientation vector, leaving its rear exposed.

## ⛓️ Interconnected Dependencies
*   Its tires leave black rubber skids on the floor, temporarily altering the surface friction variables of those specific matrix cells.

