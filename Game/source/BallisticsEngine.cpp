#include "../include/BallisticsEngine.h"
#include "../include/EngineCore.h"
#include <cmath>

namespace DePhased {

    void BallisticsEngine::ApplyWindAndSway(uint32_t entityID, float* outVecX, float* outVecY) {
        // Fetch global environmental factors directly
        float windEffect = GContext.GlobalStaticCharge * 0.5f;
        
        // Calculate sway based on local registry pos
        *outVecX = std::sin(GContext.Pos[entityID].y * 0.1f) * windEffect;
        *outVecY = std::cos(GContext.Pos[entityID].x * 0.1f) * windEffect;
    }

} // End namespace DePhased
