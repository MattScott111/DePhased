#pragma once
#include <cstdint>

namespace DePhased {

    // Fixed-size attributes to maintain Zero-Allocation
    struct PlayerProfile {
        char characterName[32];
        uint8_t speciesID;
        uint8_t genderID;
        float baseAttributes[4]; // Strength, Agility, Resonance, Intelligence
    };

    // The Lobby Registry: Accessed only when AppState == STATE_LOBBY
    struct LobbyState {
        PlayerProfile playerProfile;
        uint8_t selectedIndex; // Used for UI navigation (Name -> Species -> Attr)
        bool isConfirmed;      // Final lock-in trigger
    };

    // Extend the Master Registry
    extern LobbyState lobbyRegistry;
}
