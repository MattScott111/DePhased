# Messaging Matrix Specification
**Archetype:** Logic Processor (Decoupling Bus)
**Version:** v1.1.0

The Messaging Matrix decouples stateless engines, ensuring the `LobbyEngine`, `InputEngine`, and `Simulation` systems never depend on each other directly.

## Architecture
- **Queue Structure:** `EngineMessage MessageQueue[256]` inside `GContext`.
- **Message Definition:** - `type (uint32_t)`: Intent (e.g., `MSG_NEW_GAME`, `MSG_PHASE_SHIFT`).
  - `sender (uint32_t)`: ID of the dispatching system.
  - `payload (uint64_t)`: Event-specific union data.

## Logic Flow
1. **Dispatcher:** Systems write `EngineMessage` to `GContext.MessageQueue` and increment `MessageCount`.
2. **Orchestrator:** `main.cpp` polls the queue frame-start to resolve state transitions.
3. **Immutability:** Systems propose events; the Orchestrator executes them.
