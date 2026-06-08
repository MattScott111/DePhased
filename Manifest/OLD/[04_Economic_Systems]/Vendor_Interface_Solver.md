# Engineering Log: Contextual Proximity & Cursor Raycast Solver

## 🔍 System Purpose
Solves the problem of accurate object and container selection when the camera perspective is zoomed far out or detached.

## ⚙️ Mechanical Specification
*   **The Proximity Constraint Ring**: Surrounds Young Sir with a hard mathematical radius constraint of `2.0` meters. Entities outside this perimeter cannot be interacted with.
*   **Screen-to-World Projection**: When the player clicks an item on screen, the engine shoots a single mathematical ray from the screen coordinates into the 3D world matrix space.
*   **The Selection Logic**:
    ```cpp
    if (Ray.Intersects(CyberLocker) && Distance(YoungSir, CyberLocker) <= 2.0f) {
        OpenLockerInterface();
    }
    ```
*   **The Split-UI Interface**: Opening a valid locker activates a dual-panel inventory grid. Items remain static; the player can hit `[R]` to execute a "Take All" data buffer transfer or click specific items to manually pull them into pockets or the tactical backpack.

## 🧠 Thought Process & Logic Architecture
By verifying the 2-meter physical proximity constraint *before* running any heavy intersection algorithms, we eliminate unnecessary mathematical work. If a locker is too far away, the engine rejects the interaction instantly, maintaining high cache-efficiency.

## ⛓️ Interconnected Dependencies
*   Passes item transaction data streams directly into **Layered_Inventory_Matrix.md**.
*   Requires real-time coordinate tracking inputs from **Dynamic_Camera_Observer.md**.

