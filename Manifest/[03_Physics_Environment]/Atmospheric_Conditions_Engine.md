# Module: Atmospheric Conditions Engine
* **Designation**: Environmental Stratum (Atmosphere & Pressure)
* **Status**: Locked
* **File Hook**: `Game/source/WeatherEngine.cpp`
* **AI Context Vector**: GContext.AtmosphericPressure, LiquidDensity, CurrentWeatherState

---

## 1. ABSTRACT
Simulates weather, pressure, and liquid drag. Governs the global physics environment by writing directly to resistance arrays.

## 2. DATA ARCHITECTURE
* **Resistance SoA**: Stores `FluidDensity` and `PressureLevel` per sector-slot.
* **Reads**: `GContext.AtmosphericPressure`, `GContext.CurrentWeather`
* **Writes**: `RigidBody.DragCoefficient`.

## 3. EXECUTION PIPELINE
1. **Weather Update**: State machine cycles (Clear, Storm, Vacuum).
2. **Pressure Injection**: Updates `PressureLevel` in environmental arrays.
3. **Drag Modification**: `Kinetic_Actor_Engine` scales resistance based on density.

## 4. FAILURE CASCADE
If `PressureLevel` exceeds 1.5f, the engine forces a "Vacuum" state; `CrystallineFog` radius expands to Infinity. If `LightSource` intensity < 50.0f, the environment renders a full black-out.

## 5. STRICTURES
* Updates must be buffered. Instant density changes cause engine instability.
