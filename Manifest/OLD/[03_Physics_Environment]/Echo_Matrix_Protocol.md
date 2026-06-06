# Echo Matrix Protocol
**Target:** Acoustic Conductivity & Stealth Logic
**Rule:** An "Echo" is a physical reflection of `AcousticIntensity` against surfaces with high `MaterialConductivity`.

## 1. Kinetic Source Tracking
* **The Generation:** Entities moving with high velocity write an `AcousticIntensity` value into their grid coordinate.
* **The Reflection:** When intensity hits a "Hard Surface," the engine calculates: `Reflected_Intensity = Intensity * MaterialConductivity * Bounce_Coefficient`.

## 2. Stealth & De-Phasing
* **De-Phased Status:** When Young Sir is in the `De-Phased` state, his `AcousticIntensity` output is forced to `0.0f` at the engine level. 
* **Detection Void:** Because he writes zero data into the grid, he becomes physically invisible to both visual-seeking and sound-seeking AI.

## 3. Sensory Synergies
* **AI Reaction:** Enemies poll the `Echo_Matrix` for intensity spikes. A reflected echo off a metal wall can fool an AI into turning toward the reflection point, effectively using level geometry as a distraction.
