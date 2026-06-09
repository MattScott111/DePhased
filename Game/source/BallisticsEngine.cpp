#include "../include/BallisticsEngine.h"
#include "../include/EngineCore.h"
#include <cmath>

namespace DePhased {

    void BallisticsEngine::ApplyWindAndSway(uint32_t entityID, float* outVecX, float* outVecY) {
        // Firewall
        if (!(GContext.ExecutionMask & EXEC_SIMULATION)) return;

        // Use GContext environmental data to calculate sway
        float time = GContext.GlobalDeltaTime;
        float windStrength = GContext.Environment.GlobalStaticCharge * 0.01f;

        // Apply sine-based sway based on resonance
        float sway = sinf(time * GContext.SaveData.Resonance[entityID]) * windStrength;

        // Output results to provided pointers
        if (outVecX) *outVecX = sway;
        if (outVecY) *outVecY = sway * 0.5f;
    }
}
