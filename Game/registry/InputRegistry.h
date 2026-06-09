#pragma once
#include <cstdint>
#include <map>

namespace DePhased {
    // Defines the standard action set
    enum Action : uint32_t {
        MOVE_FORWARD    = 1 << 0,
        MOVE_BACKWARD   = 1 << 1,
        MOVE_LEFT       = 1 << 2,
        MOVE_RIGHT      = 1 << 3,
        PHASE_TOGGLE    = 1 << 4, // P Key
        JUMP            = 1 << 5, // Space
        INVENTORY       = 1 << 6, // I
        CHAR_MENU       = 1 << 7, // C
        COMM_MENU       = 1 << 8, // A (Community/Abilities as discussed)
        PAUSE_MENU      = 1 << 9, // ESC
        ATTACK_ACTION   = 1 << 10,// Mouse Right Click
        RUN_TOGGLE      = 1 << 11,// R
        LOCK_MOVEMENT   = 1 << 12,// Shift
        HIGHLIGHT       = 1 << 13 // ALT
    };

    // Default Key Map Table
    struct KeyMap {
        int phaseKey = 80;        // 'P'
        int jumpKey = 32;         // Space
        int inventoryKey = 73;    // 'I'
        int characterMenuKey = 67;// 'C'
        int pauseKey = 256;       // ESC
        // ... etc
    };
}
