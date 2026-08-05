
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
class clsString 
{

private:
    string _Value;

public:
    clsString()
    {

        _Value = "";
    }

    clsString(string Value)
    {

        _Value = Value;
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    void print(string msg = "")
    {
    
        cout << msg;
        
        cout << _Value<<endl;
    }
    void PrintFirstLetterOfEachWord ()
    {
        PrintFirstLetterOfEachWord(_Value);
    }
    static void PrintFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        cout << "\nFirst letters of this string: \n";
        for (size_t i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                cout << S1[i] << " ";
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
    }

    clsString& UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
        return *this;
    }
    static string UpperFirstLetterOfEachWord(string str)
    {
        bool isFirstLetter = true;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                str[i] = toupper(str[i]);
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
        return str;
    }

    clsString& LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
        return *this;
    }
    static string LowerFirstLetterOfEachWord(string str)
    {
        bool isFirstLetter = true;
        for (size_t  i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                str[i] = tolower(str[i]);
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
        return str;
    }

    clsString& AllLettersToUpper()
    {
        _Value = AllLettersToUpper(_Value);
        return *this;
    }
    static string AllLettersToUpper(string s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            s[i] = toupper(s[i]);
        }
        return s;
    }

    clsString& AllLettersToLower()
    {
        _Value = AllLettersToLower(_Value);
        return *this;
    }
    static string AllLettersToLower(string s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }
        return s;
    }

    static char InvertChar(char c)
    {
        return (c == toupper(c) ? tolower(c) : toupper(c));
    }

    clsString& InvertAllChars()
    {
        _Value = InvertAllChars(_Value);
        return *this;
    }
    static string InvertAllChars(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = InvertChar(s[i]);
        }
        return s;
    }

    static bool is_upper(char c)
    {
        return (c == toupper(c) ? true : false);
    }

    static bool is_lower(char c)
    {
        return (c == tolower(c) ? true : false);
    }

    int countLowerLetters(){
        
        return countLowerLetters(_Value);
    }
    static int countLowerLetters(string s)
    {
        int count = 0;
        for (size_t  i = 0; i < s.size(); i++)
        {
            if (is_lower(s[i]) && s[i] != ' ')
            {
                count++;
            }
        }
        return count;
    }

    int countUpperLetters()
    {
        return countUpperLetters(_Value);
    }
    static int countUpperLetters(string s)
    {
        int count = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (is_upper(s[i]) && s[i] != ' ')
            {
                count++;
            }
        }
        return count;
    }

    int CountCharacterInString(char c)
    {
        return CountCharacterInString(_Value, c);
    }
    static int CountCharacterInString(string s, char c)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                count++;
            }
        }
        return count;
    }

    int CountCharacterInStringMatchCase(char c, bool matchCase)
    {
        return CountCharacterInStringMatchCase(_Value, c, matchCase);
    }
    static int CountCharacterInStringMatchCase(string s, char c, bool matchCase)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (matchCase)
            {
                if (s[i] == c)
                {
                    count++;
                }
            }
            else
            {
                if (tolower(s[i]) == tolower(c))
                {
                    count++;
                }
            }
        }
        return count;
    }


    static bool is_Vowels(char Ch1)
    {
        Ch1 = tolower(Ch1);
        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }

    int CountVowels()
    {
        return CountVowels(_Value);
    }
    static int CountVowels(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (is_Vowels(s[i]))
            {
                count++;
            }
        }
        return count;
    }

    void PrintALlVowelsInString()
    {
        PrintALlVowelsInString(_Value);
    }
    static void PrintALlVowelsInString(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (is_Vowels(s[i]))
            {
                cout << s[i] << " ";
            }
        }
    }

    void PosOfFirstLetterInWord(vector<int> &PosFirstLatterInWord)
    {
        PosOfFirstLetterInWord(_Value, PosFirstLatterInWord);
    }
    static void PosOfFirstLetterInWord(string s, vector<int> &PosFirstLatterInWord)
    {
        bool isFirstLetter = true;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && isFirstLetter)
            {
                PosFirstLatterInWord.push_back(i);
            }
            isFirstLetter = (s[i] == ' ' ? true : false);
        }
    }

    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value);
    }
    static void PrintEachWordInString(string s)
    {
        vector<int> vPosOfFirstLatterInWord;
        PosOfFirstLetterInWord(s, vPosOfFirstLatterInWord);
        string word = "";
        for (int i = 0; i < vPosOfFirstLatterInWord.size(); i++)
        {
            int l = vPosOfFirstLatterInWord[i];
            while (l < s.size() && s[l] != ' ')
            {
                word += s[l];
                l++;
            }
            cout << word << endl;
            word = "";
        }
    }

    void PrintEachWordInStringver2()
    {
        PrintEachWordInStringver2(_Value);
    }
    static void PrintEachWordInStringver2(string S1)
    {
        string delim = " ";
        cout << "\nYour string wrords are: \n\n";
        short pos = 0;
        string sWord;
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                cout << sWord << endl;
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            cout << S1 << endl;
        }
    }

    int CountWordInString()
    {
        return CountWordInString(_Value);
    }
    static int CountWordInString(string S1)
    {
        bool isFirstLetter = true;
        int count = 0;
        for (size_t i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                count++;
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return count;
    }

    vector<string> SplitEachWordInString(string delm)
    {
        return SplitEachWordInString(_Value, delm);
    }
    static vector<string> SplitEachWordInString(string S1, string del)
    {
        vector<string> SplitString;
        string delim = del;
        short pos = 0;
        string sWord;
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                SplitString.push_back(sWord);
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            SplitString.push_back(S1);
        }
        return SplitString;
    }

    int FindFirstNonSpaceIndex()
    {
        return FindFirstNonSpaceIndex(_Value);
    }
    static int FindFirstNonSpaceIndex(const string& s)
    {
        if (s.empty())
            return -1;

        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] != ' ')
                return i;
        }

        return -1;
    }

    int FindLastCharPosition()
    {
        return FindLastCharPosition(_Value);
    }
    static int FindLastCharPosition(const string& s)
    {
        if (s.empty())
            return -1;

        for (int i = (int)s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
                return i;
        }

        return -1;
    }

    clsString& LeftTrim()
    {
        _Value = LeftTrim(_Value);
        return *this;
    }
    static string LeftTrim(const string& s)
    {
        int pos = FindFirstNonSpaceIndex(s);

        if (pos != -1)
            return s.substr(pos);

        return "";
    }

    clsString& RightTrim()
    {
        _Value = RightTrim(_Value);
        return *this;
    }
    static string RightTrim(const string& s)
    {
        int pos = FindLastCharPosition(s);

        if (pos != -1)
            return s.substr(0, pos + 1);

        return "";
    }

    clsString& TrimSpaces()
    {
        _Value = TrimSpaces(_Value);
        return *this;
    }
    static string TrimSpaces(const string& s)
    {
        return RightTrim(LeftTrim(s));
    }

    static string joinStrings(vector<string>& vStr, string delm=" ")
    {
        string joindString = "";
        for (string s : vStr)
        {
            joindString = joindString + s + delm;
        }
        return joindString.substr(0, joindString.length() - delm.length());
    }

    clsString& ReversString(string delm=" ")
    {
        _Value = ReversString(_Value, delm);
        return *this;
    }
    static string ReversString(string str, string delm)
    {
        vector<string> vStr = SplitEachWordInString(str, delm);
        
        if (vStr.empty()) return "";
        string RevString = "";
        for (int i = vStr.size() - 1; i >= 0; i--)
        {
            RevString += vStr[i] + delm;
        }

        return RevString.substr(0, RevString.length() - delm.length());
    }

    clsString& ReplaceWordString(string StringToReplace, string ReplaceTo, bool MatchCase)
    {
        _Value = ReplaceWordString(_Value, StringToReplace, ReplaceTo, MatchCase);
        return *this;
    }
    static string ReplaceWordString(string str, string StringToReplace, string ReplaceTo, bool MatchCase)
    {
        vector<string> vStr = SplitEachWordInString(str," ");

        for (int i = 0; i < vStr.size(); i++)
        {
            if (MatchCase)
            {
                if (vStr[i] == TrimSpaces(StringToReplace))
                {
                    vStr[i] = TrimSpaces(ReplaceTo);
                }
            }
            else
            {
                if (AllLettersToUpper(vStr[i]) == AllLettersToUpper(TrimSpaces(StringToReplace)))
                {
                    vStr[i] = TrimSpaces(ReplaceTo);
                }
            }
        }

        string NewString = joinStrings(vStr);

        return NewString;
    }
    
    clsString& ReplaceString(string StringToReplace, string ReplaceTo)
    {
        _Value = ReplaceString(_Value, StringToReplace, ReplaceTo);
        return *this;
    }
    static string ReplaceString(string str, string StringToReplace, string ReplaceTo)
    {
        size_t pos = str.find(StringToReplace);

        while (pos != string::npos)
        {
            str.replace(pos, StringToReplace.length(), ReplaceTo);
            pos = str.find(StringToReplace);
        }

        return str;
    }

    clsString& RemovePunctuationsFromString(string replace="")
    {
        _Value= RemovePunctuationsFromString(_Value, replace);
        return *this;
    }
    static string RemovePunctuationsFromString(string S1, string replace)
    {
        string S2 = "";
        for (char c : S1   )
        {
            if (!ispunct(c ))
            {
                S2 += c;
            }else
            {
                S2 += replace;
            }
        }
        return S2;
    }


};
