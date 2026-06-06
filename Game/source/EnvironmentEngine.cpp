#include "../include/EnvironmentEngine.h"
#include "../include/EngineCore.h"
#include <iostream>

namespace DePhased {

    void EnvironmentEngine::MaterializeSectorFromBlueprint(const GenericLevelBlueprint& blueprint) {
        uint32_t baseOffset = blueprint.sectorSlotIndex * SECTOR_CAPACITY;
        
        // Ensure pointer validity before dereferencing
        if (blueprint.fixedAnchors != nullptr) {
            for (uint32_t i = 0; i < blueprint.totalFixedAnchors; ++i) {
                uint32_t entityID = baseOffset + i;
                
                // Map blueprint anchor data directly into registry arrays
                GContext.Pos[entityID] = blueprint.fixedAnchors[i].position;
                
                // Set status bit to active in bit-packed registry
                GContext.StateMask[entityID] = ((uint64_t)blueprint.sectorSlotIndex << 32) | 0x1;
            }
        }
        std::cout << "[DOD Engine]: Sector " << blueprint.sectorSlotIndex << " materialized into registry." << std::endl;
    }

    void EnvironmentEngine::ResolveContextualObjectInteraction(uint32_t entityID, uint32_t targetEntityID) {
        (void)entityID;
        (void)targetEntityID;
    }

} // End namespace DePhased
