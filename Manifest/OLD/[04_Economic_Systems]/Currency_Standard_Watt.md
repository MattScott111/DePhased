# Economy & Currency Matrix: The Deuterium Ledger
**Target:** Global Macro-Economy, Market Hysteresis, and Risk-Yield Scaling
**Philosophy:** Money is not an imaginary fiat. It is backed by physical, hoarded Heavy-Water Deuterium Cells (D₂O) controlled by the Pax Aegis Consortium.

## 1. The Base Currency (Watts)
Currency is not an instantiated object; it is a globally tracked `int64_t g_GlobalDeuteriumReserve` (Watts/W). 

## 2. Market Hysteresis (Lag-Buffer Economy)
To prevent economic instability and CPU overhead, the economy utilizes a decoupled 3-tick delay pipeline:
* **The Global Tick:** Ledger updates globally once every game hour (3600 seconds).
* **Street Vendors:** Run on a 3-tick lag buffer to ensure UI updates never bottleneck the main CPU execution thread.
* **Elite Traders:** High-frequency black-market vendors bypass the buffer, querying the core deuterium registry in real-time to adjust pricing functions instantly.

## 3. Purity Harvesting (Risk-Yield Scaling)
The market value of resources is not static; it is mathematically scaled by environmental danger parameters derived from the spatial light/dark grid.
* **Baseline Yield:** Scrap harvested in neutral/lit zones yields standard integer values.
* **The Void Multiplier:** If Young Sir harvests Deuterium while standing in a negative darkness field (`LightIntensity < 0`), the engine applies a multiplier based on the absolute value of the darkness intensity. 
* **The Result:** The darker and more dangerous the environment, the richer the currency yield. This incentivizes perilous exploration purely through mathematics, requiring zero hardcoded quest scripts.

## 4. System Relational Links
* **Physics:** Prices influence asset values tracked in the `Dynamic_Movement_Matrix`.
* **Factions:** Dictates behavior changes in the `Faction_Matrix_Pax_Aegis.md`.
