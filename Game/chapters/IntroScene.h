#include "IntroScene.h"
#include "../include/GlobalContext.h"
#include "raylib.h"

namespace DePhased {
    void IntroScene::Update() {
        // Procedural camera movement or logic for workbench interaction
    }

    void IntroScene::Draw() {
        DrawText("IRON AWAKENING: WORKBENCH", 100, 50, 30, YELLOW);
        // Draw cylinder representing Young Sir
        DrawCylinder({640, 360, 0}, 50, 50, 100, 16, GRAY);
    }
}
