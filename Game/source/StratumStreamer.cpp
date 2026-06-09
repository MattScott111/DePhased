#include "../include/StratumStreamer.h"
#include "../include/EngineCore.h"

namespace DePhased {

    void StratumStreamer::UpdateStratumContext() {
        // Watch the player (entity 0) and update sector slot based on depth
        float y = GContext.Pos[0].y;
        
        if (y > 30.0f) GContext.activeSectorSlot = 2;       // Sky
        else if (y < -20.0f) GContext.activeSectorSlot = 0;  // Underground
        else GContext.activeSectorSlot = 1;                  // Surface
    }

    void StratumStreamer::StreamSectorTransition(int targetSlotIndex) {
        // Logic to trigger a reload or swap active registry segment
        GContext.activeSectorSlot = targetSlotIndex;
    }

    Vector3 StratumStreamer::CalculatePredictiveIntercept(uint32_t entityID, const Vector3& hazardOrigin, float projectileSpeed) {
        // Vector arithmetic performed directly on registry data
        Vector3 target = GContext.Pos[entityID];
        Vector3 direction = { target.x - hazardOrigin.x, target.y - hazardOrigin.y, target.z - hazardOrigin.z };
        return direction; // Simplified intercept logic
    }

} // End namespace DePhased
