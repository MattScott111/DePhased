#pragma once
#include <stdint.h>

namespace DePhased {

    // Absolute Maximums for the DOD Engine
    constexpr int MAX_ENTITIES = 4096;
    
    // The crucial bit for activating the Spacebar De-Phased Mode
    constexpr uint8_t PHASED_MASK = 0x2; 

    // The Master Registry: Zero runtime allocations.
    struct GameContext {
        // --- Physical & Geometric Data ---
        float PosX[MAX_ENTITIES];
        float PosZ[MAX_ENTITIES];
        float VelocityX[MAX_ENTITIES];
        float VelocityZ[MAX_ENTITIES];
        float Radius[MAX_ENTITIES];

        // --- State & Logic Data ---
        uint8_t StateMask[MAX_ENTITIES];
        uint8_t ActiveMask[MAX_ENTITIES]; 

        // --- Engine Globals ---
        float GlobalDeltaTime;
        float PhaseStability; // The data degradation timer
        int ActiveChapter;    // 0 = Menu, 1 = Chapter One

        // --- Camera Engine Globals (The Dynamic Observer) ---
        float CamPosX;
        float CamPosZ;
        float CamZoom;
    };

    // The declaration: Tells the compiler this memory exists in DePhased_Context.cpp
    extern GameContext GContext; 
}
