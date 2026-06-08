#pragma once
#include "GContext.h"

namespace DePhased {
    class EnvironmentEngine {
    public:
        // Branching collision resolution: Spectral vs Physical
        static void ResolveCollision(uint32_t entityID);
    };
}
