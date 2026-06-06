#ifndef CHAPTER_01_H
#define CHAPTER_01_H

#include "../include/Chapter.h"
#include "../include/Vector3.h"

namespace DePhased {

    class Chapter_01 : public IChapter {
    public:
        Chapter_01();
        void Update() override;
        void Draw() override;
        
    private:
        void InitializeWorld();
        float timeElapsed;
    };

} // End namespace DePhased

#endif
