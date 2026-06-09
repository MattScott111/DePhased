#include "../include/CameraEngine.h"
#include "../include/EngineCore.h"
#include "raymath.h"

namespace DePhased {
    void CameraEngine::Update() {
        // Implementation logic using GContext
        if (GContext.ExecutionMask & EXEC_CINEMATIC) {
            GContext.CameraZoom = Lerp(GContext.CameraZoom, 0.5f, GContext.GlobalDeltaTime);
        }
    }
}
