#ifndef CHARACTER_ACTOR_H
#define CHARACTER_ACTOR_H

#include "Vector3.h"
#include <cstdint>

namespace DePhased {
    class CharacterActor {
    public:
        // Now purely functional; operates on the registry by entityID
        static void InitializeCharacter(uint32_t entityID);
        static void InjectInputIntent(uint32_t entityID, const Vector3& intent, float yawDelta, float pitchDelta);
    };
}
#endif
