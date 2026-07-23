#pragma once
#include <string>

namespace MyKey
{
    enum enCharType { Small = 1, Capital = 2, Special = 3, Digit = 4 };

    char GetRandomChar(enCharType type);
    std::string generateword(short length, enCharType type);
    std::string generatkey();
    void fiilarray_keys(int arrLength, std::string array[]);
}
