# Threat Specification: Unit 07 - Ripper Drone

## 🔍 System Purpose
Defines the movement constraints and high-frequency collision logic for the blade-mounted airborne drone.

## 🌀 Lore & Aesthetic Integration
A jagged, triangular drone spinning on an off-center axis, kept aloft by three high-speed whining rotors. A circular diamond saw blade projects from its base, screaming loudly as it slices through loose pipes and airborne debris.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Sphere Dimensions: $Radius = 0.4m$.
*   **Kinetic Mass Profile**: `float Mass = 18.0f`.
*   **Continuous Saw Harm**: Applies a multi-hitting contact damage function every $0.1$ seconds for as long as its collision box overlaps the player's volume.

## 🧠 Thought Process & Logic Architecture
The drone uses an erratic sin-wave algorithm to calculate its flight path, causing it to bob up and down aggressively. This erratic pathing makes it difficult to hit with the cursor projection while it closes the distance.

## ⛓️ Interconnected Dependencies
*   Its high rotor speed generates a micro-air-current vector that slightly alters local dust or rain trajectories.

