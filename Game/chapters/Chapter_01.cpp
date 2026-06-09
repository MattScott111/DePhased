#include "Chapter_01.h"
#include "../include/EngineCore.h"
#include "raylib.h"

namespace DePhased {

    void Chapter_01::Update() {
        if (!(GContext.ExecutionMask & EXEC_SIMULATION)) return;

        Chapter_01::ProcessInput();

        // Atmosphere Bleed logic
        bool isPhased = (GContext.SaveData.StateMask[0] & 0x2);
        if (isPhased) {
            GContext.Environment.SkyHorizon = (Color){ 200, 180, 20, 255 };
            GContext.Environment.GroundGrid = Fade(RED, 0.7f);
        } else {
            GContext.Environment.SkyHorizon = (Color){ 30, 15, 40, 255 };
            GContext.Environment.GroundGrid = Fade(DARKGRAY, 0.5f);
        }
    }

    void Chapter_01::ProcessInput() {
        float speed = GContext.BaseMoveSpeed[0] * GContext.GlobalDeltaTime;
        Vector3 intent = {0.0f, 0.0f, 0.0f};

        if (IsKeyDown(KEY_W)) intent.z -= 1.0f;
        if (IsKeyDown(KEY_S)) intent.z += 1.0f;
        if (IsKeyDown(KEY_A)) intent.x -= 1.0f;
        if (IsKeyDown(KEY_D)) intent.x += 1.0f;

        GContext.MovementIntent[0] = intent;

        if (IsKeyPressed(KEY_SPACE)) {
            GContext.SaveData.StateMask[0] ^= 0x2;
        }
    }

    void Chapter_01::Draw() {
        bool isPhased = (GContext.SaveData.StateMask[0] & 0x2);
        Color actorColor = isPhased ? ORANGE : LIGHTGRAY;

        // Corrected: Explicitly cast all numeric parameters to float to match Raylib signature:
        // DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)
        DrawCylinder(
            GContext.SaveData.Pos[0],
            (float)1.0f,
            (float)1.0f,
            (float)2.5f,
            16,
            actorColor
        );

        DrawCylinderWires(
            GContext.SaveData.Pos[0],
            (float)1.0f,
            (float)1.0f,
            (float)2.5f,
            16,
            DARKGRAY
        );

        DrawText("SIMULATION: CHAPTER 01", 10, 10, 20, GREEN);
        DrawText(isPhased ? "MODE: PHASED" : "MODE: SOLID", 10, 40, 20, isPhased ? YELLOW : GRAY);
    }

} // End namespace DePhased
