#include "MenuChapter.h"
#include "../include/EngineCore.h"
#include "raylib.h"
#include <math.h>

using namespace DePhased;

void MenuChapter::Update() {
    // Pulse the atmosphere while in the menu (Emergent Vibe)
    GContext.Environment.AcousticIntensity += GContext.GlobalDeltaTime * 2.0f;

    // Wait for the user to initiate the kinetic layer
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        // Handover: Drop the UI bit, grant the Simulation bit.
        // Zero loading screens. The main loop instantly swaps contexts.
        GContext.ExecutionMask = EXEC_SIMULATION;
    }
}

void MenuChapter::Draw() {
    // Calculate a gentle breathing alpha channel for the text
    float alpha = (sinf(GContext.Environment.AcousticIntensity) + 1.0f) * 0.5f;
    Color pulseColor = Fade(RAYWHITE, alpha);

    DrawText("DE-PHASED", 450, 250, 60, RAYWHITE);
    DrawText("PRESS SPACE TO AWAKEN", 470, 350, 20, pulseColor);

    // Telemetry/Version Info
    DrawText("v1.2.1 - Core Engine Matrix", 10, 690, 15, Fade(RAYWHITE, 0.3f));
    DrawText("STATUS: WAITING FOR KINETIC INPUT", 10, 10, 15, Fade(GREEN, 0.6f));
}
