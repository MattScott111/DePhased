#include "raylib.h"
#include "DePhased_Context.h"
#include "MovementEngine.h"
#include "CameraEngine.h"

using namespace DePhased;

void InitYoungSir() {
    GContext.ActiveMask[0] = 1;
    GContext.StateMask[0] = 0; 
    GContext.PosX[0] = 100.0f; 
    GContext.PosZ[0] = 100.0f; 
    GContext.VelocityX[0] = 0.0f;
    GContext.VelocityZ[0] = 0.0f;
    GContext.Radius[0] = 15.0f;
    GContext.PhaseStability = 100.0f;

    CameraEngine::Initialize();
}

int main() {
    InitWindow(1280, 720, "DE-PHASED [v1.2.0] - Kinetic Test");
    SetTargetFPS(60);

    InitYoungSir();

    while (!WindowShouldClose()) {
        // 1. SYSTEM TIME CACHE
        float rawDelta = GetFrameTime();
        
        // 2. INPUT ENGINE (Phase Trigger)
        if (IsKeyPressed(KEY_SPACE)) {
            GContext.StateMask[0] ^= PHASED_MASK; 
        }

        bool isPhased = (GContext.StateMask[0] & PHASED_MASK);

        // 3. TEMPORAL PHYSICS (Time Dilation)
        // Everything moves at 30% speed except Young Sir!
        GContext.GlobalDeltaTime = isPhased ? (rawDelta * 0.3f) : rawDelta;

        // 4. DEGRADATION LOGIC
        if (isPhased) {
            GContext.PhaseStability -= 5.0f * rawDelta;
            if (GContext.PhaseStability <= 0.0f) {
                GContext.StateMask[0] &= ~PHASED_MASK; // Snap-Back
                GContext.PhaseStability = 100.0f;
            }
        } else if (GContext.PhaseStability < 100.0f) {
            GContext.PhaseStability += 10.0f * rawDelta; 
        }

        // 5. KINETIC PHYSICS & MOVEMENT
        // Young Sir always processes input at rawDelta so he doesn't slow down!
        float playerDelta = isPhased ? rawDelta : GContext.GlobalDeltaTime;
        
        // Temporarily override global delta for player physics to keep him fast in phase mode
        float tempDelta = GContext.GlobalDeltaTime; 
        GContext.GlobalDeltaTime = playerDelta; 
        
        MovementEngine::ProcessPlayerInput();
        MovementEngine::ApplyPhysics();
        
        GContext.GlobalDeltaTime = tempDelta; // Restore temporal state

        // 6. OBSERVER (Camera Math)
        CameraEngine::Update(rawDelta);

        // 7. RENDERING HOOK
        BeginDrawing();
        ClearBackground(isPhased ? DARKGRAY : BLACK);

        // Attach the Dynamic Camera
        BeginMode2D(CameraEngine::GetRaylibCamera());

            // Draw a quick grid so we can actually see our movement!
            for (int i = -1000; i <= 1000; i += 100) {
                DrawLine(i, -1000, i, 1000, Fade(DARKGRAY, 0.5f));
                DrawLine(-1000, i, 1000, i, Fade(DARKGRAY, 0.5f));
            }

            if (isPhased) {
                float glitchOffset = (100.0f - GContext.PhaseStability) * 0.1f;
                DrawCircleLines(
                    (int)GContext.PosX[0] + GetRandomValue(-glitchOffset, glitchOffset), 
                    (int)GContext.PosZ[0] + GetRandomValue(-glitchOffset, glitchOffset), 
                    GContext.Radius[0], YELLOW
                );
            } else {
                DrawCircle((int)GContext.PosX[0], (int)GContext.PosZ[0], GContext.Radius[0], LIGHTGRAY);
            }

        EndMode2D();

        // UI Overlay
        if (isPhased) {
            DrawText("DE-PHASED MODE: ACTIVE", 10, 10, 20, YELLOW);
            DrawText(TextFormat("STABILITY: %.1f%%", GContext.PhaseStability), 10, 40, 20, RED);
        } else {
            DrawText("PHYSICAL REALITY", 10, 10, 20, DARKGRAY);
        }
        DrawText("WASD: Move  |  SPACE: Phase", 10, 720 - 30, 20, GRAY);



        // OS Focus Diagnostic
        if (!IsWindowFocused()) {
            DrawRectangle(0, 0, 1280, 720, Fade(BLACK, 0.7f));
            DrawText("SYSTEM HALT: CLICK WINDOW TO SECURE INPUT DATA", 220, 350, 30, RED);
        }


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
