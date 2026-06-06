#ifndef ENVIRONMENT_ENGINE_H
#define ENVIRONMENT_ENGINE_H

#include "LevelBlueprints.h"
#include <cstdint>

namespace DePhased {

    class EnvironmentEngine {
    public:
        static void MaterializeSectorFromBlueprint(const GenericLevelBlueprint& blueprint);
        static void ResolveContextualObjectInteraction(uint32_t entityID, uint32_t targetEntityID);
    };
}
#endif
