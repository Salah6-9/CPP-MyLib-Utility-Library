#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../MyDate/MyDateOOP/clsDate.h"
using namespace std;
clsDate date;

bool IsNumberBetween(int num, int frome, int to)
{
    return ((num > frome) && (num < to));
}

bool IsNumberBetween(double num, double frome, double to)
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

static bool is_Date1EqualDate2(clsDate Date1, clsDate Date2)
{
    return (Date1._year == Date2._year && Date1._month == Date2._month && Date1._day == Date2._day);
}

static bool is_LastDayInMonth(clsDate Date)
{
    return (Date._day == clsDate::DaysInMonth(Date._month, Date._year));
}

static bool is_LastMonthInYear(int month)
{
    return month == 12;
}

static bool is_Date1BeforeDate2(const clsDate &Date1, const clsDate &Date2)
{
    return (Date1._year < Date2._year) ||
           (Date1._year == Date2._year && Date1._month < Date2._month) ||
           (Date1._year == Date2._year &&
            Date1._month == Date2._month &&
            Date1._day < Date2._day);
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

static bool IsValidDate(const clsDate &Date)
{
    if (Date._month < 1 || Date._month > 12)
        return false;
    if (Date._day < 1 || Date._day > DaysInMonth(Date._month, Date._year))
        return false;
    return true;
}

static bool is_Date1EqualDate2(clsDate Date1, clsDate Date2)
{
    return (Date1._year == Date2._year && Date1._month == Date2._month && Date1._day == Date2._day);
}

static bool is_Date1BeforeDate2(const clsDate &Date1, const clsDate &Date2)
{
    return (Date1._year < Date2._year) ||
           (Date1._year == Date2._year && Date1._month < Date2._month) ||
           (Date1._year == Date2._year &&
            Date1._month == Date2._month &&
            Date1._day < Date2._day);
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

double ReadPositiveDoubleNumber(string Message)
{
    double Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

short Read_num_in_range(string output, int from, int to)
{
    int Confirm;
    do
    {
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
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << colum(i + 1);
        for (int j = 0; j < 10; j++)
            cout << (i + 1) * (j + 1) << "\t";
        cout << endl;
    }
}