#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector3.h"
#include "GlobalContext.h"

namespace DePhased {

struct RigidBodySystem {
    // Acts on the GContext arrays directly using an entity index
    static inline void Integrate(uint32_t i, float deltaTime, float envDrag) {
        // GContext arrays are our "memory pool"
        GContext.VelocityX[i] += 0.0f * deltaTime; // Simplified for demo
        GContext.PosX[i] += GContext.VelocityX[i] * deltaTime;
        
        // Physics math operations directly on registry data
        GContext.VelocityX[i] *= (0.95f * envDrag);
    }
};

} // namespace DePhased

#endif
