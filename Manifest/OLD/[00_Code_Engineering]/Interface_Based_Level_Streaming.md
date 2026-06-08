# Interface Based Level Streaming

## Concept: Polymorphic Chapter Decoupling
To ensure infinite scalability, every game chapter must implement the `IChapter` interface. 

## Architectural Mandate
- **Interface Definitions**: The engine does not need to know the internal logic of any specific chapter. It only recognizes the `Update()` and `Draw()` contract.
- **Scalability**: New chapters can be added as standalone files within the `chapters/` directory without requiring modifications to the engine core or `main.cpp`.
- **Minimalism**: This decoupling keeps the binary footprint small and the execution path predictable, adhering to the "Seven Pillars" of *De-Phased* engineering.
