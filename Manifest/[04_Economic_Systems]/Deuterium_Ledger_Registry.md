# Module: Deuterium Ledger Registry
* **Designation**: Resource Matrix (Economic Systems)
* **Status**: Locked
* **File Hook**: `Game/source/EconomyEngine.cpp`
* **AI Context Vector**: G_GlobalDeuteriumReserve, MarketHysteresis, VoidMultiplier, LightIntensity

---

## 1. ABSTRACT & CONTEXT
Currency in *De-Phased* is not an imaginary fiat; it is the physical ability to burn energy. The system is backed by physical, hoarded Heavy-Water Deuterium Cells (D₂O) controlled by the Pax Aegis Consortium.
* **Lore Integration**: The economy is a physical reflection of world stability. When energy supply is abundant, the Watt is stable; when it is hoarded by the Consortium, the value of the Watt spikes, creating an artificial desperation among the lower strata.

## 2. LOGIC ARCHITECTURE
To maintain performance and simulation depth, the economy uses a decoupled, three-tick delay pipeline. This ensures the CPU is never bottlenecked by economic calculations, while preserving the "alive" feel of a market that reacts to the world state.

## 3. DATA STRUCTURE
* **Registry**: `int64_t g_GlobalDeuteriumReserve` (Watts/W).
* **Buffer Pipeline**: 3-tick circular lag-buffer for standard vendor price updates.
* **Environmental Scalars**: `VoidMultiplier` (float) calculated based on spatial light/dark grid.

## 4. EXECUTION PIPELINE
1. **Global Tick**: The Ledger updates globally once every game hour (3600 seconds).
2. **Purity Harvesting**: The engine calculates the `VoidMultiplier`. If Young Sir harvests Deuterium in negative light (`LightIntensity < 0`), the engine applies a multiplier based on the absolute value of darkness, incentivizing perilous exploration.
3. **Snapshot Update**: Street vendors query the 3-tick lag buffer for pricing, preventing UI thread bottlenecks.
4. **Arbitrage**: Elite black-market traders bypass the buffer, querying the core registry directly for real-time arbitrage.

## 5. RELATIONAL DEPENDENCIES
* **Physics**: Prices fluctuate based on asset values tracked in the `Dynamic_Movement_Matrix` (via `Stratum_Streaming_Matrix`).
* **Factions**: Dictates behavior and price-gouging hooks in `Faction_Relational_Matrix.md`.

## 6. STRICTURES
* All market arithmetic MUST utilize fixed-point math to guarantee ledger consistency.
* Standard vendors are FORBIDDEN from real-time core registry polling; they must use the lag-buffer.
