# Threat Specification: Unit 17 - Resonance Glitch

## 🔍 System Purpose
Manages the vector inversion parameters and player input restriction states for the orbital orb.

## 🌀 Lore & Aesthetic Integration
A perfect geometric polyhedron made of black, non-reflective material, floating silently in mid-air. Its edges crackle with purple code errors, causing local gravity constants within its proximity to visibly warp and bend out of shape.

## ⚙️ Mechanical Specification
*   **Collision Volume**: Bounding Sphere Dimensions: $Radius = 0.4m$.
*   **Kinetic Mass Profile**: `float Mass = 15.0f`.
*   **Input Inversion Pulse**: Fires an invisible spherical wave. Intersecting this wave swaps the directional input keys inside the movement matrix (`+X` becomes `-X`, and `+Y` becomes `-Y`) for exactly 2.0 seconds.

## 🧠 Thought Process & Logic Architecture
The Glitch operates on a defensive perimeter routine. It hovers at a fixed height of 2 meters above the ground plane, running a radial proximity check every frame to ensure it stays exactly 4 meters away from Young Sir, avoiding close-range combat.

## ⛓️ Interconnected Dependencies
*   Its pulse temporarily disrupts the smooth damping values utilized by the camera engine, causing brief camera lens jittering.

