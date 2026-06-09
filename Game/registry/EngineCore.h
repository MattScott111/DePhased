#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H

/**
 * @file EngineCore.h
 * @brief Master Engine Context.
 * * This file defines the global memory layout. All data is categorized into
 * specific registers to optimize CPU cache performance (SoA - Structure of Arrays).
 */

#include <cstdint>
#include "raylib.h"

namespace DePhased {

    // --- Global Constants ---
    inline constexpr uint32_t MAX_ENTITIES = 1024;
    inline constexpr uint32_t SECTOR_CAPACITY = 256;
    inline constexpr uint32_t MAX_MESSAGES = 256;

    // --- Message Bus ---
    struct EngineMessage {
        uint32_t type;
        uint32_t sender;
        uint64_t payload;
    };

    // --- Engine Context: The Global Aggregator ---
    // This is the single, pre-allocated memory block for the engine state.
    struct EngineContext {
        // --- Runtime State ---
        float    GlobalDeltaTime;
        uint32_t ExecutionMask;
        uint32_t ActiveUI_ID;
        bool     IsDevModeActive;

        // --- System Messaging ---
        EngineMessage MessageQueue[MAX_MESSAGES];
        uint32_t      MessageCount;
    };

    // Global Instance
    extern EngineContext GContext;
    void InitializeRegistry();
}

#endif
