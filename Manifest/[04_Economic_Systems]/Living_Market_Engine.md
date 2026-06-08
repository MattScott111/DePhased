# Module: Living Market Engine
* **Designation**: Resource Matrix (Economic Systems)
* **Status**: Locked
* **File Hook**: `Game/source/EconomyEngine.cpp`
* **AI Context Vector**: GContext.WattSupply, MarketSnapshot, FactionVolatility, EnergyConstant

---

## 1. ABSTRACT & CONTEXT
The economy of *De-Phased* is a living, corporate-manipulated fiat system. The "Watt" is the universal energy currency, and its value is inextricably linked to the real-time availability of energy in the game world. 
* **Lore Integration**: Currency is not an imaginary fiat. It is backed by physical, hoarded Heavy-Water Deuterium Cells controlled by the Pax Aegis Consortium.

## 2. LOGIC ARCHITECTURE
The market operates on a decoupled 3-tick delay pipeline to prevent economic instability and CPU overhead.
* **The Global Tick**: Ledger updates globally once every game hour (3600 seconds).
* **Street Vendors**: Run on a 3-tick lag buffer to ensure UI updates never bottleneck the main CPU thread.
* **Elite Traders**: Black-market vendors bypass the buffer, querying the core deuterium registry in real-time.

## 3. DATA STRUCTURE
* **Ledger**: `int64_t g_GlobalDeuteriumReserve` (Watts/W).
* **Buffer**: `Market_Snapshot_Buffer` (standard vendor price array).
* **Volatility**: `FactionVolatility` (float adjacency modifier).

## 4. EXECUTION PIPELINE
1. **Constant Evaluation**: Engine calculates base value (`Value = TotalWorldEnergy / TotalWattSupply`).
2. **Faction Injection**: Factions occupying physical power nodes (Physics entities) trigger local supply inflation.
3. **Snapshot Update**: Vendors pull pricing from the `Market_Snapshot_Buffer`.
4. **Arbitrage**: Elite traders pull from the live `GContext` registry.

## 5. RELATIONAL DEPENDENCIES
* **Physics**: Asset values are dynamically linked to `Dynamic_Movement_Matrix` and `Stratum_Streaming_Matrix`.
* **Factions**: Directly alters pricing logic within the `Faction_Relational_Matrix.md`.

## 6. STRICTURES
* Market arithmetic MUST utilize fixed-point math for global consistency.
* Real-time core registry polling for standard vendors is FORBIDDEN.
