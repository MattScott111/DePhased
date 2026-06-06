#include "../include/WeatherEngine.h"
#include "../include/EngineCore.h"
#include <cmath>
#include <algorithm>

namespace DePhased {

    void WeatherEngine::UpdateWeather(float deltaTime, float environmentalTickTime) {
        float wavePattern = std::sin(environmentalTickTime * 0.05f);
        WeatherState currentState = (WeatherState)GContext.ActiveWeatherState;

        // Apply atmospheric metrics directly to the registry
        switch (currentState) {
            case WeatherState::CLEAR_SUNLIGHT:
                GContext.Humidity = 0.2f + (wavePattern * 0.05f);
                GContext.Temperature = 25.0f + (wavePattern * 2.0f);
                GContext.GlobalStaticCharge = 0.05f;
                break;
            case WeatherState::NEON_MIST:
                GContext.Humidity = 0.6f + (wavePattern * 0.1f);
                GContext.Temperature = 15.0f;
                GContext.GlobalStaticCharge = 0.2f;
                break;
            case WeatherState::HEAVY_DOWNPOUR:
                GContext.Humidity = 0.95f;
                GContext.Temperature = 10.0f - (wavePattern * 1.5f);
                GContext.GlobalStaticCharge = 0.6f + (wavePattern * 0.1f);
                break;
            case WeatherState::ELECTRICAL_STORM:
                GContext.Humidity = 1.0f;
                GContext.Temperature = 12.0f;
                GContext.GlobalStaticCharge = 1.0f;
                break;
        }
        (void)deltaTime;
    }

    float WeatherEngine::GetMovementDragModifier() {
        if (GContext.ActiveWeatherState == (uint8_t)WeatherState::HEAVY_DOWNPOUR) return 0.92f;
        if (GContext.ActiveWeatherState == (uint8_t)WeatherState::ELECTRICAL_STORM) return 0.85f;
        return 1.0f;
    }

    float WeatherEngine::GetSurfaceFrictionModifier() {
        return (GContext.Humidity > 0.8f) ? 0.75f : 1.0f;
    }

    float WeatherEngine::GetKineticDamageMultiplier() {
        if (GContext.GlobalStaticCharge >= 0.8f) return 2.5f;
        if (GContext.Humidity >= 0.85f) return 1.75f;
        return 1.0f;
    }

} // End namespace DePhased
