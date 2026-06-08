# Engineering Log: Layered Inventory Allocations & Mass Constraints

## 🔍 System Purpose
Manages character carry space, stack behaviors, and item physical weight variables.

## 🌀 Lore & Aesthetic Integration
Young Sir is a practical technician. He does not have an abstract, infinite magical inventory pocket. He possesses a highly grounded, physical set of quick-access work pockets for immediate consumables and a heavy tactical backpack for scrap metal transformers and core components.

## ⚙️ Mechanical Specification
*   **The Quick Pockets (Fixed Array)**: A simple 4-slot sequential array for instant-use consumables (e.g., nutrition bars, hydrators). Bound directly to hotkeys `1` through `4` to bypass the inventory screen.
*   **The Tactical Backpack (Grid Matrix)**: A continuous $5 \times 5$ memory grid matrix. Items carry an integer block footprint (e.g., a standard battery occupies 1 slot, while a heavy copper transformer blocks a $2 \times 2$ grid space).
*   **The Mass Accumulator**: Every item holds a `float ItemWeight` value. The inventory system totals these values every frame into a single variable: `float TotalPayloadWeight`.

## 🧠 Thought Process & Logic Architecture
We deliberately reject dynamic, linked-list memory allocation for item slots to prevent memory fragmentation and slow read times. The entire inventory exists as a fixed, continuous block of cache-aligned memory, allowing instantaneous lookup times.

## ⛓️ Interconnected Dependencies
*   Feeds `TotalPayloadWeight` directly into **Dynamic_Movement_Matrix.md** to scale down the acceleration and traction traction modifiers when heavily encumbered.
*   Receives physical item arrays directly from interactions resolved in **Vendor_Interface_Solver.md**.

