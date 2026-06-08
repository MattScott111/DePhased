#include "../include/EngineCore.h"
#include "raylib.h"

namespace DePhased {

    void DrawSystemTelemetry() {
        if (!GContext.IsDevModeActive) return;

        // Telemetry readout directly from cache-aligned registry buffers
        DrawText(TextFormat("Active Weather: %d", GContext.ActiveWeatherState), 10, 10, 20, GREEN);
        DrawText(TextFormat("Player Pos: %.2f, %.2f", GContext.Pos[0].x, GContext.Pos[0].z), 10, 30, 20, GREEN);
        DrawText(TextFormat("Energy Pool: %.2f", GContext.EnergyPool[0]), 10, 50, 20, GREEN);
    }
    
    void ToggleDevMode() {
        GContext.IsDevModeActive = !GContext.IsDevModeActive;
    }

} // End namespace DePhased
