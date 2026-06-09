# Low-Level Specification: Index Mapping & Interaction Matrix

## 🔍 System Purpose
Defines the high-performance communication layer between entities, resolving cursor selection projections and container transfers without using string keys or heavy search algorithms.

## ⚙️ Mechanical Specification
*   **Flat Integer Index Mapping**: Every active entity in the sandbox world (Young Sir, Val, a Cyber Locker, or an Aegis Spark-Hound) is stripped of abstract runtime handles and identified strictly by a flat **Integer Array Index ID** ranging from `0` to `MAX_ENTITIES - 1`.
*   **The O(1) Matrix Lookup**:
    *   Young Sir is uniformly mapped to Index `0`.
    *   Target structures are accessed instantly using direct index offsets.
*   **The Zero-Allocation Interaction Buffer**: When opening containers or trading, item data payloads are shifted between arrays using high-speed bitwise memory copying (`std::memcpy`) inside cache-aligned array slots.

## 🧠 Thought Process & Logic Architecture
Using standard dictionary maps or runtime string evaluations (`Map["Locker_01"]`) introduces algorithmic bloat ($O(\log N)$ or $O(1)$ with high hashing overhead) and causes massive memory fragmentation. 

By replacing maps with pure integer indexes, calculating whether Young Sir can open a container reduces down to evaluating the direct spatial position delta between array element `Positions[0]` and array element `Positions[TargetIndex]`. If the distance criteria is valid, the data arrays swap item blocks directly via simple memory offset tracking.

## ⛓️ Interconnected Dependencies
*   Supplies the raw array offset validation math for **[02_Economic_Systems]/Vendor_Interface_Solver.md**.
*   Directly interfaces with the inventory storage blocks managed inside **Layered_Inventory_Matrix.md**.

