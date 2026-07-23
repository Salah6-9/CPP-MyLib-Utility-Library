#pragma once
#include <string>

namespace MySystem
{
    void test();
    std::string ColorText(std::string text, int colorCode);
    int ClearScreenIfNeeded(bool shouldClear);
    void PauseAndClearScreen();
}
