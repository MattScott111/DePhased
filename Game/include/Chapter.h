#ifndef CHAPTER_H
#define CHAPTER_H

namespace DePhased {
    class IChapter {
    public:
        virtual ~IChapter() = default;
        virtual void Update() = 0;
        virtual void Draw() = 0;
    };
}
#endif
