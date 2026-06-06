# Threat Specification: Unit 08 - Heavy Transformer Mech

## 🔍 System Purpose
Governs the ranged combat logic and electrical arc tracking for the corporate heavy walker unit.

## 🌀 Lore & Aesthetic Integration
A bulky, bipedal mechanoid bearing the yellow-and-black chevron markings of the Voltaic Syndicate. Its torso houses a massive, humming oil-cooled capacitor tank that charges two heavy copper arm-prongs protruding from its chassis.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Box Dimensions: $Width = 1.6m, Height = 2.6m, Length = 1.6m$.
*   **Kinetic Mass Profile**: `float Mass = 850.0f`.
*   **Arc Blast**: Fires a continuous tracking beam that links to Young Sir’s position, dealing high energy strain over a 2-second channel time.

## 🧠 Thought Process & Logic Architecture
The Mech tracks the player at a slow rotational speed. If the player circles around the unit rapidly, the Mech's slow yaw rotation rate allows the player to bypass the arm-prongs entirely and strike its unshielded back capacitor plates.

## ⛓️ Interconnected Dependencies
*   Arc fire vectors increase the ambient environmental static charge variables tracked by the climate engine.

