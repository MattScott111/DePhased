#pragma once
#include <cstdint>

namespace DePhased {
    // Action Bitmask: Using power-of-two values allows for simple
    // bitwise operations to check for concurrent inputs.
    enum Action : uint32_t {
        MOVE_FORWARD    = 1 << 0,
        MOVE_BACKWARD   = 1 << 1,
        MOVE_LEFT       = 1 << 2,
        MOVE_RIGHT      = 1 << 3,
        PHASE_TOGGLE    = 1 << 4,
        JUMP            = 1 << 5,
        INVENTORY       = 1 << 6,
        CHAR_MENU       = 1 << 7,
        COMM_MENU       = 1 << 8,
        PAUSE_MENU      = 1 << 9,
        ATTACK_ACTION   = 1 << 10,
        RUN_TOGGLE      = 1 << 11,
        LOCK_MOVEMENT   = 1 << 12,
        HIGHLIGHT       = 1 << 13
    };

    class InputEngine {
    public:
        // Update polls hardware and writes to the registry
        static void Update();
    };
}
