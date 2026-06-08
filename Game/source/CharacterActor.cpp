#include "../include/CharacterActor.h"
#include "../include/EngineCore.h"

namespace DePhased {

    void CharacterActor::InitializeCharacter(uint32_t entityID) {
        // Registry initialization for new entities
        GContext.Pos[entityID] = {0.0f, 0.0f, 0.0f};
        GContext.Velocity[entityID] = {0.0f, 0.0f, 0.0f};
        GContext.EnergyPool[entityID] = 100.0f;
        GContext.StateMask[entityID] = 0x1; // Set Active bit
    }

    void CharacterActor::InjectInputIntent(uint32_t entityID, const Vector3& intent, float yawDelta, float pitchDelta) {
        // Update registry movement intent for the MovementController to process
        GContext.MovementIntent[entityID] = intent;
        GContext.Yaw[entityID] += yawDelta;
        GContext.Pitch[entityID] += pitchDelta;
    }

} // End namespace DePhased
