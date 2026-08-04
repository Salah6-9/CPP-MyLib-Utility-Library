#include "MyString.h"
#include <iostream>
#include <cctype>

using namespace std;

namespace MyString
{
    
    void PrintFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        cout << "\nFirst letters of this string: \n";
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                cout << S1[i] << " ";
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
    }

    string UpperFirstLetterOfEachWord(string str)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                str[i] = toupper(str[i]);
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
        return str;
    }

    string LowerFirstLetterOfEachWord(string str)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                str[i] = tolower(str[i]);
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
        return str;
    }

    string AllLettersToUpper(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = toupper(s[i]);
        }
        return s;
    }

    string AllLettersToLower(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }
        return s;
    }

    char InvertChar(char c)
    {
        return (c == toupper(c) ? tolower(c) : toupper(c));
    }

    string InvertALLChar(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = InvertChar(s[i]);
        }
        return s;
    }

    bool is_upper(char c)
    {
        return (c == toupper(c) ? true : false);
    }

    bool is_lower(char c)
    {
        return (c == tolower(c) ? true : false);
    }

    int countLowerLatter(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (is_lower(s[i]) && s[i] != ' ')
            {
                count++;
            }
        }
        return count;
    }

    int countUpperLatter(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (is_upper(s[i]) && s[i] != ' ')
            {
                count++;
            }
        }
        return count;
    }

    int CountLatterInString(string s, char c)
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

    int CountLatterInStringMatchCase(string s, char c, bool matchCase)
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

    bool is_Vowles(char Ch1)
    {
        Ch1 = tolower(Ch1);
        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }

    int CountVowles(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (is_Vowles(s[i]))
            {
                count++;
            }
        }
        return count;
    }

    void PrintALlVowlesInString(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (is_Vowles(s[i]))
            {
                cout << s[i] << " ";
            }
        }
    }

    void PosOfFirstLatterInWord(string s, vector<int> &PosOfFirstLatterInWord)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && isFirstLetter)
            {
                PosOfFirstLatterInWord.push_back(i);
            }
            isFirstLetter = (s[i] == ' ' ? true : false);
        }
    }

    void PrintEachWordInString(string s)
    {
        vector<int> vPosOfFirstLatterInWord;
        PosOfFirstLatterInWord(s, vPosOfFirstLatterInWord);
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

    void PrintEachWordInStringver2(string S1)
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

    int CountWordInString(string S1)
    {
        bool isFirstLetter = true;
        int count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                count++;
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return count;
    }

    vector<string> SplitEachWordInString(string S1, string del)
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

    int FindFirstNonSpaceIndex(const string& s)
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

    int FindLastCharPosition(const string& s)
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

    string LeftTrim(const string& s)
    {
        int pos = FindFirstNonSpaceIndex(s);

        if (pos != -1)
            return s.substr(pos);

        return "";
    }

    string RightTrim(const string& s)
    {
        int pos = FindLastCharPosition(s);

        if (pos != -1)
            return s.substr(0, pos + 1);

        return "";
    }

    string TrimSpaces(const string& s)
    {
        return RightTrim(LeftTrim(s));
    }

    string joinStrings(vector<string>& vStr, string delm)
    {
        string joindString = "";
        for (string s : vStr)
        {
            joindString = joindString + s + delm;
        }
        return joindString.substr(0, joindString.length() - delm.length());
    }

    string joinStrings(string arrStr[], int len, string delm)
    {
        string joindString = "";
        for (int i = 0; i < len; i++)
        {
            joindString = joindString + arrStr[i] + delm;
        }
        return joindString.substr(0, joindString.length() - delm.length());
    }

    string ReversString(string str, string delm)
    {
        vector<string> vStr = SplitEachWordInString(str);
        string RevString = "";
        for (int i = vStr.size() - 1; i >= 0; i--)
        {
            RevString += vStr[i] + delm;
        }

        return RevString.substr(0, RevString.length() - delm.length());
    }

    string ReplaceWordString(string str, string StringToReplace, string ReplaceTo, bool MatchCase)
    {
        vector<string> vStr = SplitEachWordInString(str);

        for (int i = 0; i < vStr.size(); i++)
        {
            if (MatchCase)
            {
                if (AllLettersToUpper(vStr[i]) == AllLettersToUpper(TrimSpaces(StringToReplace)))
                {
                    vStr[i] = TrimSpaces(ReplaceTo);
                }
            }
            else
            {
                if (vStr[i] == TrimSpaces(StringToReplace))
                {
                    vStr[i] = TrimSpaces(ReplaceTo);
                }
            }
        }

        string NewString = joinStrings(vStr);

        return NewString;
    }

    string ReplaceString(string str, string StringToReplace, string ReplaceTo)
    {
        size_t pos = str.find(StringToReplace);

        while (pos != string::npos)
        {
            str.replace(pos, StringToReplace.length(), ReplaceTo);
            pos = str.find(StringToReplace);
        }

        return str;
    }

    string RemovePunctuationsFromString(string S1, string replace)
    {
        string S2 = replace;
        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }
        return S2;
    }
}
