#ifndef LOADING_WINDOW_H
#define LOADING_WINDOW_H

#include "Chapter.h"

namespace DePhased {
    class LoadingWindow : public IChapter {
    public:
        void Update() override;
        void Draw() override;
    };
}
#endif
