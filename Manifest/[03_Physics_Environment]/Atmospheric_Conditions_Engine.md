# Module: Atmospheric Conditions Engine
* **Designation**: Environmental Stratum (Atmosphere & Pressure)
* **Status**: Locked
* **File Hook**: `Game/source/WeatherEngine.cpp`
* **AI Context Vector**: GContext.AtmosphericPressure, LiquidDensity, CurrentWeatherState

---

## 1. ABSTRACT
Simulates weather, pressure states, and liquid drag throughout the strata. This system influences actor movement and kinetic propagation by modifying the local environmental resistance arrays in real-time.

## 2. DATA ARCHITECTURE
* **Resistance SoA**: Stores `FluidDensity` and `PressureLevel` per sector-slot.
* **Reads**: `GContext.AtmosphericPressure`, `GContext.CurrentWeather`
* **Writes**: `RigidBody.DragCoefficient` (updates based on local conditions).

## 3. EXECUTION PIPELINE
1. **Weather Update**: The engine cycles through the weather state machine (Clear, Storm, High-Pressure, Vacuum).
2. **Pressure Injection**: Updates `PressureLevel` in the environment arrays for the active stratum.
3. **Drag Modification**: `Kinetic_Actor_Engine` reads the local density and scales actor movement resistance accordingly.

## 4. INTEGRATION HOOKS
* Feeds into the `Spatial_Event_Broadcaster` when weather changes (e.g., thunder impacts).

## 5. STRICTURES
* Atmospheric updates must be buffered; changing density too rapidly causes physical engine instability.
