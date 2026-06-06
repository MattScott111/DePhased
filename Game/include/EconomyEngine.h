#ifndef ECONOMY_ENGINE_H
#define ECONOMY_ENGINE_H

#include <cstdint>

namespace DePhased {
    class EconomyEngine {
    public:
        static void ProcessTransaction(uint32_t entityID, uint32_t itemID, int quantity);
        static float CalculateTotalWeight(uint32_t entityID);
        static void ExecuteHourlyMarketTick(uint32_t entityID, float corporateSabotageModifier);
        static float GetStreetVendorPriceMultiplier(uint32_t entityID);
        static float GetRealTimePriceMultiplier(uint32_t entityID);
    };
}
#endif
