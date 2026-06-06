#ifndef PROGRESSION_ENGINE_H
#define PROGRESSION_ENGINE_H

#include <cstdint>

namespace DePhased {
    class ProgressionEngine {
    public:
        static void InitializeProgression(uint32_t entityID);
        static void AwardExperience(uint32_t entityID, uint32_t xpAmount);
        static uint32_t CalculateRequiredXP(uint32_t level);
    };
}
#endif
