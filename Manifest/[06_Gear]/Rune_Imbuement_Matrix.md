# Module: Rune Imbuement Matrix
* **Designation**: Entity Form (SkillVector Injection)
* **Status**: Locked
* **File Hook**: `Game/source/WeaponEngine.cpp`
* **AI Context Vector**: ImbuementBitmask, SkillVectorPointer, ActiveTactics

---

## 1. ABSTRACT & CONTEXT
Runes are "Data-Packets" that inject temporary skill-vectors into the gear. Rather than static stat-increases, runes provide functional tactical advantages (e.g., *Phase-Through-Wall* or *Acoustic-Stun*).
* **Lore Integration**: Runes are shards of high-density logic-code salvaged from ancient, defunct hardware. Using them is a high-stakes modification, as they are inherently unstable.

## 2. LOGIC ARCHITECTURE
Runes are logic-injections. When a rune is applied, the gear's `ActiveTactics` registry bitmask is updated, altering how the weapon interprets input. This allows the gear to perform new actions without creating new classes or objects.

## 3. DATA STRUCTURE
* **Bitmask**: `ImbuementBitmask` (Flags for active perks).
* **Vector**: `SkillVectorPointer` (Accesses the injected logic routine).

## 4. EXECUTION PIPELINE
1. **Probe**: The engine queries proximity for a `RuneEntity`.
2. **Vector Injection**: The rune’s logic routine is bitwise-OR'd into the gear's `ActiveTactics` registry.
3. **Activation**: Gear execution loop incorporates the injected routine alongside base functionality.

## 5. RELATIONAL DEPENDENCIES
* **Narrative**: Achievements are unlocked via `Ghost_Memory_Registry.md` based on rune-usage patterns.

## 6. STRICTURES
* Imbuements must be additive bitmasks; they cannot override or replace core hardware identity.
