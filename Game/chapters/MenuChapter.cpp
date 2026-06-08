#include "MenuChapter.h"
#include "../include/EngineCore.h"
#include "raylib.h"
#include <cstddef> // Required for size_t

namespace DePhased {
    MenuChapter::MenuChapter() : selectedIndex(0) {
        options = {"New Game", "Load Game", "Dev Mode (Toggle)", "Settings"};
    }

    void MenuChapter::Update() {
        if (IsKeyPressed(KEY_UP)) selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
        if (IsKeyPressed(KEY_DOWN)) selectedIndex = (selectedIndex + 1) % options.size();
    }

    void MenuChapter::Draw() {
        DrawText("DE-PHASED", 100, 100, 60, WHITE);
        for (std::size_t i = 0; i < options.size(); ++i) {
            Color color = (i == (std::size_t)selectedIndex) ? YELLOW : GRAY;
            DrawText(options[i].c_str(), 120, 200 + (i * 50), 30, color);
        }
        
        if (DePhased::IsDevModeVisible) {
            DrawText("DEV HUD: Active", 600, 20, 20, GREEN);
            DrawText(TextFormat("Resonance: %.2f", DePhased::GContext.Resonance[0]), 600, 50, 20, YELLOW);
            DrawText(TextFormat("Weather: %d", DePhased::GContext.ActiveWeatherState), 600, 80, 20, YELLOW);
        }
    }
}
