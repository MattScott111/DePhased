#ifndef ACHIEVEMENT_ENGINE_H
#define ACHIEVEMENT_ENGINE_H

#include <cstdint>

namespace DePhased {
    class AchievementEngine {
    public:
        static void EvaluateAttributeRewards(uint32_t entityID);
        static void RegisterMilestone(uint32_t entityID, uint32_t milestoneID);
    };
}
#endif
