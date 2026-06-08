#include "../include/MovementController.h"
#include "../include/PhysicsProxy.h"
#include "../include/GContext.h"

namespace DePhased {

    void MovementController::ProcessPlayerMovement(uint32_t entityID, float weatherDrag, float deltaTime) {
        // 1. Identify Proxy Behavior
        ProxyShape shape = activePlayerProxy.shape;

        // 2. Fetch Registry Data via the GLOBAL INSTANCE (globalContext)
        // Accessing the instance 'globalContext', not the type 'GContext'
        float totalMass = 80.0f + globalContext.PayloadWeight[entityID];
        Vector3& vel = globalContext.Velocity[entityID];
        Vector3& pos = globalContext.Pos[entityID];
        Vector3& intent = globalContext.MovementIntent[entityID];

        // 3. Branching Physics
        switch (shape) {
            case SHAPE_CYLINDER:
                // Roll physics logic
                break;
            case SHAPE_BOX:
                // Box collision logic
                break;
            case SHAPE_MODEL_RIG:
                // Rig animation logic
                break;
        }

        // 4. Integrate
        float maxSpeed = globalContext.BaseMoveSpeed[entityID] * globalContext.FatigueModifier[entityID];

        Vector3 force = {
            ((intent.x * maxSpeed) - vel.x) * totalMass * (1.0f / deltaTime),
            0.0f,
            ((intent.z * maxSpeed) - vel.z) * totalMass * (1.0f / deltaTime)
        };

        vel.x += (force.x / totalMass) * deltaTime * weatherDrag * activePlayerProxy.dragCoefficient;
        vel.z += (force.z / totalMass) * deltaTime * weatherDrag * activePlayerProxy.dragCoefficient;

        pos.x += vel.x * deltaTime;
        pos.z += vel.z * deltaTime;

        // 5. Cleanup
        globalContext.Force[entityID] = {0.0f, 0.0f, 0.0f};
    }
}
