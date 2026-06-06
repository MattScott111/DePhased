# Module: Faction Relational Matrix
* **Designation**: Resource Matrix (Corporate Alliances)
* **Status**: Locked
* **File Hook**: `Game/source/EconomyEngine.cpp`
* **AI Context Vector**: FactionStanding[NUM][NUM], Syndicate_PaxAegis_Alliance

---

## 1. ABSTRACT & CONTEXT
Manages the relational tracking matrix between megacorporations, government wings, and underground sub-factions. 
* **Lore Integration**: The power players are not static. The Pax Aegis Consortium and the Voltaic Syndicate form shaky, corrupt trade pacts, while the AC Radians navigate the underground gaps. Alliances are fragile—one major narrative event can shatter them overnight.

## 2. LOGIC ARCHITECTURE
Using a flat 2D matrix array allows the engine to instantly look up how any faction feels about another in $O(1)$ time complexity. This bypasses bloated branch-checking algorithms and saves critical nanoseconds during world updates.

## 3. DATA STRUCTURE
* **Matrix Array**: `float FactionStanding[NUM_FACTIONS][NUM_FACTIONS]`
* **Dynamic State**: Event-driven flags (e.g., `Syndicate_PaxAegis_Alliance`) that force structural state shifts (e.g., triggering a power plant meltdown forces `Syndicate_PaxAegis_Alliance = false`).

## 4. EXECUTION PIPELINE
1. **Query**: Systems lookup faction sentiment via matrix index.
2. **State Shift**: Narrative events write directly to the matrix, forcing alliance-break logic.
3. **Inventory Swap**: On alliance change, vendors in that sector instantly swap item inventories from standard corporate goods to rare, unmetered underground tech salvage.

## 5. RELATIONAL DEPENDENCIES
* Directly updates pricing calculations handled in `Deuterium_Ledger_Registry.md`.
* Locks or unlocks safehouse territory zone boundaries evaluated by the world loading grids.

## 6. STRICTURES
* Matrix lookups are strictly $O(1)$; complex branch logic in the relation loop is forbidden.
