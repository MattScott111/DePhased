#pragma once

namespace DePhased {
    namespace MovementEngine {
        
        // Reads WASD input and converts it into raw physical momentum
        void ProcessPlayerInput();

        // Applies velocity to position and handles mathematical friction
        void ApplyPhysics();

    }
}
