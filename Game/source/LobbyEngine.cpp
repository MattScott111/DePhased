#include "../include/LobbyState.h"
#include "../include/GContext.h"
#include "../include/InputEngine.h"

namespace DePhased {
    // Ensure this matches your LobbyState struct definition
    LobbyState lobbyRegistry = { {"", 0, 0, {1.0f, 1.0f, 1.0f, 1.0f}}, 0, false };

    void UpdateLobby() {
        // Accessing the bitmask via the master globalContext registry
        // We use DePhased:: prefix to ensure we access the correct Action constant
        if (globalContext.state.activeActions & DePhased::MOVE_FORWARD) {
            if (lobbyRegistry.selectedIndex > 0) {
                lobbyRegistry.selectedIndex--;
            }
        }

        if (globalContext.state.activeActions & DePhased::ATTACK_ACTION) {
            // Check against the State enum defined in GContext.h
            if (lobbyRegistry.selectedIndex == 3) {
                globalContext.state.appState = DePhased::STATE_INTRO;
            }
        }
    }
}
