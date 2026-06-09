#include "../include/AchievementEngine.h"
#include "../include/EngineCore.h"

namespace DePhased {

    void AchievementEngine::EvaluateAttributeRewards(uint32_t entityID) {
        if (!(GContext.ExecutionMask & EXEC_SIMULATION)) return;

        // Check if player has 1000 XP and has NOT yet unlocked 'First Step' (Bit 0x10)
        if (GContext.SaveData.CurrentXP[entityID] >= 1000 &&
           !(GContext.SaveData.StateMask[entityID] & 0x10)) {

            RegisterMilestone(entityID, 0); // Index 0 = 'First Step'

            // Set milestone bit in persistent StateMask
            GContext.SaveData.StateMask[entityID] |= 0x10;
        }
    }

    void AchievementEngine::RegisterMilestone(uint32_t entityID, uint32_t milestoneID) {
        if (milestoneID < 128) {
            // Logic for triggering UI notifications or logging
            // Update the binary-dump-ready achievement array
            GContext.SaveData.Achievements[milestoneID] = true;
        }
    }
}
