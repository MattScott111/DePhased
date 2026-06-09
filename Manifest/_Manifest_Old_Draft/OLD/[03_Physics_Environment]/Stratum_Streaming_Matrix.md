# Engineering Log: Vertical Stratum Fluidity & Barometric Pressure Matrix

## 🔍 System Purpose
Governs seamless vertical world streaming across three distinct height tiers and computes barometric pressure penalties influencing movement and stamina recovery rates.

## 🌀 Lore & Aesthetic Integration
The atmosphere is a crushing, living variable. Descending into the high-pressure depths of subterranean server vaults chokes physical stamina, while ascending into the low-pressure expanse of upper towers frees projectile ranges but stresses pulmonary function. 

## ⚙️ Mechanical Specification
*   **The Three Fluid Strata Zones**:
    *   **The Sky Stratum (`Y > 20.0m`)**: Barometric Pressure = `0.5f` to `0.7f` atm. Air density drops. Falling ordnance (Sky Missiles) gain high velocity profiles due to minimal air resistance. Player stamina recovery slows by 25%.
    *   **The Surface Stratum (`Y` between `0.0m` and `20.0m`)**: Barometric Pressure = `1.0f` atm (Baseline physics engine constants apply).
    *   **The Underground Stratum (`Y < 0.0m`)**: Barometric Pressure = `1.3f` to `2.0f` atm. Dense air drag increases projectile friction penalties by 30%. However, dense air molecules multiply kinetic resonance acoustic waves, boosting player damage vectors by a flat 30%.
*   **Seamless Threshold Bounds**: Traversal drops dynamic loading screens entirely. When `playerBody.position.y` crosses a threshold boundary, the streaming engine shifts memory registers instantly.

## 🧠 Thought Process & Logic Architecture
By making pressure a direct mathematical function of the player's vertical coordinate position ($P = f(Y)$), the engine eliminates the need for expensive volumetric gas calculations. It translates three-dimensional air columns into a fast inline scalar check, optimizing CPU processing overhead down to zero.

## ⛓️ Interconnected Dependencies
*   Injects real-time pressure modifiers directly into **[03_Physics_Environment]/Dynamic_Movement_Matrix.md**.
*   Alters projectile drag constants inside the active weapon and bestiary bullet loops.

