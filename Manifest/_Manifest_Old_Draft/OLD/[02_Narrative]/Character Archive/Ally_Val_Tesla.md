# Character Dossier: Valerie "Val" Tesla

## 🔍 System Purpose
Defines the relational tracking matrix, behavioral responses, and mechanics tied to Young Sir's core engineer ally and romance option.

## 🌀 Lore & Aesthetic Integration
Valerie is the legacy holder of the wireless resonance movement. She is rarely seen without her heavy canvas work coat, its inner lining hand-woven with raw copper threading to deflect corporate grid sweeps. Her attitude is sharp, direct, and unyielding—a defensive shield built to protect both her hidden underground workshop and the fragile, amnesiac mind of Young Sir.

## ⚙️ Mechanical Specification
*   **Unique Identifier**: `NPC_VAL_01`.
*   **Relational Variable**: `float ValTrust` (Initialized at `0.15f`).
*   **Proximity Hook**: When Young Sir enters her immediate 2-meter proximity cell, her state transitions to `Safe_Zone_Active = true`, which accelerates Young Sir’s passive stamina recovery coefficient by $1.5\times$.
*   **The Trust Threshold Reward**: 
    ```cpp
    if (ValTrust >= 0.50f && !BackpackUpgradeUnlocked) {
        TotalPayloadWeightModifier = 0.85f; // Cuts backpack weight drag by 15%
        BackpackUpgradeUnlocked = true;
    }
    ```

## 🧠 Thought Process & Logic Architecture
By isolating Val's relationship tracking to a single data structure, her presence acts as a localized environmental buff card. The engine only reads her active status when Young Sir is physically inside the workshop node, entirely eliminating global script processing costs during exploration.

