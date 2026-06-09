# Inventory Engine Specification
**Archetype:** Resource Matrix
**Version:** v1.0.0

The Inventory system operates as a fixed-length memory pool within the `GContext.SaveData` struct. It utilizes a zero-allocation approach to manage items, weights, and currency (Deuterium).

## Data Schema
- **Slots:** Fixed-size array `uint32_t InventorySlots[MAX_ENTITIES][MAX_ITEMS_PER_ENTITY]` storing unique item IDs.
- **Weights:** Contiguous `float PayloadWeight[MAX_ENTITIES]` for physics-based encumbrance calculations.
- **Deuterium:** `float DeuteriumReserve[MAX_ENTITIES]` for real-time transactional logic.

## Functional Logic
- **`AddItem(entityID, itemID)`:** Checks the `PayloadWeight` threshold before adding to `InventorySlots`.
- **`RemoveItem(entityID, itemID)`:** Shifts array elements to maintain contiguous memory (no null gaps).
- **Encumbrance:** The `MovementEngine` polls `PayloadWeight` to scale `BaseMoveSpeed`.
