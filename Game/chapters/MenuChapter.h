#ifndef MENU_CHAPTER_H
#define MENU_CHAPTER_H

#include "../include/Chapter.h"
#include <string>
#include <vector>

namespace DePhased {
    class MenuChapter : public IChapter {
    public:
        MenuChapter();
        void Update() override;
        void Draw() override;
        int GetSelectedOption() const { return selectedIndex; }

    private:
        int selectedIndex;
        std::vector<std::string> options;
    };
}
#endif
