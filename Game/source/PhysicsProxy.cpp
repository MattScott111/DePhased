#include "../include/PhysicsProxy.h"

namespace DePhased {
    // Defaulting to Cylinder proxy as per Iron Awakening vision
    PhysicsProxy activePlayerProxy = { SHAPE_CYLINDER, 0.5f, 0.0f, 2.0f, 80.0f, 0.1f };
}
