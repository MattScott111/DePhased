# Atmospheric Weather Engine
**Target:** Data-Driven Climate Manipulation
**Rule:** Weather is a mathematical governor that actively overwrites multipliers in the physics, traction, and photonics arrays. It is not a visual effect; it is a global environment modifier.

## 1. The Global Weather Seed
The active weather is defined by a single 8-bit integer (`uint8_t g_ActiveWeatherCondition`). The engine reads this and applies simultaneous filters to the sector's arrays.

## 2. Photonic & Environmental Synergies
The Weather Engine actively manipulates light/darkness values to create terrifying, dynamic atmospheres:
* **Crystalline Fog (Radius Expansion):** A dense fog that scatters light.
  * *Physics Effect:* `LightIntensity` is halved (dimming), but `LightRadius` is multiplied by `3.0f`.
* **Static Storm Blackouts:** A localized anomaly.
  * *Physics Effect:* Floods the sector with a baseline `-10.0f` darkness float, requiring high-powered light sources (`> 50.0f`) to counteract.

## 3. Traction & Kinetic Degradation
Weather writes directly to the `TractionArray`. 
* **Conditions:** Precipitation, coolant spills, or extreme pressure changes overwrite the friction float (`1.0f` down to `0.3f`). 
* **Kinetic Yield:** High-mass entities (Scrap-Haulers) experience violent drift, as their momentum cannot be countered by the low traction values.

## 4. System Relational Links
* **Photonics:** Manipulates the `LightPosition` and `LightIntensity` arrays.
* **Movement:** Directly writes friction multipliers to the `TractionArray` used by the `MovementController`.
