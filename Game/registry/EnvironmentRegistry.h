#include "EngineCore.h"
#include "raymath.h"

namespace DePhased {

    void EnvironmentEngine::Update() {
        if (GContext.Environment.AcousticIntensity > 0.0f) {
            GContext.Environment.AcousticIntensity -= GContext.GlobalDeltaTime * 0.5f;
            if (GContext.Environment.AcousticIntensity < 0.0f)
                GContext.Environment.AcousticIntensity = 0.0f;
        }
    }

    void EnvironmentEngine::ResolveCollision(uint32_t entityID) {
        // Bypass physics if Phased Mode (Bit 0x2/PHASE_TOGGLE) is active
        if ((GContext.SaveData.StateMask[entityID] & PHASE_TOGGLE) != 0) {
            return;
        }

        // Standard physics resolution (AABB-Sphere collision test)
        Vector3 pos = GContext.SaveData.Pos[entityID];
        float radius = 0.5f;

        for (uint32_t i = 0; i < SECTOR_CAPACITY; ++i) {
            BoundingBox wall = { {pos.x - 5.0f, 0.0f, pos.z - 5.0f}, {pos.x + 5.0f, 2.0f, pos.z + 5.0f} };
            if (CheckCollisionBoxSphere(wall, pos, radius)) {
                GContext.SaveData.Pos[entityID] = Vector3Subtract(pos, GContext.Velocity[entityID]);
                GContext.Velocity[entityID] = Vector3Zero();
            }
        }
    }

    void EnvironmentEngine::ShiftAtmosphere(float targetIntensity) {
        GContext.Environment.AcousticIntensity = targetIntensity;
    }
}
