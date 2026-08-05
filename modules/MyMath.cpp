#include "MyMath.h"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace MyMath
{   
    int RandomNum(int from, int to)
    {
        return rand() % (to - from + 1) + from;
    }

    void Swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    bool IsNumberBetween(int num ,int frome,int to){
        return ((num > frome) && (num <to));
    }
    bool IsNum1LessThenNum2(int Num1, int Num2)
    {
        return (Num1 < Num2) ? true : false;
    }

    int ReverseDigits(int num)
    {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    bool IsPalindrome(int num)
    {
        return num == ReverseDigits(num);
    }

    encheckpeime checkprime(int n)
    {
        if (n <= 1) return notprime;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return notprime;
        return prime;
    }

    encheckperfect checkperfect(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n / 2; i++)
            if (n % i == 0) sum += i;
        return (sum == n) ? perfect : notperfect;
    }

    void printreversnum(int num)
    {
        while (num != 0) {
            cout << num % 10 << endl;
            num /= 10;
        }
    }

    int sumofdigit(int num)
    {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int freqdigit(int num, int dig)
    {
        int count = 0;
        while (num > 0) {
            if (dig == num % 10) count++;
            num /= 10;
        }
        return count;
    }

    void printfreqdigit(int num)
    {
        while (num > 0) {
            cout << num % 10 << endl;
            num /= 10;
        }
    }

    void printprimeforn(int n)
    {
        cout << "The prime numbers from 1 to " << n << ":\n";
        for (int i = 1; i <= n; i++)
            if (checkprime(i) == prime) cout << i << endl;
    }

    void printPerfectnum(int n)
    {
        if (checkperfect(n) == perfect)
            cout << n << " is a perfect number.\n";
        else
            cout << n << " is not a perfect number.\n";
    }

    void printPerfectNumbersFrom1ToN(int n)
    {
        for (int i = 1; i <= n; i++)
            if (checkperfect(i) == perfect)
                cout << i << endl;
    }

    void PrintFibonacciSeries(int num)
    {
        int prev1 = 0, prev2 = 1, temp = 0;
        for (int i = 0; i < num; i++)
        {
            temp = prev2;
            cout << prev2 << " ";
            prev2 = prev2 + prev1;
            prev1 = temp;
        }
    }

    void RecPrintFibonacciSeries(int num, int prev1, int prev2)
    {
        if (num > 0)
        {
            int temp = prev2;
            cout << prev2 << " ";
            prev2 = prev2 + prev1;
            prev1 = temp;
            RecPrintFibonacciSeries(num - 1, prev1, prev2);
        }
    }

    string ConvertTensToWords(int num)
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

    string ConvertThreeDigitsToWords(int num)
    {
        if (num <= 99)
        {
            return ConvertTensToWords(num);
        }
        static const string units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

        string remainder = ConvertTensToWords(num % 100);
        return units[num / 100] + " Hundred" + (remainder != "" ? " " + remainder : "");
    }

    vector<int> SplitNumberIntoGroups(int num)
    {
        vector<int> groups;

        do
        {
            groups.push_back(num % 1000);
            num /= 1000;
        } while (num > 0);

        return groups;
    }

    string TranslateNumbersToWords(const vector<int> &Numbers)
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
}
