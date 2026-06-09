#ifndef WEAPON_ENGINE_H
#define WEAPON_ENGINE_H

#include <cstdint>
#include <algorithm>

namespace DePhased {
    class WeaponEngine {
    public:
        // Processes weapon firing, recoil, and resonance update
        static void FireWeapon(uint32_t entityID, float power);
        
        // Returns dynamic damage scaling based on player resonance
        static float GetDamageModifier(uint32_t entityID);
    };
}
#endif
