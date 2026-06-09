#include "../include/EconomyEngine.h"
#include "../include/EngineCore.h"
#include <algorithm>

namespace DePhased {

    void EconomyEngine::ProcessTransaction(uint32_t entityID, uint32_t itemID, int quantity) {
        float price = EconomyEngine::GetRealTimePriceMultiplier(entityID);
        float totalCost = price * (float)quantity;

        // Corrected: Accessing GContext.SaveData
        if (GContext.SaveData.DeuteriumReserve[entityID] >= totalCost) {
            GContext.SaveData.DeuteriumReserve[entityID] -= totalCost;
        }
        (void)itemID;
    }

    float EconomyEngine::CalculateTotalWeight(uint32_t entityID) {
        // Corrected: Accessing GContext.SaveData
        return GContext.SaveData.PayloadWeight[entityID];
    }

    void EconomyEngine::ExecuteHourlyMarketTick(uint32_t entityID, float corporateSabotageModifier) {
        // Corrected: Accessing GContext.SaveData
        GContext.SaveData.LocalMarketInflation[entityID] += corporateSabotageModifier * 0.001f;
        if (GContext.SaveData.LocalMarketInflation[entityID] > 2.0f)
            GContext.SaveData.LocalMarketInflation[entityID] = 2.0f;
        (void)entityID;
    }

    float EconomyEngine::GetStreetVendorPriceMultiplier(uint32_t entityID) {
        (void)entityID;
        // Corrected: Accessing GContext.SaveData
        return GContext.SaveData.HistoricalWattPrices[GContext.SaveData.CurrentTickPointer];
    }

    float EconomyEngine::GetRealTimePriceMultiplier(uint32_t entityID) {
        (void)entityID;
        // Corrected: Accessing GContext.SaveData
        return GContext.SaveData.BaseWattValue;
    }

} // End namespace DePhased
