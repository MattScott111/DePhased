#include "../include/InventoryEngine.h"
#include "../include/EngineCore.h"

namespace DePhased {

    void InventoryEngine::AddItem(uint32_t entityID, uint32_t itemID, int count) {
        float itemWeight = 0.5f; 
        GContext.PayloadWeight[entityID] += (itemWeight * count);
        (void)itemID; // Silence unused warning
    }

    void InventoryEngine::RemoveItem(uint32_t entityID, uint32_t itemID, int count) {
        float itemWeight = 0.5f;
        GContext.PayloadWeight[entityID] -= (itemWeight * count);
        if (GContext.PayloadWeight[entityID] < 0.0f) GContext.PayloadWeight[entityID] = 0.0f;
        (void)itemID; // Silence unused warning
    }

    float InventoryEngine::GetTotalEncumbrance(uint32_t entityID) {
        return GContext.PayloadWeight[entityID];
    }
}
