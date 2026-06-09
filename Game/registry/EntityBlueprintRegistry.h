#ifndef ENTITY_BLUEPRINT_H
#define ENTITY_BLUEPRINT_H

#include <cstdint>

namespace DePhased {

    struct EntityBlueprint {
        uint8_t  raceID;      // 0: Terran, 1: Veylarian, 2: Chitin-Kreen
        uint8_t  typeID;      // 0: Stealth, 1: Mastermind, 2: Titan, 3: Auric, 4: Ranged
        float    baseSpeed;
        float    baseResonance;
        uint32_t activeAbilityMask;
    };

    // Helper to map type to stats
    inline EntityBlueprint GetBlueprint(uint8_t race, uint8_t type) {
        // Logic will return static configurations based on the Race/Type matrix
        return { race, type, 5.0f, 1.0f, 0x0 };
    }
}

#endif
