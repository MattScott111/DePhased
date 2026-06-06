# Threat Specification: Unit 19 - Current Leach

## 🔍 System Purpose
Governs the attachment tracking logic and physical weight accumulation loops for the parasitic parasite.

## 🌀 Lore & Aesthetic Integration
A tiny, soft-bodied mechanical slug that glows with a faint green slime coat. It crawls silently along copper pipes, dropping down onto passing engineers to latch onto their battery compartments and drain their electrical potential.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Box Dimensions: $Width = 0.15m, Height = 0.1m, Length = 0.3m$.
*   **Kinetic Mass Profile**: `float Mass = 2.0f`.
*   **The Mass Burden Hook**: Upon a successful strike, the leach locks its coordinates directly onto Young Sir’s backpack attachment point. It adds a flat `+15.0f` to the `TotalPayloadWeight` variable, increasing movement drag.

## 🧠 Thought Process & Logic Architecture
The leach relies entirely on proximity triggers. It features no complex tracking AI; it remains attached to walls until the player's bounding box moves within a $1.0$-meter zone, triggering an instant jump vector.

## ⛓️ Interconnected Dependencies
*   Accumulating multiple leaches can heavily encumber the player, forcing acceleration curves into exhausted, low-traction states.

