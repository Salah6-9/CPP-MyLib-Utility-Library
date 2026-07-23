#include "MyVector.h"
#include <iostream>

using namespace std;

namespace MyVector
{
    void readVector(vector<string>& vec)
    {
        char v = 'Y';
        string temp;
        do
        {
            cout << "enter the text : ";
            cin >> temp;
            cout << "do you want to enter a value : ";
            cin >> v;
            vec.push_back(temp);
        }
        while (v == 'Y' || v == 'y');
    }

    string VectorToString(vector<string> vStr)
    {
        string Str;
        for (string s : vStr)
        {
            Str += s + " ";
        }
        return Str;
    }

    void PrintVector(vector<string>& vec)
    {
        for (const string &s : vec)
        {
            cout << s << endl;
        }
    }

    void PrintVector(vector<int>& vec)
    {
        for (const int &s : vec)
        {
            cout << s << endl;
        }
    }

    vector<int> ReversVector(const vector<int>& numbers)
    {
        int size = numbers.size();
        vector<int> temp;
        for (int i = size - 1; i >= 0; i--)
        {
            temp.push_back(numbers[i]);
        }
        return temp;
    }
}
