# Threat Specification: Unit 10 - Shock-Trooper

## 🔍 System Purpose
Manages the rapid positioning routines and plasma burst weapons for the corporate elite mercenary.

## 🌀 Lore & Aesthetic Integration
Voltaic Syndicate elite soldiers clad in lightweight carbon-weave armor suites. Their boots feature micro-thruster plates that allow them to slide horizontally across concrete floors, wielding rapid-fire plasma carbines that blind the camera lens.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Cylinder Volume Dimensions: $Radius = 0.35m, Height = 1.8m$.
*   **Kinetic Mass Profile**: `float Mass = 80.0f`.
*   **The Thruster Dash**: Executes an instantaneous, high-velocity side-step vector ($\vec{v} = \text{SidewaysDirection} \times 18.0\text{ m/s}$) whenever the player aims a resonance attack directly at them.

## 🧠 Thought Process & Logic Architecture
The Shock-Trooper tracks player input states. When it registers an interaction click pointing at its own bounding box, it triggers a probability calculation to instantly execute a thruster dash, forcing the player to predict their movements.

## ⛓️ Interconnected Dependencies
*   Dashes consume a localized energy pool that requires a 4-second cool down period to reset.

