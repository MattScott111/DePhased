#include "../include/IntroCinematic.h"

namespace DePhased {
    Waypoint introPath[] = {
        {{ -10.0f, 5.0f, 0.0f }, 2.0f}, // Start of Pan
        {{ 0.0f, 2.0f, 0.0f }, 3.0f}    // Settle on Workbench
    };
    int currentWaypoint = 0;
}
