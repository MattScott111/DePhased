# Module: Gear Matrix Registry
* **Designation**: Entity Form (Master Index)
* **Status**: Locked
* **File Hook**: `Game/source/WeaponEngine.cpp`
* **AI Context Vector**: GearStateWord, ModuleCount, ModuleRegistryPointer

---

## 1. ABSTRACT & CONTEXT
The Master Registry for all gear-related data. In *De-Phased*, gear is not an object; it is a **Data Modification Vector**. It defines the interface through which the protagonist interacts with the world’s physics. 

## 2. LOGIC ARCHITECTURE
The registry uses a flat index-based look-up system. By avoiding object-oriented "Gear" classes and instead utilizing a global `ModuleRegistryPointer`, we allow the engine to dynamically inject module logic as function pointers or bitmask-logic into the gear's execution loop at runtime.

## 3. DATA STRUCTURE
* **Registry**: `GearStateWord` (64-bit bit-pack containing rank, status, and affinity).
* **Module Slots**: `uint8_t moduleCount`, `uint32_t moduleStartIdx`.
* **Registry SoA**: Contiguous `GearModules` Struct-of-Arrays (SoA) to maintain cache-line efficiency.

## 4. EXECUTION PIPELINE
1. **Registry Lookup**: Engine performs $O(1)$ lookup for the gear entity.
2. **Module Injection**: Module logic is streamed into the weapon’s execution tick based on the `ModuleRegistryPointer`.
3. **State Sync**: The gear’s registry is updated, reflecting any rank, module, or status changes.

## 5. RELATIONAL DEPENDENCIES
* **Physics**: Directly interfaces with the `Spatial_Event_Broadcaster` to propagate wave events (Acoustics/Pressure).
* **Progression**: Linked to `[05_Entity_Blueprints]/Character_Actor_Matrix.md` for equip-validation.

## 6. STRICTURES
* No pointer-hopping allowed; all module access must use `uint32_t` index offsets.
* Gear Registry must be atomic during the update cycle.
