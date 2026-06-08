#pragma once
#include "raylib.h"

namespace DePhased {
    struct Waypoint {
        Vector3 position;
        float duration;
    };

    // Sequence of points for the camera to traverse during the intro
    extern Waypoint introPath[];
    extern int currentWaypoint;
}
