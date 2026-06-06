#pragma once
#include "raylib.h"

namespace DePhased {
    namespace CameraEngine {
        
        // Locks the camera to Young Sir initially
        void Initialize();
        
        // Executes the spring tension, lerp, and sine-wave physics
        void Update(float rawDelta);
        
        // Translates our raw DOD math into a format Raylib can draw with
        Camera2D GetRaylibCamera();
    }
}
