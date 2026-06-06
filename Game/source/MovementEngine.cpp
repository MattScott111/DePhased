#include "MovementEngine.h"
#include "DePhased_Context.h"
#include "raylib.h"
#include <math.h>

namespace DePhased {
    namespace MovementEngine {

        // The "Weight" configuration
        constexpr float ACCELERATION = 2000.0f;
        constexpr float MAX_SPEED = 400.0f;
        constexpr float FRICTION = 8.0f; // Higher = stops faster

        void ProcessPlayerInput() {
            // Only process input for Entity 0 (Young Sir)
            float intentX = 0.0f;
            float intentZ = 0.0f;

            if (IsKeyDown(KEY_W)) intentZ -= 1.0f;
            if (IsKeyDown(KEY_S)) intentZ += 1.0f;
            if (IsKeyDown(KEY_A)) intentX -= 1.0f;
            if (IsKeyDown(KEY_D)) intentX += 1.0f;

            // Normalize diagonal movement so we don't move faster diagonally
            float length = sqrtf(intentX * intentX + intentZ * intentZ);
            if (length > 0.0f) {
                intentX /= length;
                intentZ /= length;
            }

            // Apply acceleration to velocity based on our Global Time (respects Phase Dilation)
            GContext.VelocityX[0] += intentX * ACCELERATION * GContext.GlobalDeltaTime;
            GContext.VelocityZ[0] += intentZ * ACCELERATION * GContext.GlobalDeltaTime;
        }

        void ApplyPhysics() {
            // Cap maximum speed
            float currentSpeed = sqrtf(GContext.VelocityX[0] * GContext.VelocityX[0] + 
                                       GContext.VelocityZ[0] * GContext.VelocityZ[0]);
            
            if (currentSpeed > MAX_SPEED) {
                float ratio = MAX_SPEED / currentSpeed;
                GContext.VelocityX[0] *= ratio;
                GContext.VelocityZ[0] *= ratio;
            }

            // Apply mathematical friction (decay) when no keys are pressed
            GContext.VelocityX[0] -= GContext.VelocityX[0] * FRICTION * GContext.GlobalDeltaTime;
            GContext.VelocityZ[0] -= GContext.VelocityZ[0] * FRICTION * GContext.GlobalDeltaTime;

            // Finally, apply Velocity to Position
            GContext.PosX[0] += GContext.VelocityX[0] * GContext.GlobalDeltaTime;
            GContext.PosZ[0] += GContext.VelocityZ[0] * GContext.GlobalDeltaTime;
        }
    }
}
