# State Machine Orchestration

## Concept: The Orchestrator Pattern
The *De-Phased* engine rejects monolithic control structures. Instead, it employs an `ApplicationState` manager within `main.cpp`. This orchestrator maintains the current engine state (`MENU_MAIN`, `OPERATING_ROOM`, `CHAPTER_1`) and an `ActiveChapter*` pointer.

## Implementation Principles
- **Delegation**: `main.cpp` is prohibited from executing gameplay logic. It acts as the high-frequency loop orchestrator that invokes the `Update()` and `Draw()` interface methods of the currently active chapter.
- **Cold Boot Transitions**: State switches are handled by a `State_Switch(NEW_STATE)` call. This triggers a `BootGrid()` memory clear to ensure the engine remains "boundless" by purging stale world-data before injecting new level blueprints.
- **Data Handover**: Transitions occur via instantaneous pointer swaps and deterministic data injection, ensuring zero overhead between setup and active gameplay.
