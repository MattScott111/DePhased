#ifndef CHAPTER_01_H
#define CHAPTER_01_H

#include "../include/Chapter.h"
#include "../include/EngineCore.h"

namespace DePhased {

    class Chapter_01 : public IChapter {
    public:
        Chapter_01() = default;

        void Update() override;
        void Draw() override;

    private:
        void ProcessInput();
    };

}

#endif
