# Gear Registry Architecture

## Core Philosophy: Gear as Data
Gear items are stateless data definitions. They possess `Tier` (technology level) and `Rank` (modification level).

## Registry Implementation
- **Storage**: Each entity in `GContext` maintains an `InventoryBuffer[16]`—an array of 16 gear indices.
- **Physical Integration**: When gear is equipped, the `CombatSystem` reads `GearRank` from the `GContext` array to scale impact, damage, and reach.
- **The "Conductive" System**: Gear indices mapped to the `WeatherEngine` array allow the environment to affect the player's stats (e.g., Static Storms multiplying gear power at the cost of detection radius).
