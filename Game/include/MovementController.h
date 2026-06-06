#ifndef MOVEMENT_CONTROLLER_H
#define MOVEMENT_CONTROLLER_H

#include <cstdint>

namespace DePhased {
    class MovementController {
    public:
        // Operates exclusively on GContext registry via entityID
        static void ProcessPlayerMovement(uint32_t entityID, float weatherDrag, float deltaTime);
    };
}
#endif
