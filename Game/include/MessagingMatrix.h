#ifndef MESSAGING_MATRIX_H
#define MESSAGING_MATRIX_H

#include "EngineCore.h"

namespace DePhased {
    class MessagingMatrix {
    public:
        // Pushes message to the GContext queue
        static void PushMessage(uint32_t type, uint32_t sender, uint64_t payload) {
            if (GContext.MessageCount < 256) {
                GContext.MessageQueue[GContext.MessageCount++] = {type, sender, payload};
            }
        }

        // Clears queue after Router processes messages
        static void ClearQueue() {
            GContext.MessageCount = 0;
        }
    };
}
#endif
