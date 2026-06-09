#ifndef BALLISTICS_ENGINE_H
#define BALLISTICS_ENGINE_H

#include <cstdint>

namespace DePhased {
    class BallisticsEngine {
    public:
        static void ApplyWindAndSway(uint32_t entityID, float* outVecX, float* outVecY);
    };
}
#endif
