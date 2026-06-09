#include "../include/ProgressionEngine.h"
#include "../include/EngineCore.h"
#include <algorithm>

namespace DePhased {

    void ProgressionEngine::InitializeProgression(uint32_t entityID) {
        GContext.Level[entityID] = 1;
        GContext.CurrentXP[entityID] = 0;
        GContext.BaseMoveSpeed[entityID] = 5.0f;
    }

    void ProgressionEngine::AwardExperience(uint32_t entityID, uint32_t xpAmount) {
        GContext.CurrentXP[entityID] += xpAmount;
        uint32_t required = CalculateRequiredXP(GContext.Level[entityID]);

        while (GContext.CurrentXP[entityID] >= required) {
            GContext.CurrentXP[entityID] -= required;
            GContext.Level[entityID]++;
            if (GContext.Level[entityID] % 5 == 0) {
                GContext.BaseMoveSpeed[entityID] *= 1.05f;
            }
            required = CalculateRequiredXP(GContext.Level[entityID]);
        }
    }

    uint32_t ProgressionEngine::CalculateRequiredXP(uint32_t level) {
        return 1000 + (level * 500);
    }

} // End namespace DePhased
