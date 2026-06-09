#pragma once
#include <cstdint>
#include "raylib.h"

namespace DePhased {
    // These are the abstract actions the Engine understands.
    enum Action : uint32_t {
        MOVE_FORWARD    = 1 << 0,
        MOVE_BACKWARD   = 1 << 1,
        MOVE_LEFT       = 1 << 2,
        MOVE_RIGHT      = 1 << 3,
        PHASE_TOGGLE    = 1 << 4,
        JUMP            = 1 << 5,
        INVENTORY_SCREEN = 1 << 6,
        CHAR_MENU       = 1 << 7,
        COMM_MENU       = 1 << 8,
        PAUSE_MENU      = 1 << 9,
        ATTACK_ACTION   = 1 << 10,
        RUN_TOGGLE      = 1 << 11,
        LOCK_MOVEMENT   = 1 << 12,
        HIGHLIGHT       = 1 << 13
    };

    // This maps physical inputs to abstract actions.
    // Core remains agnostic; this file only needs to change if you change input devices.
    inline bool IsActionTriggered(Action action) {
        switch(action) {
            case PHASE_TOGGLE: return IsKeyPressed(KEY_LEFT_ALT);
            case RUN_TOGGLE:   return IsKeyPressed(KEY_R);
            // ... etc
            default: return false;
        }
    }
}
