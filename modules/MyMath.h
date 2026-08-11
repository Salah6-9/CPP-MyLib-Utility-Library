#pragma once
#include <string>
#include <vector>

namespace MyMath
{
    enum encheckpeime { prime = 1, notprime = 0 };
    enum encheckperfect { perfect = 1, notperfect = 0 };

    int RandomNum(int from, int to);
    void Swap(int& a, int& b);
    bool IsNum1LessThenNum2(int Num1, int Num2);
    int ReverseDigits(int num);
    bool IsPalindrome(int num);
    encheckpeime checkprime(int n);
    encheckperfect checkperfect(int n);
    void printreversnum(int num);
    int sumofdigit(int num);
    int freqdigit(int num, int dig);
    void printfreqdigit(int num);
    void printprimeforn(int n);
    void printPerfectnum(int n);
    void printPerfectNumbersFrom1ToN(int n);
    void PrintFibonacciSeries(int num);
    void RecPrintFibonacciSeries(int num, int prev1 = 0, int prev2 = 1);
    std::string ConvertTensToWords(int num);
    std::string ConvertThreeDigitsToWords(int num);
    std::vector<int> SplitNumberIntoGroups(int num);
    std::string ConvertNumbersToWords(const std::vector<int> &Numbers);
}
