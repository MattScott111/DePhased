#include "../include/EconomyEngine.h"
#include "../include/EngineCore.h"
#include <algorithm>

namespace DePhased {

    void EconomyEngine::ProcessTransaction(uint32_t entityID, uint32_t itemID, int quantity) {
        float price = EconomyEngine::GetRealTimePriceMultiplier(entityID);
        float totalCost = price * (float)quantity;
        
        if (GContext.DeuteriumReserve[entityID] >= totalCost) {
            GContext.DeuteriumReserve[entityID] -= totalCost;
        }
        (void)itemID; // Unused parameter
    }

    float EconomyEngine::CalculateTotalWeight(uint32_t entityID) {
        return GContext.PayloadWeight[entityID];
    }

    void EconomyEngine::ExecuteHourlyMarketTick(uint32_t entityID, float corporateSabotageModifier) {
        GContext.LocalMarketInflation[entityID] += corporateSabotageModifier * 0.001f;
        if (GContext.LocalMarketInflation[entityID] > 2.0f) GContext.LocalMarketInflation[entityID] = 2.0f;
        (void)entityID;
    }

    float EconomyEngine::GetStreetVendorPriceMultiplier(uint32_t entityID) {
        (void)entityID;
        return GContext.HistoricalWattPrices[GContext.CurrentTickPointer];
    }

    float EconomyEngine::GetRealTimePriceMultiplier(uint32_t entityID) {
        (void)entityID;
        return GContext.BaseWattValue;
    }

} // End namespace DePhased
