
Version 1.1.0
MODULE: DEEP PHASING ARCHITECTURE & DYNAMIC OBSERVER

    "In the physical world, we are bound by mass. In the Phased world, we are unbound by reality, reading the engine's mind and rewriting its rules."

I. STATE ACTUATION & ACCESSIBILITY

The threshold between the physical simulation and the raw data-stream must be accessible, intuitive, and bound to physical risk.

    The Catalyst: Phasing is mapped directly to the Spacebar, executing a flawless, single-cycle bitwise operation (GContext.StateMask[0] ^= 0x2).

    Player Autonomy: The engine will natively support a toggleable setting:

        Sustained Engagement (Hold to Phase): Increases the risk of rapid Data Degradation, demanding tactical precision.

        Tactical Shift (Toggle to Phase): Allows for deliberate, sustained tactical analysis of the environment.

II. THE DYNAMIC OBSERVER (Relational Camera Physics)

The camera is no longer a static, rigid lens. It is a stateless, mathematical observer tethered to Young Sir (Entity 0) by a virtual, physical spring, responding to both mass and psychology.

    Kinetic Weight & Lag: Driven by linear interpolation (Lerp), the camera simulates physical mass. When Young Sir shifts momentum violently, the camera drifts and struggles to catch up, grounding the movement in a heavy reality.

    Relational Magnetism: The Observer actively reads the HostilityArray. Upon detecting a nearby threat, a fractional weight (e.g., 10%) bends the camera's target vector, causing the lens to subtly and naturally drift toward the danger without stealing control from the player.

    Chemical Interference (The Glitch State): If the protagonist suffers toxicity or system glitches, the mathematical spring tension dissolves. Slow, nauseating sine waves are injected into the Pitch and Yaw arrays, forcing the player into a sluggish, disorienting fight for physical control.

III. THE PHASED REALITY (Data-Flow Rendering)

When StateMask 0x2 is triggered, the illusion of the physical world drops. The rendering engine bypasses standard geometry and visually renders the raw GContext arrays.

    Visual Resonance: Young Sir abandons his physical material, rendering as a stark, geometric wireframe of pure intent (neon/yellow). The heavy bunker walls fade into dark, translucent grids, while the AcousticIntensity and LightIntensity arrays violently glow, showing the true shape of the environment's data.

    Orphaned Data (Echoes & Ghosts): The renderer is instructed to draw entities trapped in unallocated memory (ActiveMask == 0). The player bears witness to the frozen, glitching remnants of defeated enemies and historical events.

    Algorithmic Intent: The engine's pathfinding AI (TargetPosX/Z) is unmasked. Glowing vectors project from hostiles to their intended destinations, allowing the player to visually read the engine's logic and outsmart the simulation.

IV. TEMPORAL & KINETIC PHYSICS

Phasing decouples the protagonist from spatial collision, but it also warps the fabric of the simulation's time and physical velocity.

    Data-Flow Time Dilation: Upon phasing, the GlobalDeltaTime is instantly throttled to 0.3f for all entities except Entity 0. The physical world grinds to a heavy crawl, while Young Sir glides through the data-stream at 100% execution speed.

    The Threat of Degradation: Remaining in the data-stream degrades the PhaseStability array. As stability plummets, mathematical noise infects the renderer. Young Sir visually vibrating and tearing into static. If stability reaches zero, the engine forces a violent physical re-entry.

    The Kinetic Snap-Back: De-phasing inside solid mass triggers the EnvironmentEngine to eject Young Sir to the nearest valid coordinate in a single frame. This mathematical spike in infinite velocity is weaponized—dumped straight into the CameraEngine for a violent screen-shake, and into the HostilityArray to stagger nearby threats.

V. LOGICAL MANIPULATION (Hacking the Paradigm)

In the Phased state, physical collision is reduced to 0. You cannot interact with mass, but you possess the ultimate power to manipulate the core data.

    Logic Nodes: Massive, immovable physical barriers (blast doors, inactive synthetics) expose internal, floating "Logic Nodes" in the Phased realm.

    System Rewrite: Young Sir can glide directly inside these nodes to execute an input override. This physically flips the object's StateMask bit—mathematically deleting a locked door's collision value, allowing him to return to the physical world and simply walk right through the breached logic.






Version 1.0.0
- Status:      Implemented (Design Specification)
- Core Logic:  Spatial state-shifting mechanic transcending 3D geometry.
- Mechanism:   Toggling bitmask [0x2] in [GContext.StateMask] , forces 
               an entity transition from the physical plane of interaction to a 
               spectral state. Forces a transition from Physical to Spectral.
- Engine Sync: Triggers [EnvironmentEngine] collision-mask 
               branching; Phased entities bypass narrow-phase 
               collision resolution, allowing traversal through solid geometry 
               as though it were data-flow.

Description:
A hallmark of the De-Phased experience, this spatial state-shifting mechanic transcends standard 3D geometry. By toggling bitmask 0x2 within the central Registry (GContext.StateMask), the entity transitions from the physical plane of interaction to a spectral state. This enables collision-mask branching within the EnvironmentEngine, allowing the protagonist to traverse solid geometry as though it were mere data-flow.
