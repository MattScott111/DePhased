# Threat Specification: Unit 16 - Signal Stalker

## 🔍 System Purpose
Defines the climate-scaling behavior and size transformation matrices for the environmental anomaly.

## 🌀 Lore & Aesthetic Integration
A mass of coiled copper wiring and scrap mesh held together by a pulsing magnetic core. It slithers along the floor like an electronic serpent, actively seeking out wet areas to pull raw moisture directly into its electrical grounding points.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Box Dimensions: $Width = 0.4m, Height = 0.3m, Length = 1.8m$.
*   **Kinetic Mass Profile**: `float Mass = 30.0f` (Scales dynamically up to `90.0f`).
*   **The Humidity Absorption**: The unit reads the global environment's `Humidity` float value. If Humidity matches or exceeds `0.85`, the unit's scaling matrix expands by $2.0\times$, increasing its attack radius.

## 🧠 Thought Process & Logic Architecture
The Stalker evaluates wet surface matrix blocks. Its movement vectors prioritize grid coordinates flagged with active water or puddle entities, choosing paths that maximize its humidity accumulation loops.

## ⛓️ Interconnected Dependencies
*   Striking the unit while it is wet triggers a chain lightning cascade that deals damage to any nearby metallic units.

