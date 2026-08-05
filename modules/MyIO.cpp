#include "MyIO.h"
#include <iostream>

using namespace std;

namespace MyIO
{
    
    int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do {
            cout << Message;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    double ReadPositiveDoubleNumber(string Message)
    {
        double Number = 0;
        do {
            cout << Message;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    short Read_num_in_range(string output, int from, int to)
    {
        int Confirm;
        do {
            cout << output;
            cin >> Confirm;
        } while (Confirm < from || Confirm > to);
        return Confirm;
    }

    bool Ask_for_continue(string message)
    {
        return Read_num_in_range(message, 0, 1);
    }

    string ReadString(const string &prompt)
    {
        string str;
        cout << prompt;
        cin >> ws;
        getline(cin, str);
        return str;
    }

    void header()
    {
        for (int i = 1; i <= 10; i++)
            cout << "      " << i << "\t";
        cout << "\n---------------------------------------------------------------------------------------\n";
    }

    string colum(int i)
    {
        return (i < 10) ? "    | " : "   | ";
    }

    void multp()
    {
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << colum(i + 1);
            for (int j = 0; j < 10; j++)
                cout << (i + 1) * (j + 1) << "\t";
            cout << endl;
        }
    }
}
