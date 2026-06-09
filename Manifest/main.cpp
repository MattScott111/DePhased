#include "raylib.h"
#include "raymath.h"
#include "Game/include/EngineCore.h"
#include "Game/include/MessagingMatrix.h"
#include "Game/include/Chapter.h"
#include "Game/chapters/MenuChapter.h"
#include "Game/chapters/Chapter_01.h"

using namespace DePhased;

int main() {
    // 1. Initialization
    InitWindow(1280, 720, "DE-PHASED [v1.1.0] - Master Router");
    SetTargetFPS(60);
    DePhased::InitializeEngine();

    MenuChapter menuSystem;
    Chapter_01  chapter01;
    IChapter* activeSystem = &menuSystem;

    Camera3D cam = { { 0.0f, 15.0f, 20.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, CAMERA_PERSPECTIVE };

    // 2. Main Loop (Zero-Allocation Orchestrator)
    while (!WindowShouldClose()) {
        GContext.GlobalDeltaTime = GetFrameTime();

        // A. Process Messaging Matrix (The Event Bus)
        for (uint32_t i = 0; i < GContext.MessageCount; ++i) {
            EngineMessage msg = GContext.MessageQueue[i];
            if (msg.type == 0x1) { // MSG_NEW_GAME
                GContext.ExecutionMask = EXEC_SIMULATION;
                activeSystem = &chapter01;
            }
        }
        MessagingMatrix::ClearQueue();

        // B. Dynamic System Routing
        if (GContext.ExecutionMask & EXEC_UI) {
            activeSystem = &menuSystem;
        } else if (GContext.ExecutionMask & EXEC_SIMULATION) {
            activeSystem = &chapter01;
        }

        // C. Update System Logic
        activeSystem->Update();

        // D. Camera Interpolation (Registry-Driven)
        Vector3 targetPos = GContext.SaveData.Pos[GContext.CameraTargetID];
        Vector3 desiredCamPos = { targetPos.x, targetPos.y + 15.0f, targetPos.z + 20.0f };

        cam.position = Vector3Lerp(cam.position, desiredCamPos, GContext.CameraLerpSpeed);
        cam.target   = Vector3Lerp(cam.target, targetPos, GContext.CameraLerpSpeed);
        cam.fovy     = 45.0f * GContext.CameraZoom;

        // E. Rendering Hook
        BeginDrawing();
            ClearBackground(GContext.Environment.SkyZenith);

            if (GContext.ExecutionMask & EXEC_SIMULATION) {
                BeginMode3D(cam);
                    DrawGrid(100, 2.0f);
                    activeSystem->Draw();
                EndMode3D();
            }

            if (GContext.ExecutionMask & EXEC_UI) {
                activeSystem->Draw();
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
