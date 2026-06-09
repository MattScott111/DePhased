#include "../include/EngineCore.h"
#include <cstring> // Required for memset

namespace DePhased {

    // Define the global master registry instance
    EngineContext GContext;
    bool IsDevModeVisible = false;

    void InitializeEngine() {
        // 1. Reset the entire registry to zero-state
        // This ensures no 'garbage' data from previous runs or stack memory
        std::memset(&GContext, 0, sizeof(EngineContext));

        // 2. Set Initial Control State
        GContext.ExecutionMask = EXEC_UI; // Start in Lobby/UI mode
        GContext.GlobalDeltaTime = 0.0f;
        GContext.MessageCount = 0;
        GContext.IsDevModeActive = false;

        // 3. Initialize Camera Defaults (DOD-Compliant)
        GContext.CameraTargetID = 0; // Track protagonist by default
        GContext.CameraZoom = 1.0f;
        GContext.CameraLerpSpeed = 0.05f; // Initial "Weight" for cinematic feel
        GContext.CameraOffset = {0.0f, 0.0f};

        // 4. Initialize Environment Defaults
        GContext.Environment.SkyZenith = (Color){ 10, 10, 20, 255 };
        GContext.Environment.SkyHorizon = (Color){ 30, 15, 40, 255 };
        GContext.Environment.GroundGrid = (Color){ 20, 20, 20, 255 };
        GContext.Environment.FogDensity = 0.02f;

        // 5. Initialize Persistence Defaults
        GContext.SaveData.SaveVersion = 100;
        GContext.SaveData.ActiveChapterID = 0;
        GContext.SaveData.BaseWattValue = 100.0f;

        // 6. Reset Transient Arrays
        // Explicitly ensuring movement data starts neutral
        for (uint32_t i = 0; i < MAX_ENTITIES; ++i) {
            GContext.BaseMoveSpeed[i] = 5.0f;
            GContext.FatigueModifier[i] = 1.0f;
            GContext.PhaseStability[i] = 1.0f;
        }
    }
}
