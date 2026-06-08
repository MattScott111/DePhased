#include "../include/CameraEngine.h"
#include "../include/GContext.h"
#include <cmath>

namespace DePhased {
    CameraDirector cameraDirector = { MODE_SCRIPTED, {0,0,0}, {0,0,0}, 1.0f };

    void UpdateCamera() {
        Vector3 target = cameraDirector.targetPos;

        // Follow mode: lock to proxy, apply Look-Ahead
        if (cameraDirector.mode == MODE_PLAYER_FOLLOW) {
            target.x = globalContext.physics.posX[0] + (globalContext.physics.velX[0] * 0.5f);
            target.z = globalContext.physics.posZ[0] + (globalContext.physics.velZ[0] * 0.5f);
        }

        // Damped Spring logic
        float tension = globalContext.state.isDephased ? 1.5f : 5.0f;
        cameraDirector.currentPos.x += (target.x - cameraDirector.currentPos.x) * tension * GetFrameTime();
        cameraDirector.currentPos.z += (target.z - cameraDirector.currentPos.z) * tension * GetFrameTime();
    }
}
