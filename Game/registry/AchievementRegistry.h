#ifndef ACHIEVEMENT_ENGINE_H
#define ACHIEVEMENT_ENGINE_H

#include <cstdint>

namespace DePhased {

    class AchievementEngine {
    public:
        // Evaluates progress against thresholds in GContext.SaveData
        static void EvaluateAttributeRewards(uint32_t entityID);

        // Internal helper to flag milestones in the GContext bitmask
        static void RegisterMilestone(uint32_t entityID, uint32_t milestoneID);
    };

}

#endif
