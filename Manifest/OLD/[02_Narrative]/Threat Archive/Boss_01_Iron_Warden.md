# Threat Specification: Gatekeeper 01 - The Iron Warden

## 🔍 System Purpose
Outlines the phase parameters and heavy spatial matrix calculations for the Sector 0 Outpost progression barrier.

## 🌀 Lore & Aesthetic Integration
A massive, bipedal mechanical goliath coated in thick, black ceramic armor tiles. It serves as Pax Aegis's ultimate urban pacification machine. Its steps cause structural dust to fall, shaking the screen to communicate immense physical gravity.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Capsule Volume Dimensions: $Radius = 1.5m, Height = 4.0m$.
*   **Kinetic Mass Profile**: `float Mass = 2500.0f` (Extremely heavy; completely immune to standard player momentum knockback vectors).
*   **Grounding Logic Vulnerability**: The unit maintains a hard `IsGrounded = true` status. Young Sir cannot damage its hull directly until he uses his induction device to trigger an environmental blast on the floor plates, breaking the Warden's local Sphere-Cast tracking and forcing a 3-second stun state.

## 🧠 Thought Process & Logic Architecture
To prevent frame rate drops during boss encounters, the Iron Warden's collision logic uses an exclusive, localized spatial partitioning cell. It ignores minor environmental ambient objects, updating its sweeping arm attack vector matrix only when the player enters its immediate $5.0$-meter combat quadrant.

## ⛓️ Interconnected Dependencies
*   Defeating this unit switches the globally saved bit-flag `GATEKEEPER_01_DOWN = true` inside **Unlockable_Progression.md**.
*   Its heavy ground stomps apply direct, temporary vector displacement pulses to dynamic physics boxes.

