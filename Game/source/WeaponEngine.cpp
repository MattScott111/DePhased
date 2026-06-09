#include "../include/WeaponEngine.h"
#include "../include/EngineCore.h"

namespace DePhased {

    void WeaponEngine::FireWeapon(uint32_t entityID, float power) {
        // Apply recoil and resonance kickback to the registry
        float resonanceKick = GContext.Resonance[entityID] * power;
        GContext.Resonance[entityID] = std::min(10.0f, GContext.Resonance[entityID] + 0.1f);
        
        // Weapon impact would perform a raycast and update target's state
        (void)resonanceKick;
    }

    float WeaponEngine::GetDamageModifier(uint32_t entityID) {
        // Impact scales with player resonance registry
        return 1.0f + (GContext.Resonance[entityID] * 0.1f);
    }

} // End namespace DePhased
