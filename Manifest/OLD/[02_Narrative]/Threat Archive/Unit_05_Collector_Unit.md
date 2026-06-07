# Threat Specification: Unit 05 - Collector Unit

## 🔍 System Purpose
Defines the resource sweeping behavior and heavy physics properties of the autonomous cleanup mechanism.

## 🌀 Lore & Aesthetic Integration
A massive, slow-moving vacuum tank operating on continuous rubber treads. Its front face houses a rotating wire-brush drum designed to strip scrap wires and loose copper from the streets, feeding it into a pressurized storage bin behind its cab.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Box Dimensions: $Width = 1.8m, Height = 1.5m, Length = 2.5m$.
*   **Kinetic Mass Profile**: `float Mass = 1200.0f` (Heavy industrial hazard mass).
*   **The Vacuum Sweep**: Automatically tracks and pulls loose physics items within a $3.0$-meter front radius into its own storage inventory array.

## 🧠 Thought Process & Logic Architecture
The Collector Unit operates completely neutrally to the player unless attacked. It moves on a slow, continuous loop across the level matrix, functioning primarily as a physical moving obstacle that blocks tight hallways and doorways.

## ⛓️ Interconnected Dependencies
*   Destroying the unit unlocks a massive cache of raw metal salvage components for the tactical backpack.

