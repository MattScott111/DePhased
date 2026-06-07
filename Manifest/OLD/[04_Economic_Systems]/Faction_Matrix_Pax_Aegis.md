# System Specification: Faction Matrix & Dynamic Corporate Alliances

## 🔍 System Purpose
Manages the relational tracking matrix between megacorporations, government wings, and underground sub-factions.

## 🌀 Lore & Aesthetic Integration
The power players of this world do not stay static. The Pax Aegis Consortium and the Voltaic Syndicate form shaky, corrupt trade pacts, while the AC Radians navigate the underground gaps. One major event can shatter an alliance overnight.

## ⚙️ Mechanical Specification
*   **The Matrix Array**: Tracked via a fast 2D adjacency matrix array `float FactionStanding[NUM_FACTIONS][NUM_FACTIONS]`.
*   **Story Event Hooks**: Major narrative choices or boss defeats trigger a structural state shift. For example, triggering a power plant meltdown forces `Syndicate_PaxAegis_Alliance = false`.
*   **Dynamic Shop Pools**: When a corporation disbands its alliance with a local sub-faction, the item inventories of vendors in that sector instantly swap from standard corporate goods to rare, unmetered underground tech salvage.

## 🧠 Thought Process & Logic Architecture
Using a flat 2D matrix array allows the engine to instantly look up how any faction feels about another in $O(1)$ time complexity. This completely bypasses the need for bloated branch-checking algorithms and saves critical nanoseconds during world updates.

## ⛓️ Interconnected Dependencies
*   Directly updates pricing calculations handled in **Currency_Standard_Watt.md**.
*   Locks or unlocks safehouse territory zone boundaries evaluated by the world loading grids.

