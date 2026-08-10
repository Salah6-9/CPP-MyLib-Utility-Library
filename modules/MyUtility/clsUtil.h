#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../MyDate/MyDateOOP/clsDate.h"
using namespace std;

class clsUtil
{
private:
    static string ConvertTensToWords(int num)
    {

        if (num == 0)
        {
            return "";
        }
        static const string units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        static const string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        if (num < 20)
        {
            return units[num];
        }
        else
        {
            string remainder = units[num % 10];
            return tens[num / 10] + (remainder != "" ? " " + remainder : "");
        }
    }
    static string ConvertThreeDigitsToWords(int num)
    {
        if (num <= 99)
        {
            return ConvertTensToWords(num);
        }
        static const string units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

        string remainder = ConvertTensToWords(num % 100);
        return units[num / 100] + " Hundred" + (remainder != "" ? " " + remainder : "");
    }
    static vector<int> SplitNumberIntoGroups(int num)
    {
        vector<int> groups;

        do
        {
            groups.push_back(num % 1000);
            num /= 1000;
        } while (num > 0);

        return groups;
    }
    static string ConvertNumbersToWords(const vector<int> &Numbers)
    {
        string finalResult = "";
        static const vector<string> scaleNames =
            {
                "",
                "Thousand",
                "Million",
                "Billion",
                "Trillion"};
        const size_t size = Numbers.size();
        for (size_t i = 0; i < size; i++)
        {
            if (Numbers[i] != 0)
            {
                finalResult += ConvertThreeDigitsToWords(Numbers[i]);

                size_t index = size - 1 - i;

                if (!scaleNames[index].empty())
                {

                    finalResult += ' ';
                    finalResult += scaleNames[index];
                }
                finalResult += " ";
            }
        }
        return finalResult;
    }

public:
    static void Srand()
    {
        // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }
    enum enCharType
    {
        Small = 1,
        Capital = 2,
        Special = 3,
        Digit = 4,
        MixChars = 5
    };

    static int RandomNum(int from, int to)
    {
        return rand() % (to - from + 1) + from;
    }

    static void Swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    static void Swap(double &a, double &b)
    {
        double temp = a;
        a = b;
        b = temp;
    }

    static void Swap(string &a, string &b)
    {
        string temp = a;
        a = b;
        b = temp;
    }

    static void Swap(clsDate &a, clsDate &b)
    {
        clsDate temp = a;
        a = b;
        b = temp;
    }

    static char GetRandomChar(enCharType type)
    {
        switch (type)
        {
        case Small:
            return char(RandomNum(97, 122));
        case Capital:
            return char(RandomNum(65, 90));
        case Special:
            return char(RandomNum(33, 47));
        case Digit:
            return char(RandomNum(48, 57));
        }
        return '!';
    }

    static string GenerateWord(short length, enCharType type)
    {
        string result = "";
        for (int i = 0; i < length; i++)
            result += GetRandomChar(type);
        return result;
    }

    static string Generatkey(int num = 4, enCharType CharType = enCharType::Capital)
    {
        string Key = "";
        for (int i = 0; i < num; i++)
        {
            Key += GenerateWord(4, CharType) + '-';
        }

        return Key;
    }

    static void FillArrayRendomkeys(int arrLength, string array[], enCharType CharType = enCharType::Capital)
    {
        for (int i = 0; i < arrLength; i++)
            array[i] = Generatkey();
    }
    //=====================================================
    static string NumberToText(int num)
    {
        vector<int> GroupedNumbers = MyVector::ReversVector(SplitNumberIntoGroups(num));
        return ConvertNumbersToWords(GroupedNumbers);
    }
    //======================================================
    static string ColorText(string text, int colorCode)
    {
        switch (colorCode)
        {
        case 1:
            return "\x1b[1;32m" + text + "\x1b[0m"; // Green
        case 2:
            return "\x1b[1;31m" + text + "\x1b[0m"; // Red
        case 3:
            return "\x1b[1;33m" + text + "\x1b[0m"; // Yellow
        default:
            return text;
        }
    }

    static int ClearScreenIfNeeded(bool shouldClear)
    {
        return shouldClear ? system("clear") : 0;
    }

    static void PauseAndClearScreen()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        system("clear");
    }
    template <typename T>
    static void ShuffleArray(int arrLength, T arr[])
    {
        for (int i = 0; i < arrLength; i++)
            Swap(arr[RandomNum(0, arrLength - 1)], arr[RandomNum(0, arrLength - 1)]);
    }
    static void ShuffleArray(int arrLength, int *arr)
    {
        for (int i = 0; i < arrLength; i++)
            Swap(arr[RandomNum(0, arrLength - 1)], arr[RandomNum(0, arrLength - 1)]);
    }

    static void FillArrayRandomNumbers(int arrLength, int *array, int from, int To)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;
        for (int i = 0; i < arrLength; i++)
            array[i] = MyMath::RandomNum(from, To);
    }

    static void FillArrayRendomWord(string array[], int arrLength, enCharType chartype, int wordLen)
    {
        for (int i = 0; i < arrLength; i++)
            array[i] = GenerateWord(wordLen, chartype);
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static string EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i < (int)Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i < (int)Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    // Append..
    inline static const string BLUE = "\033[34m";
    inline static const string MAGENTA = "\033[35m";
    inline static const string CYAN = "\033[36m";
    inline static const string RED = "\x1b[1;31m";
    inline static const string YELLOW = "\x1b[1;33m";
    inline static const string RESET = "\033[0m";
};