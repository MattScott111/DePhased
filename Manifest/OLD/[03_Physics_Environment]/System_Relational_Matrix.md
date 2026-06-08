# System Relational Data Flow
**Target:** Pure System Abstraction
**Rule:** Zero "glue code" is permitted. Systems do not call functions on other systems. They communicate purely by reading and writing to the same centralized, pre-allocated memory arrays.

## 1. Weather & Movement
* **Writer:** The `WeatherEngine` reads the active barometric climate and writes a float (e.g., `0.3f` for a Coolant Spill) directly to the `TractionArray`.
* **Reader:** The `MovementController` passively reads the `TractionArray` and mathematically applies slip to heavy entities.

## 2. Inventory & Physics
* **Writer:** The `Layered_Inventory_Matrix` tallies the flat item weights and writes the sum to `TotalPayloadWeight`.
* **Reader:** The `MovementController` reads `TotalPayloadWeight` to dynamically throttle acceleration and kinetic drag.

## 3. Light & Environment
* **Writer:** The `EnvironmentEngine` calculates the density of the active stratum (e.g., dense Underground fog) and writes a dampening multiplier to the `AtmosphericDensityArray`.
* **Reader:** The `LightEngine` reads the `AtmosphericDensityArray` and mathematically throttles the `LightIntensity` floats, physically dimming the world.
