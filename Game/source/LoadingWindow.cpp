#include "../include/LoadingWindow.h"
#include "../include/EngineCore.h"
#include "raylib.h"

namespace DePhased {

    void LoadingWindow::Update() {
        // Handle loading transition logic (e.g., checking if sector is loaded)
        // StratumStreamer::UpdateStratumContext();
    }

    void LoadingWindow::Draw() {
        // Minimalistic load screen rendering
        DrawText("DE-PHASED | IRON AWAKENING", 400, 300, 30, WHITE);
        DrawText("System Calibrating...", 400, 340, 20, GRAY);
    }

} // End namespace DePhased
