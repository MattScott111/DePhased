# Threat Specification: Primary Boss - The Digital Phantom

## 🔍 System Purpose
Manages the memory state-swapping engine logic for the dual-form final intro encounter.

## 🌀 Lore & Aesthetic Integration
The Phantom is the ultimate glitch in the machine—an ancient wireless energy consciousness that refuses to be chained by Pax Aegis copper lines. It constantly flickers between an ethereal energy state and a brutal, scrap-fused physical nightmare.

## ⚙️ Mechanical Specification

### 🔌 Form 1: Ethereal Spectrum (Phase 1)
*   **State Matrix**: Rendered as an un-collidable, high-frequency particle array container. 
*   **The Frequency Sync Puzzle**: The Phantom’s core cycles its vulnerability frequency `float PhantomFreq` between $10\text{Hz}$ and $60\text{Hz}$ every 4 seconds. Young Sir must hit `[Scroll Wheel]` to tune his hand tool matrix to match, or his resonance blasts pass straight through the entity harmlessly.

### 🛠️ Form 2: Scrapped Goliath (Phase 2)
*   **State Matrix**: Swaps memory allocation states instantly when Form 1 health drops to zero. It executes an assembly algorithm, drawing all local dynamic crates within a $30$-meter matrix cell toward its center coordinate.
*   **Kinetic Mass Profile**: `float Mass = 5000.0f`. It transitions into a heavy-inertia physical entity that smashes the floor plates, forcing the player to continuously monitor their Sphere-Cast footing to prevent slipping into open electrical pits.

## 🧠 Thought Process & Logic Architecture
By utilizing a **State Swapping Pointer Memory Structure**, the engine deletes the lightweight, un-collidable Form 1 logic completely from active CPU cash lines when Phase 2 initializes, spinning up the rigid body physical hull allocation in the exact same memory coordinate space. This guarantees optimal, zero-lag phase transitions.

## ⛓️ Interconnected Dependencies
*   Alters the weather values in **[03_Physics_Environment]/Atmospheric_Weather_Engine.md** by forcing maximum humidity lightning loops during Form 1.
*   Triggers the final intro narrative sequence and unlocks the master story campaign files upon completion.

