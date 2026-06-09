#ifndef MOVEMENT_ENGINE_H
#define MOVEMENT_ENGINE_H

#include "EngineCore.h"

namespace DePhased {
    class MovementEngine {
    public:
        // Global integration step for physics
        static void Update(float deltaTime);
    };
}
#endif
