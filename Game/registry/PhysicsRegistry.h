#pragma once
#include <cstdint>

namespace DePhased {
    enum ProxyShape : uint8_t {
        SHAPE_CYLINDER,
        SHAPE_BOX,
        SHAPE_MODEL_RIG
    };

    // Data-oriented structure for player physics proxy
    struct PhysicsProxy {
        ProxyShape shape;
        float radius;       // Cylinder radius
        float width;        // Box width
        float height;       // Box/Cylinder height
        float mass;
        float dragCoefficient;
    };

    extern PhysicsProxy activePlayerProxy;
}
