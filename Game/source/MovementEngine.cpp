#include "../include/MovementEngine.h"
#include "../include/EngineCore.h"

namespace DePhased {

    void MovementEngine::Update(float deltaTime) {
        // Firewall: Only process if Simulation layer is permitted
        if (!(GContext.ExecutionMask & EXEC_SIMULATION)) return;

        // DOD Iteration: Update physics for all entities
        for (uint32_t i = 0; i < MAX_ENTITIES; ++i) {
            // Apply Intent to Velocity
            GContext.Velocity[i].x += (GContext.MovementIntent[i].x * GContext.BaseMoveSpeed[i]) * deltaTime;
            GContext.Velocity[i].z += (GContext.MovementIntent[i].z * GContext.BaseMoveSpeed[i]) * deltaTime;

            // Apply Friction (Grounding)
            GContext.Velocity[i].x *= 0.95f;
            GContext.Velocity[i].z *= 0.95f;

            // Integrate Position
            GContext.SaveData.Pos[i].x += GContext.Velocity[i].x * deltaTime;
            GContext.SaveData.Pos[i].z += GContext.Velocity[i].z;

            // Reset intent after consumption to prevent ghost movement
            GContext.MovementIntent[i] = {0.0f, 0.0f, 0.0f};
        }
    }
}
