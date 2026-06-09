#include "../include/LobbyEngine.h"
#include "../include/EngineCore.h"
#include "raylib.h"

namespace DePhased {

    void LobbyEngine::Update() {
        // Firewall: Only process if UI layer is permitted
        if (!(GContext.ExecutionMask & EXEC_UI)) return;

        // Logic branching for lobby interaction
        // ActiveUI_ID: 0 = Main Menu, 1 = Lobby/Loadout, 2 = Terminal
        switch (GContext.ActiveUI_ID) {
            case 1: { // Lobby / Loadout Selection
                // Example: Press 'L' to confirm loadout and start simulation
                if (IsKeyPressed(KEY_L)) {
                    GContext.ExecutionMask = EXEC_SIMULATION;
                }
                break;
            }
            default:
                break;
        }
    }
}
