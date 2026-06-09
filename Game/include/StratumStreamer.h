#ifndef STRATUM_STREAMER_H
#define STRATUM_STREAMER_H

#include "Vector3.h"
#include <cstdint>

namespace DePhased {
    class StratumStreamer {
    public:
        static void UpdateStratumContext();
        static void StreamSectorTransition(int targetSlotIndex);
        static Vector3 CalculatePredictiveIntercept(uint32_t entityID, const Vector3& hazardOrigin, float projectileSpeed);
    };
}
#endif
