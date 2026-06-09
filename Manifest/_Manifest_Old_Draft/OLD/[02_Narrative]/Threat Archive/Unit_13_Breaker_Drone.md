# Threat Specification: Unit 13 - Breaker Drone

## 🔍 System Purpose
Defines the suicide tracking velocity and localized EMP blast footprint for the volatile payload orb.

## 🌀 Lore & Aesthetic Integration
A small, unstable flying sphere containing a pulsing, raw deuterium core. It has no weapons armor; it is a cheap, mass-produced corporate asset designed to overload underground grids by intentionally sacrificing its own chassis.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Sphere Dimensions: $Radius = 0.25m$.
*   **Kinetic Mass Profile**: `float Mass = 8.0f`.
*   **The EMP Overload**: Upon contact with the player's capsule, the drone deletes itself, generating a spherical shockwave that zeroes out Young Sir’s active stamina pool and darkens all nearby light fixtures.

## 🧠 Thought Process & Logic Architecture
The drone uses an aggressive intercept algorithm, calculating the shortest straight-line vector to the player's head coordinate. It possesses a high acceleration modifier, making it critical to intercept with rapid attacks before it gets too close.

## ⛓️ Interconnected Dependencies
*   The detonation instantly clears out any nearby airborne **Unit_14_Static_Wraith.md** anomalies due to the intense electromagnetic disruption.

