#include "MyKey.h"
#include "MyMath.h"

using namespace std;

namespace MyKey
{
    char GetRandomChar(enCharType type)
    {
        switch (type) {
            case Small: return char(MyMath::RandomNum(97, 122));
            case Capital: return char(MyMath::RandomNum(65, 90));
            case Special: return char(MyMath::RandomNum(33, 47));
            case Digit: return char(MyMath::RandomNum(48, 57));
        }
        return '!';
    }

    string generateword(short length, enCharType type)
    {
        string result = "";
        for (int i = 0; i < length; i++)
            result += GetRandomChar(type);
        return result;
    }

    string generatkey()
    {
        return generateword(4, Capital) + '-' +
            generateword(4, Capital) + '-' +
            generateword(4, Capital) + '-' +
            generateword(4, Capital);
    }

    void fiilarray_keys(int arrLength, string array[])
    {
        for (int i = 0; i < arrLength; i++)
            array[i] = generatkey();
    }
}
