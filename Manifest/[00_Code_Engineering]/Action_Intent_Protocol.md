# Action Intent Protocol

## Meta-Data
- **Archetype:** Logic_Processor
- **Classification:** Engine_Input
- **Status:** Locked
- **Focus:** Input-to-Action mapping via Bitmask

---

## 1. Intent States (Bitmask)
All inputs map to a 32-bit integer. 
* `PHASE_TOGGLE` (0x0001)
* `JUMP_INTENT` (0x0002)
* `RUN_TOGGLE` (0x0004)
* `LOCK_MOVEMENT` (0x0008)
* `DISCOVER_HIGHLIGHT` (0x0010)

## 2. Protocol Logic
The `InputEngine` does not react to keys. It maps keys to the `ActionBitmask`. 
* **Input Buffering:** Actions like `JUMP` and `PHASE` are buffered for 5 frames to prevent input loss.
* **Modal Filtering:** The `ActionBitmask` is filtered by the current `GContext.AppState`. For example, `ATTACK_ACTION` is ignored if `GContext.AppState == STATE_PHASED_SPIRIT` (as the spirit cannot interact physically).
