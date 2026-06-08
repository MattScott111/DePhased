# Module: Ghost Memory Registry
* **Designation**: Entity Form (History Registry)
* **Status**: Locked
* **File Hook**: `Game/source/ProgressionEngine.cpp`
* **AI Context Vector**: UsageHistory, StoryAffinity, KillCount

---

## 1. ABSTRACT & CONTEXT
Gear carries history. Every action performed with a specific piece of gear is written to its `UsageHistory`. This registry tracks the "ghost" data of the gear’s life.
* **Lore Integration**: A weapon that has participated in the destruction of ten *Null-Specters* doesn't just get "better"; it becomes "attuned" to those signatures, unlocking unique tactics for that specific frequency.

## 2. LOGIC ARCHITECTURE
We use a circular-buffered history bitmask to track recent events. The `AchievementEngine` periodically scans this history to trigger perks or achievement flags when thresholds are met.

## 3. DATA STRUCTURE
* **UsageHistory**: 256-action circular bitmask.
* **StoryAffinity**: Bit-packed narrative-tag register.

## 4. EXECUTION PIPELINE
1. **Event Logging**: Every interaction (kill, phase-shift, environment interaction) pushes an event tag to `UsageHistory`.
2. **Recognition**: The `AchievementEngine` reads this history to unlock buffs (e.g., *Specter Slayer*).
3. **Write-Protection**: Story-critical events mark specific gear indices as "Indestructible" within the `GContext`.

## 5. RELATIONAL DEPENDENCIES
* **Progression**: Feeds achievement state to `[01_Interface_Design]/HUD_Telemetry_Registry.md`.
* **Narrative**: Directly interacts with `Dramatis_Personae.md` event triggers.

## 6. STRICTURES
* History tracking must be circular-buffered to maintain a constant, minimal memory footprint.
