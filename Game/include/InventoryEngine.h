#ifndef INVENTORY_ENGINE_H
#define INVENTORY_ENGINE_H

#include <cstdint>

namespace DePhased {
    class InventoryEngine {
    public:
        // Logic for managing payload weight and item capacity in the registry
        static void AddItem(uint32_t entityID, uint32_t itemID, int count);
        static void RemoveItem(uint32_t entityID, uint32_t itemID, int count);
        static float GetTotalEncumbrance(uint32_t entityID);
    };
}
#endif
