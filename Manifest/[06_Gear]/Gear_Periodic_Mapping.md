# Gear & Periodic Table Mapping
**Archetype:** Entity Form (Physical Properties)
**Version:** 1.1.0

Gear is mapped to the Periodic Table to drive "Physical-Acoustic" environmental influences. 

## Properties
- **ElementID (uint32_t):** Maps to Periodic Table index.
- **Physical Influence:** Material density scales `Mass` (Inertia/Knockback).
- **Acoustic Influence:** Elements modulate acoustic frequency, creating specific soundscapes.

## Stat Scaling
- **StatModifier:** Float scalar applied to `MovementSpeed`, `Resonance`, or `Power`.
- **AbilityBitmask:** Gear grants unique ability bits (e.g., "Graphene-Weave" grants `Shielding`).
