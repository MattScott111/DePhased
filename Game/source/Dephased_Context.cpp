#include "DePhased_Context.h"

namespace DePhased {
    // THE MASTER ALLOCATION
    // This physically reserves the contiguous block of memory for the entire game.
    // Zero-initialized automatically.
    GameContext GContext = {0}; 
}
