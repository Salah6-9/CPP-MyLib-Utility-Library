#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include "../MyDate/MyDateOOP/clsDate.h"
using namespace std;

class clsInputValidate
{
public:
    template <typename T>
    static bool IsNumberBetween(T num, T frome, T to)
    {
        return ((num > frome) && (num < to));
    }

    bool IsNum1LessThenNum2(int Num1, int Num2)
    {
        return (Num1 < Num2) ? true : false;
    }
    static bool is_leapYear(int num)
    {
        return (num % 400 == 0) || (num % 4 == 0 && num % 100 != 0);
    }

    static bool is_LastDayInMonth(clsDate Date)
    {
        return (Date.getDay() == clsDate::DaysInMonth(Date.getMonth(), Date.getYear()));
    }

    static bool is_LastMonthInYear(int month)
    {
        return month == 12;
    }

    static bool is_Date1BeforeDate2(const clsDate &Date1, const clsDate &Date2)
    {
        return (Date1.getYear() < Date2.getYear()) ||
               (Date1.getYear() == Date2.getYear() && Date1.getMonth() < Date2.getMonth()) ||
               (Date1.getYear() == Date2.getYear() &&
                Date1.getMonth() == Date2.getMonth() &&
                Date1.getDay() < Date2.getDay());
    }

    static bool is_EndOfWeek(const clsDate &Date)
    {
        return clsDate::GregorianDayOfWeek(Date) == 6;
    }

    static bool IsWeekEnd(const clsDate &Date)
    {
        int dayIndex = clsDate::GregorianDayOfWeek(Date);
        return (dayIndex == 5 || dayIndex == 6);
    }

    static bool IsBusinessDay(const clsDate &Date)
    {
        return !IsWeekEnd(Date);
    }

    static bool IsValidateDate(const clsDate &Date)
    {

        return Date.IsValidDate();
    }

    template <typename T>
    static T ReadPositiveNumber(string Message = "", string errorMsg = "")
    {
        T Number = 0;

        do
        {
            cout << Message;
            cin >> Number;
            // confirm it a number  not a string
            if (cin.fail())
            {
                cout << errorMsg;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (Number <= 0);
        return Number;
    }

    static int ReadPositiveNumber(string Message = "", string errorMsg = "Invalid Input!\n")
    {
        return ReadPositiveNumber<int>(Message, errorMsg);
    }

    static double ReadPositiveDbleNumber(string Message = "", string errorMsg = "")
    {
        return ReadPositiveNumber<double>(Message, errorMsg);
    }

    template <typename T>

    static T Read_num_in_range(T From, T To, string Message = "", string errorMsg = "")
    {
        T Confirm;
        do
        {
            cout << Message;
            cin >> Confirm;
            // confirm it a number  not a string
            if (cin.fail())
            {
                cout << errorMsg;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (Confirm < From || Confirm > To);
        return Confirm;
    }

    // ========== Wrappers للتوافق مع الكود القديم ==========

    static double Read_Dblnum_in_range(string Message = "", string errorMsg = "Out of range!\n", double from = 0, double to = 100)
    {
        return Read_num_in_range<double>(from, to, Message, errorMsg);
    }

    static short Read_num_in_range(int From, int To, string Message = "", string errorMsg = "Out of range!\n")
    {
        return static_cast<short>(Read_num_in_range<int>(From, To, Message, errorMsg));
    }

    static bool Ask_for_continue(string message)
    {
        return Read_num_in_range<int>(0, 1, message) != 0;
    }

    static char GetUserConfirmation(string msg = "...")
    {
        char userChoice;
        do
        {
            cout << msg;
            cin >> userChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (toupper(userChoice) != 'Y' && toupper(userChoice) != 'N');
        return toupper(userChoice);
    }

    static string ReadString(const string &prompt)
    {
        string str;
        cout << prompt;
        cin >> ws;
        getline(cin, str);
        return str;
    }

    static void header()
    {
        for (int i = 1; i <= 10; i++)
            cout << "      " << i << "\t";
        cout << "\n---------------------------------------------------------------------------------------\n";
    }

    static string colum(int i)
    {
        return (i < 10) ? "    | " : "   | ";
    }

    static void multp()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << i + 1 << colum(i + 1);
            for (int j = 0; j < 10; j++)
                cout << (i + 1) * (j + 1) << "\t";
            cout << endl;
        }
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.getYear() == Date2.getYear() && Date1.getMonth() == Date2.getMonth() && Date1.getDay() == Date2.getDay());
    }

    static bool IsDate1BeforThenDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.getYear() < Date2.getYear()) ||
               (Date1.getYear() == Date2.getYear() && Date1.getMonth() < Date2.getMonth()) ||
               (Date1.getYear() == Date2.getYear() && Date1.getMonth() == Date2.getMonth() && Date1.getDay() < Date2.getDay());
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforThenDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
    }
    static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
    {
        return ((IsDate1BeforThenDate2(DateFrom, Date) || IsDate1EqualDate2(DateFrom, Date)) &&
                (IsDate1BeforThenDate2(Date, DateTo) || IsDate1EqualDate2(Date, DateTo)));
    }
};
