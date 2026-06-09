# Passive Awareness Registry (The AI Detection System)
**Target:** Zero-Allocation Entity Detection
**Rule:** AI does not "think." It polls the sensory registry once per tick to determine alertness.

## 1. The TSAG Accumulator Logic (Temporal-Sensory Awareness Grid)
Instead of states, the AI uses an `uint8_t AlertnessLevel` accumulator that polls sensory intensity:
* **The Polling Trigger:** `Accumulation = (Intensity * AwarenessCoefficient) * AtmosphericMultiplier`.
* **The Decay:** If the player is not sensed, the `AlertnessLevel` decays by the entity's `AwarenessCoefficient`.
* **State Thresholds:**
    * `0-10`: **Neutral** (Patrol behavior).
    * `11-50`: **Suspicious** (Increased polling rate).
    * `51-100`: **Hostile** (Engage/Attack).

## 2. Advanced Detection Logic
* **Trait Coefficients:** Every enemy has an `AwarenessCoefficient`. 
    * *High Awareness (0.9f+):* Multiplies sensory input.
    * *Lazy/Dumb (0.1f):* Filters out noise, ignoring minor sensory spikes.
* **LastKnownCoordinate:** When losing sight of the player, enemies save the last `[X, Y, Z]` coordinate of the spike and rotate their transform toward it to perform a search behavior.
* **Pheromone Drift:** Pheromone values "slide" across grid coordinates based on the `GlobalWindVector`, making enemies downwind significantly more sensitive to the player's presence.
