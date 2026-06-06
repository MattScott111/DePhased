#include "Chapter_01.h"
#include "../include/EngineCore.h"
#include "../include/InputEngine.h"
#include "raylib.h"

namespace DePhased {
    Chapter_01::Chapter_01() {
        GContext.Pos[0] = {0,0,0};
        GContext.StateMask[0] = 0x1; // Solid start
    }

    void Chapter_01::Update() {
        InputEngine::ProcessInput(0);
        // Apply physics (basic)
        GContext.Pos[0].x += GContext.MovementIntent[0].x * 0.1f;
        GContext.Pos[0].z += GContext.MovementIntent[0].z * 0.1f;
    }

    void Chapter_01::Draw() {
        BeginMode3D({ {10,10,10}, {0,0,0}, {0,1,0}, 45, 0 });
            // Color shift if Phased
            Color charColor = (GContext.StateMask[0] & 0x2) ? PURPLE : BLUE;
            DrawCylinder( {GContext.Pos[0].x, 0, GContext.Pos[0].z}, 0.5f, 0.5f, 2.0f, 16, charColor);
        EndMode3D();
    }
}
