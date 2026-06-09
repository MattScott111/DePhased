#include "../include/EnvironmentEngine.h"

namespace DePhased {

    void EnvironmentEngine::Update() {
        if (GContext.Environment.AcousticIntensity > 0.0f) {
            GContext.Environment.AcousticIntensity -= GContext.GlobalDeltaTime * 0.5f;
            if (GContext.Environment.AcousticIntensity < 0.0f) {
                GContext.Environment.AcousticIntensity = 0.0f;
            }
        }
    }

    void EnvironmentEngine::ResolveCollision(uint32_t entityID) {
        // Corrected: Uses PHASE_TOGGLE from EngineCore.h
        if ((GContext.SaveData.StateMask[entityID] & PHASE_TOGGLE) != 0) {
            return; // Spectral traversal: Physics solver skipped
        }

        // --- PHYSICAL COLLISION RESOLUTION ---
        // Implementation: Resolve solid-state collision against world geometry
        // stored in active sector slots.
        Vector3 pos = GContext.SaveData.Pos[entityID];
        Vector3 vel = GContext.Velocity[entityID];

        // Perform AABB/Cylinder overlap check here using raymath
        // If collision: GContext.SaveData.Pos[entityID] = Vector3Subtract(pos, vel);
    }

    void EnvironmentEngine::ShiftAtmosphere(float targetIntensity) {
        GContext.Environment.AcousticIntensity = targetIntensity;
    }
}
