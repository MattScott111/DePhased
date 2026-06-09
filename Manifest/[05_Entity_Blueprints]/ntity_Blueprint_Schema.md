# Entity Blueprint Schema
**Archetype:** Entity Form (Configuration)
**Version:** 1.1.0

The Blueprint represents the entity's "DNA." It links the Race/Type matrix to the actual Registry arrays.

## Blueprint Structure
```cpp
struct EntityBlueprint {
    uint8_t raceID;      // Terran, Veylarian, Chitin-Kreen
    uint8_t typeID;      // Stealth, Mastermind, Titan, Auric, Ranged
    float   baseSpeed;
    float   baseResonance;
    uint32_t activeAbilityMask; // Bitfield for Race/Type ability capabilities
};
