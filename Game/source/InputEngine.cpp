#include "../include/InputEngine.h"
#include "../include/EngineCore.h"

namespace DePhased {
    InputMapping InputEngine::bindings;

    void InputEngine::ProcessInput(uint32_t entityID) {
        GContext.MovementIntent[entityID] = {0,0,0};
        if (IsKeyDown(bindings.moveForward)) GContext.MovementIntent[entityID].z += 1.0f;
        if (IsKeyDown(bindings.moveBack))    GContext.MovementIntent[entityID].z -= 1.0f;
        if (IsKeyDown(bindings.moveLeft))    GContext.MovementIntent[entityID].x -= 1.0f;
        if (IsKeyDown(bindings.moveRight))   GContext.MovementIntent[entityID].x += 1.0f;
        
        if (IsKeyPressed(bindings.phaseToggle)) {
            GContext.StateMask[entityID] ^= 0x2; // Toggle Phased Bit
        }
    }
}
