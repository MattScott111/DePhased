#ifndef LEVEL_BLUEPRINTS_H
#define LEVEL_BLUEPRINTS_H

#include "Vector3.h"
#include <cstdint>

namespace DePhased {

    struct GenericAnchorPin {
        Vector3 position;
        uint32_t objectTypeID;
        uint32_t bitPackedState;
        float payloadData[8];
    };

    struct GenericLevelBlueprint {
        uint32_t sectorSlotIndex;
        uint32_t generationSeed;
        uint32_t totalFixedAnchors;
        GenericAnchorPin* fixedAnchors;
        float baselineFrictionOverride;
    };
}
#endif
