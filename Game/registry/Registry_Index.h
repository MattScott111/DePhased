#ifndef REGISTRY_INDEX_H
#define REGISTRY_INDEX_H

/**
 * @file Registry_Index.h
 * @brief Master aggregation header for all data registries.
 * * This file centralizes the inclusion of all system-specific registries.
 * Engines should include this to access the full system data state.
 */

#include "EngineCore.h"
#include "PhysicsRegistry.h"
#include "EconomyRegistry.h"
#include "EnvironmentRegistry.h"
#include "CameraRegistry.h"
#include "InputRegistry.h"
#include "AchievementRegistry.h"
#include "BallisticsRegistry.h"
#include "CharacterRegistry.h"
#include "EntityBlueprintRegistry.h"
#include "InventoryRegistry.h"
#include "LobbyRegistry.h"
#include "MovementRegistry.h"
#include "ProgressionRegistry.h"
#include "WeatherRegistry.h"
#include "WeaponRegistry.h"

namespace DePhased {

    /**
     * @brief Initializes all registry memory blocks.
     * Called at engine startup to ensure deterministic, zeroed memory state.
     */
    void InitializeRegistry();
}

#endif
