# Threat Specification: Gatekeeper 02 - Flux-Node 09

## 🔍 System Purpose
Establishes the macro-climatic overrides and environmental area-of-effect zones for the second gatekeeper.

## 🌀 Lore & Aesthetic Integration
A massive corporate substation generator that has grown fully self-aware. Its massive cooling towers spew super-heated steam into the sky, while its base is completely submerged in a massive pool of electrified heavy water.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Fixed Industrial Structure Box: $Width = 6.0m, Height = 8.0m, Length = 6.0m$.
*   **Kinetic Mass Profile**: `Static Entity` (Infinite Mass; un-pushable).
*   **The Overrain Protocol**: Upon initialization, it forces the global environment engine's `Humidity` scale to a hard locked `1.0`, triggering an infinite downpour across the sandbox zone.

## 🧠 Thought Process & Logic Architecture
Because the node is entirely stationary, its combat script manages secondary entity allocation. It spawns continuous waves of airborne **Unit_03_Grid_Sentry_Drone.md** units from its side ventilation vents to defend its core circuits from close-range strikes.

## ⛓️ Interconnected Dependencies
*   Defeating the node sets the global flag `GATEKEEPER_02_DOWN = true`, permanently clearing the storm vectors over Sector 0.

