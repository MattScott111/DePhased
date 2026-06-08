#pragma once
#include "raylib.h"

namespace DePhased {
    enum CameraMode { MODE_PLAYER_FOLLOW, MODE_SCRIPTED };

    struct CameraDirector {
        CameraMode mode;
        Vector3 targetPos;    // Where we are going
        Vector3 currentPos;   // Where we are
        float zoom;           // 0.0 (Tight) to 2.0 (Eagle Eye)
    };

    extern CameraDirector cameraDirector;
    void UpdateCamera();
}
