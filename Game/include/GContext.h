#pragma once
#include <cstdint>
#include "raylib.h"

namespace DePhased {

    // --- State Constants ---
    enum AppState : uint8_t {
        STATE_MENU,
        STATE_LOBBY,
        STATE_INTRO,
        STATE_PLAYING,
        STATE_PAUSED
    };

    // --- Input Definitions (Consolidated here to be globally visible) ---
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
        ATTACK_ACTION   = 1 << 10
    };

    // --- Physics Registry (DOD Arrays) ---
    struct PhysicsRegistry {
        float posX[64];
        float posZ[64];
        float velX[64];
        float velZ[64];
        float stability;
        float friction;
    };

    // --- Engine Control ---
    struct EngineState {
        AppState appState;
        bool isDephased;
        uint32_t activeActions; // Bitmask of inputs
    };

    // --- The Master Registry ---
    struct GContext {
        EngineState state;
        PhysicsRegistry physics;

        // Player-specific arrays (mapped to entityID)
        Vector3 Pos[64];
        Vector3 Velocity[64];
        Vector3 Force[64];
        Vector3 MovementIntent[64];
        float BaseMoveSpeed[64];
        float FatigueModifier[64];
        float PayloadWeight[64];
    };

    // Define the global instance
    extern GContext globalContext;

    // Typedef for struct tagging compatibility
    typedef struct GContext GContext;
}
