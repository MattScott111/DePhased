#include "../include/MovementController.h"
#include "../include/EngineCore.h"

namespace DePhased {

    // This matches the declaration in your MovementController.h exactly.
    void MovementController::ProcessPlayerMovement(uint32_t entityID, float weatherDrag, float deltaTime) {
        // 1. EXECUTION FIREWALL
        // We only process movement if the simulation layer is permitted.
        if (!(GContext.ExecutionMask & EXEC_SIMULATION)) {
            return;
        }

        // 2. RETRIEVE DATA
        // Using GContext registry as the single source of truth.
        Vector3 intent = GContext.MovementIntent[entityID];
        Vector3 velocity = GContext.Velocity[entityID];

        // 3. APPLY PHYSICS LOGIC
        // We incorporate the passed weatherDrag and deltaTime parameters.
        float speed = GContext.BaseMoveSpeed[entityID] * deltaTime;

        // Apply intent (normalized force)
        velocity.x += (intent.x * speed) - (velocity.x * weatherDrag);
        velocity.z += (intent.z * speed) - (velocity.z * weatherDrag);

        // 4. COMMIT DATA BACK TO REGISTRY
        GContext.Velocity[entityID] = velocity;
        GContext.SaveData.Pos[entityID].x += velocity.x;
        GContext.SaveData.Pos[entityID].z += velocity.z;
    }

} // End namespace DePhased
