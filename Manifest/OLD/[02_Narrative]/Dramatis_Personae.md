# Dramatis Personae: Core Profiles & Trust Mechanics

## 🔍 System Purpose
Manages character data layers, localized dialogue conditions, and progression perks tied to relational states.

## 🌀 Lore & Aesthetic Integration
Relationships in the fringe sectors aren't superficial; they are defensive necessities. In a world monitored closely by Pax Aegis grids, trust is a valuable underground currency.

## ⚙️ Mechanical Specification
*   **The Protagonist: Young Sir**
    *   *Baseline State*: Amnesiac resonance technician. 
    *   *Core Attribute*: Quantum Conduit—capable of channeling high-voltage current waves safely through human biology.
*   **The Technician / Childhood Friend: "Val" (Working Moniker)**
    *   *Baseline State*: Hardware engineer running a local scrap-fuel workshop. Highly independent, fiercely protective, sharp-tongued under pressure.
    *   *Relational Metric*: Tracked via a `float ValTrust` matrix variable (ranging from `0.0` to `1.0`).
*   **The Unlockable Relationship Tier**: 
    *   *Progressive Perks*: Advancing relationship trust stages through moral dialogue alignment awards passive mechanics. At `0.5 Trust` (Unlocking Mutual Security), Val installs a customized copper induction harness in Young Sir’s Tactical Backpack, permanently decreasing physical inventory weight drag variables by 15%.

## 🧠 Thought Process & Logic Architecture
To maximize structural optimization, character profiles exist as fixed memory spaces. Romantic tension, narrative evolution, and stat perks are calculated using simple binary flags and proximity state matrices rather than continuous heavy script calls.

## ⛓️ Interconnected Dependencies
*   Directly triggers narrative unlocks inside **Unlockable_Progression.md**.
*   Alters physical movement weight profiles managed in **[03_Physics_Environment]/Dynamic_Movement_Matrix.md**.

