#include "../include/LevelBlueprints.h"
#include "../include/EngineCore.h"

namespace DePhased {

    // This processor is stateless; it maps blueprint data to registry indices
    void InstantiateBlueprint(const GenericLevelBlueprint& blueprint) {
        uint32_t baseOffset = blueprint.sectorSlotIndex * SECTOR_CAPACITY;
        
        for (uint32_t i = 0; i < blueprint.totalFixedAnchors; ++i) {
            uint32_t entityID = baseOffset + i;
            // Map anchor data directly into the GContext registry
            GContext.Pos[entityID] = blueprint.fixedAnchors[i].position;
            GContext.StateMask[entityID] = blueprint.fixedAnchors[i].bitPackedState;
        }
    }

} // End namespace DePhased
