#include "../include/MovementController.h"
#include "../include/EngineCore.h"
#include <algorithm>

namespace DePhased {

    void MovementController::ProcessPlayerMovement(uint32_t entityID, float weatherDrag, float deltaTime) {
        float totalMass = 80.0f + GContext.PayloadWeight[entityID];
        Vector3& vel = GContext.Velocity[entityID];
        Vector3& pos = GContext.Pos[entityID];
        Vector3& force = GContext.Force[entityID];
        Vector3& intent = GContext.MovementIntent[entityID];

        // Apply force based on movement intent
        float maxSpeed = GContext.BaseMoveSpeed[entityID] * GContext.FatigueModifier[entityID];
        force.x += ((intent.x * maxSpeed) - vel.x) * totalMass * (1.0f / deltaTime);
        force.z += ((intent.z * maxSpeed) - vel.z) * totalMass * (1.0f / deltaTime);

        // Integrate Velocity
        vel.x += (force.x / totalMass) * deltaTime * weatherDrag;
        vel.z += (force.z / totalMass) * deltaTime * weatherDrag;

        // Integrate Position
        pos.x += vel.x * deltaTime;
        pos.z += vel.z * deltaTime;

        // Clear per-tick accumulation
        GContext.Force[entityID] = {0.0f, 0.0f, 0.0f};
    }

} // End namespace DePhased
