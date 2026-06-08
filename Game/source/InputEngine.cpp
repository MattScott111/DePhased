#include "../include/InputEngine.h"
#include "../include/GContext.h"
#include "raylib.h"

namespace DePhased {

    void InputEngine::Update() {
        uint32_t actions = 0;

        // Movement Mapping (Polling continuous state)
        if (IsKeyDown(KEY_W)) actions |= MOVE_FORWARD;
        if (IsKeyDown(KEY_S)) actions |= MOVE_BACKWARD;
        if (IsKeyDown(KEY_A)) actions |= MOVE_LEFT;
        if (IsKeyDown(KEY_D)) actions |= MOVE_RIGHT;

        // Action Mapping (Polling events)
        if (IsKeyPressed(KEY_P))       actions |= PHASE_TOGGLE;
        if (IsKeyPressed(KEY_SPACE))   actions |= JUMP;
        if (IsKeyPressed(KEY_I))       actions |= INVENTORY;
        if (IsKeyPressed(KEY_C))       actions |= CHAR_MENU;
        if (IsKeyPressed(KEY_A))       actions |= COMM_MENU;
        if (IsKeyPressed(KEY_ESCAPE))  actions |= PAUSE_MENU;

        // Mouse / Shift / Alt
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) actions |= ATTACK_ACTION;
        if (IsKeyPressed(KEY_R))                       actions |= RUN_TOGGLE;
        if (IsKeyDown(KEY_LEFT_SHIFT))                actions |= LOCK_MOVEMENT;
        if (IsKeyDown(KEY_LEFT_ALT))                  actions |= HIGHLIGHT;

        // Atomically update the registry
        globalContext.state.activeActions = actions;
    }
}
