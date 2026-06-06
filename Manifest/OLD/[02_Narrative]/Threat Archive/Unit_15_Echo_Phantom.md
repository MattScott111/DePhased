# Threat Specification: Unit 15 - Echo Phantom

## 🔍 System Purpose
Controls the decoy allocation system and cursor projection redirection logic for the phantom entity.

## 🌀 Lore & Aesthetic Integration
An eerie digital apparition that splits into multiple translucent, green-tinted visual mirages. It mimics the movement patterns of a human survivor, luring outcasts into dead-end alleyways before overloading their neural links.

## ⚙️ Mechanical Specification
*   **Collision Volume**: 3 Dynamic Bounding Volumes (1 Authentic, 2 Decoys).
*   **Kinetic Mass Profile**: `float Mass = 10.0f`.
*   **The Mirage Split**: Upon taking an initial hit, the entity instantiates two identical clone data profiles at temporary coordinate offsets. Clones deal zero damage and dissolve cleanly when clicked.

## 🧠 Thought Process & Logic Architecture
To save system memory, the decoys share the exact same asset texture pointer as the parent entity. They run no independent tracking logic; they simply copy and mirror the raw velocity inputs of the primary authentic unit.

## ⛓️ Interconnected Dependencies
*   Successfully identifying and destroying the authentic core drops rare neural data shards into the progression database.

