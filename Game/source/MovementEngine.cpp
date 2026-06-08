#include "../include/MovementEngine.h"
#include "../include/PhysicsProxy.h"
#include "../include/GContext.h"
#include "raylib.h"
#include <cmath>

namespace DePhased {

    void MovementEngine::Update() {
        // 1. Fetch Intent Bitmask (from Master Registry)
        uint32_t actions = globalContext.state.activeActions;

        // 2. Resolve Proxy Branch
        switch(activePlayerProxy.shape) {
            case SHAPE_CYLINDER: {
                // Torque Math: Build momentum
                Vector2 torque = { 0.0f, 0.0f };
                if (actions & MOVE_FORWARD)  torque.y -= 1.0f;
                if (actions & MOVE_BACKWARD) torque.y += 1.0f;
                if (actions & MOVE_LEFT)     torque.x -= 1.0f;
                if (actions & MOVE_RIGHT)    torque.x += 1.0f;

                // Apply torque with resistance scaling
                // Logic: Mass * Acceleration = Torque / Resistance
                float resistance = globalContext.physics.stability * 0.01f;
                float massInv = 1.0f / activePlayerProxy.mass;

                // Update velocity (Acceleration)
                globalContext.physics.velX[0] += (torque.x * massInv) * 10.0f * GetFrameTime();
                globalContext.physics.velZ[0] += (torque.y * massInv) * 10.0f * GetFrameTime();

                // Apply Friction (Grounding)
                globalContext.physics.velX[0] *= globalContext.physics.friction;
                globalContext.physics.velZ[0] *= globalContext.physics.friction;

                // Apply Velocity to Position
                globalContext.physics.posX[0] += globalContext.physics.velX[0];
                globalContext.physics.posZ[0] += globalContext.physics.velZ[0];
                break;
            }

            case SHAPE_BOX:
                // Stability-focused (Snappier, non-rolling movement)
                break;

            case SHAPE_MODEL_RIG:
                // Kinematic movement (Rig-driven)
                break;
        }
    }
}
