# De-Phased Code Engineering Manifesto

1.  **Zero-Allocation Main Loop (Hot Path)**: No dynamic memory allocation (`new`, `malloc`) during `Update()`/`Draw()`.
2.  **Data-Oriented Design (DOD)**: Systems are stateless; data resides in `GContext`.
3.  **Namespace Isolation**: All code encapsulated in `namespace DePhased`.
4.  **Pulse-Bus Communication**: Systems interact solely by reading/writing to the `GContext` signal arrays.
5.  **SIMD Alignment**: All structures use `alignas(64)` for cache-line alignment.
