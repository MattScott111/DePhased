# Threat Specification: Unit 01 - Aegis Spark-Hound

## 🔍 System Purpose
Defines the low-level mechanical variables, bounding boxes, and behaviors of the standard quad-pedal enforcement unit.

## 🌀 Lore & Aesthetic Integration
The Spark-Hound is a sleek, metal-skeleton hunting drone deployed by the Pax Aegis Consortium. Its joints hiss with compressed air, and its visor glows a steady, predatory neon-blue. When it tracks wireless energy, its visor strobes rapidly, and sparks cascade down its spine plating.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Box Dimensions: $Width = 0.5m, Height = 0.6m, Length = 1.2m$.
*   **Kinetic Mass Profile**: `float Mass = 45.0f` (Lightweight, low-inertia frame).
*   **The Battery-Drain Trigger**: Upon a successful intersection with Young Sir's capsule volume, the unit executes a `DrainQuickPocket()` buffer function, deleting 1 random consumable asset from Hotkey Slots 1-4.

## 🧠 Thought Process & Logic Architecture
The Spark-Hound utilizes a **Linear Line-of-Sight AI State Machine**. It calculates the relative distance vector $\vec{d} = \text{Player.Pos} - \text{Self.Pos}$. If $|\vec{d}| \le 15.0m$, it locks its yaw orientation directly to the player and triggers an instant full-velocity sprint. It runs strictly on flat plane matrices to save CPU processing costs.

## ⛓️ Interconnected Dependencies
*   Reads position vector parameters directly from **[03_Physics_Environment]/Dynamic_Movement_Matrix.md**.
*   Drops rare copper filament items into the inventory pools managed by **Layered_Inventory_Matrix.md** when health parameters equal zero.

