#pragma once
#include <string>
#include <vector>

namespace MyString
{
    void PrintFirstLetterOfEachWord(std::string S1);
    std::string UpperFirstLetterOfEachWord(std::string str);
    std::string LowerFirstLetterOfEachWord(std::string str);
    std::string AllLettersToUpper(std::string s);
    std::string AllLettersToLower(std::string s);
    char InvertChar(char c);
    std::string InvertALLChar(std::string s);
    bool is_upper(char c);
    bool is_lower(char c);
    int countLowerLatter(std::string s);
    int countUpperLatter(std::string s);
    int CountLatterInString(std::string s, char c);
    int CountLatterInStringMatchCase(std::string s, char c, bool matchCase = true);
    bool is_Vowles(char Ch1);
    int CountVowles(std::string s);
    void PrintALlVowlesInString(std::string s);
    void PosOfFirstLatterInWord(std::string s, std::vector<int> &PosOfFirstLatterInWord);
    void PrintEachWordInString(std::string s);
    void PrintEachWordInStringver2(std::string S1);
    int CountWordInString(std::string S1);
    std::vector<std::string> SplitEachWordInString(std::string S1, std::string del = " ");
    int FindFirstNonSpaceIndex(const std::string& s);
    int FindLastCharPosition(const std::string& s);
    std::string LeftTrim(const std::string& s);
    std::string RightTrim(const std::string& s);
    std::string TrimSpaces(const std::string& s);
    std::string joinStrings(std::vector<std::string>& vStr, std::string delm = " ");
    std::string joinStrings(std::string arrStr[], int len, std::string delm = " ");
    std::string ReversString(std::string str, std::string delm = " ");
    std::string ReplaceWordString(std::string str, std::string StringToReplace, std::string ReplaceTo, bool MatchCase = 1);
    std::string ReplaceString(std::string str, std::string StringToReplace, std::string ReplaceTo);
    std::string RemovePunctuationsFromString(std::string S1, std::string replace = "");
}
