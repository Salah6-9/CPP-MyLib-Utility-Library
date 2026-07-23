#include "MySystem.h"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace MySystem
{
    void test()
    {
        cout << "Hello from MyLib!" << endl;
        cout << "Hello from MyLib!" << endl;
        cout << "Hello from MyLib!" << endl;
        cout << "Hello from MyLib!" << endl;
    }

    string ColorText(string text, int colorCode)
    {
        switch (colorCode) {
            case 1: return "\x1b[1;32m" + text + "\x1b[0m"; // Green
            case 2: return "\x1b[1;31m" + text + "\x1b[0m"; // Red
            case 3: return "\x1b[1;33m" + text + "\x1b[0m"; // Yellow
            default: return text;
        }
    }

    int ClearScreenIfNeeded(bool shouldClear)
    {
        return shouldClear ? system("clear") : 0;
    }

    void PauseAndClearScreen()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        system("clear");
    }
}
