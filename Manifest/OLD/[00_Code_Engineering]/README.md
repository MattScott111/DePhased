# Project Manifest: DE-PHASED (v1.0.0-Stable)
> **Data-Oriented, High-Velocity 3D Hybrid RPG Architecture for Linux Mint OS**
> **Portability Target**: 100% Compliant Standard ISO C++20
> *"Universal Current, Eternal Peace... is a lie wrapped in copper wire."*

---

## 🧭 Welcoming New Team Members (The Onboarding Roadmap)
Welcome to the team! If you are a designer, writer, or engineer who just cloned this repository, do not panic. This project is built completely differently from commercial engines like Unreal or Unity. 

You are no longer building bloated "Objects." You are managing the flow of **pure, raw data**. 
We do not use abstract visual editors or heavy inheritance trees. Everything in this game—from a character's romantic tension index to a sky-missile's trajectory vector—is treated as pure, high-speed mathematical data packed inside centralized, parameterless structural matrices.

### 🏃 Your 3-Step Quickstart & Coding Rules
1.  **Pass Data in its Rawest Form**: We do not pass complex objects between systems. We pass primitive integers, floats, and bitmasks. 
2.  **Zero-Allocation Rule**: We do not use the `new` or `delete` keywords anywhere inside active game frame loops. All objects, item counts, and level terrains are pre-allocated into flat, sequential memory blocks on boot.
3.  **No Dynamic Parameter Passing**: If you add a new feature to an asset, you *never* change function signatures (e.g., writing `Update(Player, Fatigue, Wind)` is strictly banned). Systems pull data automatically behind the scenes by querying the `GlobalContext` ether.

---

## 🏛️ The 7 Pillars of Architecture (Master Engineering Manifesto)
For the system engineers who understand cache hierarchies and hardware assembly limits, here are the absolute bare-metal rules of the De-Phased engine:

1. **The "Holy" Engine Rule**: The core engine is a pure mathematical simulator. We strictly reject boilerplate code and OOP bloat. The engine just crunches numbers seamlessly.
2. **Nanosecond Optimization**: We optimize for the CPU cache line using strict Data-Oriented Design (DOD). Entities are flat, contiguous arrays.
3. **Optimal Resource Stewardship**: By keeping the memory footprint incredibly tight and bypassing heavy algorithms, we leave maximum CPU overhead available for massive entity counts.
4. **Authentic, Emergent Mechanics**: Mechanics must emerge naturally from the physics engine (e.g., impact damage = $\text{Mass} \times \text{Velocity}$). Mechanics feel authentic because they *are* mathematically authentic.
5. **Seamless Integration**: The environment is divided into parallel memory streaming pages. The player must never see a loading screen once the simulation begins.
6. **The Universal Port**: All game logic is sealed inside `namespace DePhased`. The graphics hook is completely decoupled, making future ports to Windows, Mac, or Consoles trivial.
7. **Data-Driven Instantiation**: An "Object" is simply a synchronized row across our data arrays. We create NPCs and enemies by injecting raw data templates into active memory indices.

---

## ⚡ Technical Briefing for Engine Vets (The Low-Level Spec Sheet)
Here is the bare-metal layout of the C++ binary implementation driving the 7 Pillars:

### 1. Cache Alignment & Structure of Arrays (SoA)
We reject classic Object-Oriented design patterns (`std::vector<Entity*>`). Such arrays fragment data across the RAM heap, inducing continuous CPU cache line misses and virtual table (`vtable`) pointer jumps. Instead, components are split into flat, parallel, cache-aligned structural arrays:

```text
[ CONTINUOUS 64-BYTE CHIP-LEVEL CACHE LINES ]
Positions Array:  [x0,y0,z0][x1,y1,z1][x2,y2,z2]... (Sequential prefetch)
Velocities Array: [v0,v0,v0][v1,v1,v1][v2,v2,v2]...
Mass Registry:    [  m0  ]  [  m1  ]  [  m2  ]  ...
A single hardware read pipeline pulls up to 16 consecutive float attributes into L1/L2 caches simultaneously. Math sequences utilize Semi-Implicit Euler Integration to maintain strict mechanical energy conservation properties over varying frame durations.2. Multi-Sector Slotted Memory PagesTo enable screen-door loading zones with zero runtime heap allocation overhead, the game data pool splits memory into 3 simultaneous, fixed parallel level pages:C++const int SECTOR_CAPACITY = 500;
const int MAX_STREAMED_SECTORS = 3; // Slot 0: Sky, Slot 1: Surface, Slot 2: Underground
RigidBody physicsObjects[MAX_STREAMED_SECTORS][SECTOR_CAPACITY];
Crossing vertical or horizontal level boundaries simply shifts an integer pointer state (activeSectorSlot), immediately swapping the active level tracking layers in a sub-nanosecond interval.3. Bit-Mask Registries & AI Performance CullingNeural Link Unlocks: Achievements, trophies, and story quest markers are packed into a single, high-speed 64-bit primitive integer register (uint64_t g_AchievementMask). Querying or writing states compiles down to single-cycle bitwise hardware operations (& and |=).Visibility Cull Masks: Entities carry a tracking bit-mask vector. If an asset sits in an unrendered vertical slot layer, its mask flips to 0. The AI finite state machines drop calculations for that actor instantly, saving critical cycles by skipping line-of-sight raycasts and pathfinding code arrays entirely.Predictive Spatial Intercepts: Cross-stratum vertical hazards read the player's vector inputs directly from memory row 0, executing basic linear projectile prediction math ($\vec{x}_{\text{intercept}} = \vec{x}_{\text{player}} + \vec{v}_{\text{player}} \cdot t_{\text{travel}}$) to lead targets into sharp, low-traction drift matrices.🌡️ Barometric Matrix FormulaVertical coordinate data points ($Y$) calculate localized atmospheric pressure equations instantly without volumetric fluid gas computing loops:Sky Stratum ($Y > 20m$): $P = 0.5\text{atm} \rightarrow 0.7\text{atm}$. Low drag; fast projectiles; player energy recovery drops 25%.Underground Stratum ($Y < 0m$): $P = 1.3\text{atm} \rightarrow 2.0\text{atm}$. High fluid air density; 30% projectile drag penalty; acoustic resonance wave propagation multiplies kinetic combat vectors by $+30\%$.
