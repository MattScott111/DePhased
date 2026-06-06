#ifndef INPUT_ENGINE_H
#define INPUT_ENGINE_H

#include "raylib.h"
#include <cstdint>

namespace DePhased {
    struct InputMapping {
        int moveForward = KEY_W;
        int moveBack = KEY_S;
        int moveLeft = KEY_A;
        int moveRight = KEY_D;
        int phaseToggle = KEY_SPACE;
    };

    class InputEngine {
    public:
        static InputMapping bindings;
        static void ProcessInput(uint32_t entityID);
    };
}
#endif
