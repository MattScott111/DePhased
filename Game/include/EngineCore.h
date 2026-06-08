#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H

#include <cstdint>
#include "Vector3.h"

namespace DePhased {

    // --- System Constants ---
    inline constexpr uint32_t SECTOR_CAPACITY = 256;
    inline constexpr uint32_t MAX_ENTITIES = 1024;

    // --- Core Registry Structure (SoA Layout) ---
    struct EngineContext {
        // --- Core Simulation Registry ---
        Vector3 Pos[MAX_ENTITIES];
        Vector3 Velocity[MAX_ENTITIES];
        Vector3 Force[MAX_ENTITIES];
        
        // --- Input & Orientation ---
        Vector3 MovementIntent[MAX_ENTITIES];
        float Yaw[MAX_ENTITIES];
        float Pitch[MAX_ENTITIES];
        
        // --- Camera & Interaction ---
        Vector3 CamPos[MAX_ENTITIES];
        float ZoomLevel[MAX_ENTITIES];
        
        // --- Economy & Inventory ---
        float PayloadWeight[MAX_ENTITIES];
        float DeuteriumReserve[MAX_ENTITIES];
        float LocalMarketInflation[MAX_ENTITIES];
        float HistoricalWattPrices[100];
        uint32_t CurrentTickPointer;
        float BaseWattValue;
        
        // --- Progression & Status ---
        // StateMask bit 0x1: Solid, 0x2: Phased
        uint64_t StateMask[MAX_ENTITIES];
        float EnergyPool[MAX_ENTITIES];
        uint32_t Level[MAX_ENTITIES];
        uint32_t CurrentXP[MAX_ENTITIES];
        float BaseMoveSpeed[MAX_ENTITIES];
        float FatigueModifier[MAX_ENTITIES];
        float Resonance[MAX_ENTITIES];
        
        // --- Environment ---
        uint32_t activeSectorSlot;
        float Humidity;
        float Temperature;
        float GlobalStaticCharge;
        uint8_t ActiveWeatherState;
        bool IsDevModeActive;
    };

    // Global Registry Instance
    extern EngineContext GContext; 
    extern bool IsDevModeVisible;
}

#endif
