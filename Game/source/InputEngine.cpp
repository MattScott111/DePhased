#include "../include/InputEngine.h"
#include "../include/MessagingMatrix.h"
#include "../include/EngineCore.h"
#include "raylib.h"
#include "raymath.h"

namespace DePhased {

    void InputEngine::Update() {
        // 1. Movement Intent (WASD + Arrows)
        Vector3 movement = {0};
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))    movement.z -= 1.0f;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))  movement.z += 1.0f;
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  movement.x -= 1.0f;
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) movement.x += 1.0f;

        // Correct normalization using raymath
        if (movement.x != 0.0f || movement.z != 0.0f) {
            movement = Vector3Normalize(movement);
        }
        GContext.MovementIntent[0] = movement;

        // 2. Action Toggles (Bitmask updates in registry)
        if (IsKeyPressed(KEY_LEFT_ALT))   GContext.SaveData.StateMask[0] ^= PHASE_TOGGLE;
        if (IsKeyPressed(KEY_R))          GContext.SaveData.StateMask[0] ^= RUN_TOGGLE;

        // Hold states
        if (IsKeyDown(KEY_LEFT_SHIFT))    GContext.SaveData.StateMask[0] |= LOCK_MOVEMENT;
        else                              GContext.SaveData.StateMask[0] &= ~LOCK_MOVEMENT;

        if (IsKeyDown(KEY_LEFT_CONTROL))  GContext.SaveData.StateMask[0] |= HIGHLIGHT;
        else                              GContext.SaveData.StateMask[0] &= ~HIGHLIGHT;

        // 3. Event-Driven Messaging
        if (IsKeyPressed(KEY_SPACE))  MessagingMatrix::PushMessage(JUMP, 0, 0);
        if (IsKeyPressed(KEY_C))      MessagingMatrix::PushMessage(CHAR_MENU, 0, 0);
        if (IsKeyPressed(KEY_I))      MessagingMatrix::PushMessage(INVENTORY_SCREEN, 0, 0);
        if (IsKeyPressed(KEY_ESCAPE)) MessagingMatrix::PushMessage(PAUSE_MENU, 0, 0);

        // 4. Mouse Logic
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            MessagingMatrix::PushMessage(ATTACK_ACTION, 0, 0);
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            GContext.SaveData.StateMask[0] |= (1 << 14); // PENDING_INTERACT
        }
    }
}
