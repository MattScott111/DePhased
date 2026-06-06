#include "CameraEngine.h"
#include "DePhased_Context.h"
#include <math.h>

namespace DePhased {
    namespace CameraEngine {

        void Initialize() {
            // Snap exactly to Young Sir (Entity 0) on boot
            GContext.CamPosX = GContext.PosX[0];
            GContext.CamPosZ = GContext.PosZ[0];
            GContext.CamZoom = 1.0f;
        }

        void Update(float rawDelta) {
            bool isPhased = (GContext.StateMask[0] & PHASED_MASK);
            
            // 1. Base Target (Where the camera WANTS to look)
            float targetX = GContext.PosX[0];
            float targetZ = GContext.PosZ[0];

            // 2. Relational Magnetism Placeholder
            // (Future: Poll HostilityArray here and offset TargetX/Z toward enemies)

            // 3. Mathematical Spring Tension
            // 5.0f feels grounded and heavy. 
            float springTension = 5.0f; 

            // 4. Phase State Physics Alteration
            if (isPhased) {
                // The tether goes slack. The camera floats and drifts.
                springTension = 1.5f; 
                
                // Algorithmic Glitch: As stability drops, the camera mathematically shudders
                float glitchFactor = (100.0f - GContext.PhaseStability) * 0.05f;
                
                // Injecting time-based sine/cosine waves for nauseating drift
                targetX += sinf(GetTime() * 15.0f) * glitchFactor;
                targetZ += cosf(GetTime() * 17.0f) * glitchFactor;
            }

            // 5. Execute Mathematical Drift (Lerp)
            // Instead of Cam = Target, we move a fraction of the distance every frame.
            GContext.CamPosX += (targetX - GContext.CamPosX) * springTension * rawDelta;
            GContext.CamPosZ += (targetZ - GContext.CamPosZ) * springTension * rawDelta;
        }

        Camera2D GetRaylibCamera() {
            Camera2D cam = {0};
            // Tell Raylib to look exactly where our engine math says to look
            cam.target = (Vector2){ GContext.CamPosX, GContext.CamPosZ };
            
            // Offset places the target in the dead-center of a 1280x720 window
            cam.offset = (Vector2){ 1280.0f / 2.0f, 720.0f / 2.0f }; 
            cam.rotation = 0.0f;
            cam.zoom = GContext.CamZoom;
            return cam;
        }
    }
}
