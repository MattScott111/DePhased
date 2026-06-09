#ifndef WEATHER_ENGINE_H
#define WEATHER_ENGINE_H

#include <cstdint>

namespace DePhased {
    enum class WeatherState : uint8_t { CLEAR_SUNLIGHT, NEON_MIST, HEAVY_DOWNPOUR, ELECTRICAL_STORM };

    class WeatherEngine {
    public:
        static void UpdateWeather(float deltaTime, float environmentalTickTime);
        static float GetMovementDragModifier();
        static float GetSurfaceFrictionModifier();
        static float GetKineticDamageMultiplier();
    };
}
#endif
