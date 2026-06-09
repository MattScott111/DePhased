# Threat Specification: Unit 09 - Liquid-Coolant Drone

## 🔍 System Purpose
Defines the thermal aura calculation parameters and passive fatigue debuff fields for the utility orb.

## 🌀 Lore & Aesthetic Integration
A heavily insulated, spherical container drone wrapped in frosted glass tubes. Liquid nitrogen moves through its outer casing, causing a freezing cloud of dense white vapor to trail behind it, forming ice sheets on nearby metal walls.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Sphere Dimensions: $Radius = 0.5m$.
*   **Kinetic Mass Profile**: `float Mass = 40.0f`.
*   **Freezing Aura**: Projects a spherical field vector with a $4.0$-meter radius. Standing inside this field applies an instant $3.0\times$ multiplier to Young Sir’s physical Fatigue accumulation rate.

## 🧠 Thought Process & Logic Architecture
The Coolant Drone operates as a support actor. Its AI logic instructs it to hover within a tight $3.0$-meter radius of other corporate units, acting as a defensive shield that slows down the player's movements during combat encounters.

## ⛓️ Interconnected Dependencies
*   Temporarily overrides regional climate values by reducing the local air temperature variable to freezing.

