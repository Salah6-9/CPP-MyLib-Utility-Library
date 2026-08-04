#pragma once
#pragma warning(disable : 4996)
#include "../../../MyLib.h"
#include "../../MyString/MyStringOOP/clsString.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <string>

class clsDate
{
private:
    short _day;
    short _month;
    short _year;

public:
    clsDate()
    {
        clsDate Date = GetRealTime();
        _day = Date._day;
        _month = Date._month;
        _year = Date._year;
    }

    clsDate(string Date)
    {
        vector<string> vDate = clsString::SplitEachWordInString(Date, "/");
        if (vDate.size() == 3)
        {
            _day = stoi(vDate[0]);
            _month = stoi(vDate[1]);
            _year = stoi(vDate[2]);
        }
        else
        {
            clsDate now = GetRealTime();
            _day = now._day;
            _month = now._month;
            _year = now._year;
        }
    }

    clsDate(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }

    clsDate(int days, int year)
    {
        clsDate Date = GetDateFromDayOrderInYear(days, year);
        _day = Date._day;
        _month = Date._month;
        _year = Date._year;
    }
    void setDay(short day) { _day = day; }
    void setMonth(short month) { _month = month; }
    void setYear(short year) { _year = year; }
    short getDay() { return _day; }
    short getMonth() { return _month; }
    short getYear() { return _year; }

    void print(string msg = "")
    {
        cout << msg << DateToString() << endl;
    }

    static clsDate GetRealTime()
    {
        time_t t = time(NULL);
        tm *now = localtime(&t);
        if (now == nullptr)
        {
            return clsDate(0, 0, 0);
        }
        return clsDate(static_cast<short>(now->tm_mday),
                       static_cast<short>(now->tm_mon + 1),
                       static_cast<short>(now->tm_year + 1900));
    }

    bool is_leapYear()
    {
        return is_leapYear(_year);
    }
    static bool is_leapYear(int num)
    {
        return (num % 400 == 0) || (num % 4 == 0 && num % 100 != 0);
    }

    int DaysInMonth()
    {
        return DaysInMonth(_month, _year);
    }
    static int DaysInMonth(short Month, short Year)
    {
        static const int arrNumberOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2) ? (is_leapYear(Year) ? 29 : 28) : arrNumberOfDays[Month];
    }

    static clsDate GetDateFromDayOrderInYear(int DaysAdded, int year)
    {
        int i = 0;
        clsDate Date(0, 0, 0);
        int DaysINMonth = DaysInMonth(i + 1, year);

        while (DaysAdded > DaysINMonth)
        {
            if (DaysAdded <= 0)
                return clsDate(0, 0, 0);
            DaysAdded = DaysAdded - DaysINMonth;

            i++;
            if (i >= 12)
            {
                i = 0;
                year++;
            }
            DaysINMonth = DaysInMonth(i + 1, year);
        }
        Date._day = DaysAdded;
        Date._month = i + 1;
        Date._year = year;
        return Date;
    }

    int dGregoianCalendar()
    {
        return dGregoianCalendar(_day, _month, _year);
    }
    static int dGregoianCalendar(short day, short month, short year)
    {
        int a = (14 - month) / 12,
            y = year - a,
            m = month + 12 * a - 2;

        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    string MonthName()
    {
        return MonthName(_month);
    }
    static string MonthName(short month)
    {
        static const string Month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return Month[month - 1];
    }

    void PrintMonthCalendar()
    {
        return PrintMonthCalendar(_month, _year);
    }
    static void PrintMonthCalendar(short month, short year)
    {
        static const string Days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        short startDay = dGregoianCalendar(1, month, year),
              maxDays = DaysInMonth(month, year);
        cout << "_______________" << MonthName(month) << "_______________\n";

        for (int i = 0; i < 7; i++)
        {
            cout << setw(5) << Days[i];
        }
        cout << endl;
        for (int i = 0; i < startDay; i++)
        {
            cout << setw(5) << "";
        }
        int currentColumn = startDay;
        for (int i = 1; i <= maxDays; i++)
        {
            if (currentColumn == 7)
            {
                currentColumn = 0;
                cout << endl;
            }
            currentColumn++;
            cout << setw(5) << i;
        }
    }

    void PrintYearCalendar()
    {
        return PrintYearCalendar(_year);
    }
    static void PrintYearCalendar(short year)
    {
        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, year);
            cout << endl;
        }
    }

    static int MinHourToSecMin(int MinHour)
    {
        return MinHour * 60;
    }

    static int HoureInDay(int day)
    {
        return day * 24;
    }

    int DaysInYear()
    {
        return DaysInYear(_year);
    }
    static int DaysInYear(int year)
    {
        return (is_leapYear(year)) ? 366 : 365;
    }

    void DisplayYearDetails()
    {
        return DisplayYearDetails(_year);
    }
    static void DisplayYearDetails(int year)
    {
        int days = DaysInYear(year),
            Hour = HoureInDay(days),
            Min = MinHourToSecMin(Hour),
            Sec = MinHourToSecMin(Min);

        cout << "Number Of Days in Year [" << year << "] is " << days << endl;
        cout << "Number Of Hours in Year [" << year << "] is " << Hour << endl;
        cout << "Number Of Minutes in Year [" << year << "] is " << Min << endl;
        cout << "Number Of Second in Year [" << year << "] is " << Sec << endl;
    }

    void DisplayMonthDetails()
    {
        return DisplayMonthDetails(_month, _year);
    }
    static void DisplayMonthDetails(short Month, short year)
    {
        int days = DaysInMonth(Month, year),
            Hour = HoureInDay(days),
            Min = MinHourToSecMin(Hour),
            Sec = MinHourToSecMin(Min);

        cout << "Number Of Days    in Month [" << Month << "] is " << days << endl;
        cout << "Number Of Hours   in Month [" << Month << "] is " << Hour << endl;
        cout << "Number Of Minutes in Month [" << Month << "] is " << Min << endl;
        cout << "Number Of Second  in Month [" << Month << "] is " << Sec << endl;
    }

    string DayName()
    {
        return DayName(dGregoianCalendar(_day, _month, _year));
    }
    static string DayName(short d)
    {
        static const string Days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return Days[d];
    }

    void PrintDayNameOfWeek()
    {
        return PrintDayNameOfWeek(_day, _month, _year);
    }
    static void PrintDayNameOfWeek(short day, short month, short year)
    {
        int dayOrder = dGregoianCalendar(day, month, year);
        cout << "Date   : " << day << "/" << month << "/" << year << endl;
        cout << "Day Order : " << dayOrder << endl;
        cout << "Day Name : " << DayName(dayOrder) << endl;
    }

    short CalculateDaysSinceStartOfYear()
    {
        return CalculateDaysSinceStartOfYear(_day, _month, _year);
    }
    static short CalculateDaysSinceStartOfYear(short day, short month, short year)
    {
        short sum = 0, i;
        for (i = 0; i < month - 1; i++)
        {
            sum += DaysInMonth(i + 1, year);
        }
        return sum += day;
    }

    clsDate AddDaysToDate(int daysToAdd)
    {
        *this = AddDaysToDate(_day, _month, _year, daysToAdd);
        return *this;
    }
    static clsDate AddDaysToDate(short day, short month, short year, int daysToAdd)
    {
        if (daysToAdd < 0)
        {
            clsDate temp(day, month, year);
            return DecreaseDateByXDay(temp, -daysToAdd);
        }
        clsDate Date(0, 0, 0);
        while (daysToAdd > 0)
        {
            int daysInMonth = DaysInMonth(month, year);
            int remainingDays = daysInMonth - day;

            if (daysToAdd <= remainingDays)
            {
                day += daysToAdd;
                daysToAdd = 0;
            }
            else
            {
                daysToAdd -= (remainingDays + 1);
                day = 1;
                month++;

                if (month > 12)
                {
                    month = 1;
                    year++;
                }
            }
        }

        Date._day = day;
        Date._month = month;
        Date._year = year;

        return Date;
    }

    clsDate AddDaysToDateFromBeginingOfYear(int DateToAdd)
    {
        return AddDaysToDateFromBeginingOfYear(*this, DateToAdd);
    }
    static clsDate AddDaysToDateFromBeginingOfYear(clsDate Date, int DateToAdd)
    {
        int totaldates = CalculateDaysSinceStartOfYear(Date._day, Date._month, Date._year) + DateToAdd;
        return GetDateFromDayOrderInYear(totaldates, Date._year);
    }

    clsDate ReadFullDate()
    {
        return ReadFullDate("Enter full date:");
    }
    clsDate ReadFullDate(string title)
    {
        clsDate Date;
        cout << "\n"
             << title;
        Date._year = MyIO::ReadPositiveNumber("\nEnter a year : ");
        Date._month = MyIO::Read_num_in_range("Enter a Month Number [1 to 12]: ", 1, 12);
        short maxDays = DaysInMonth(Date._month, Date._year);
        string dayPrompt = "Enter a Day Number [1 to " + to_string(maxDays) + "]: ";
        Date._day = MyIO::Read_num_in_range(dayPrompt, 1, maxDays);
        return Date;
    }

    bool is_Date1EqualDate2(clsDate Date2)
    {
        return is_Date1EqualDate2(*this, Date2);
    }
    static bool is_Date1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._year == Date2._year && Date1._month == Date2._month && Date1._day == Date2._day);
    }

    bool is_LastDayInMonth()
    {
        return is_LastDayInMonth(*this);
    }
    static bool is_LastDayInMonth(clsDate Date)
    {
        return (Date._day == DaysInMonth(Date._month, Date._year));
    }

    bool is_LastMonthInYear()
    {
        return is_LastMonthInYear(_month);
    }
    static bool is_LastMonthInYear(int month)
    {
        return month == 12;
    }

    clsDate IncreaseDateByOneDay()
    {
        *this = IncreaseDateByOneDay(*this);
        return *this;
    }
    static clsDate IncreaseDateByOneDay(clsDate Date)
    {
        if (is_LastDayInMonth(Date))
        {
            if (is_LastMonthInYear(Date._month))
            {
                Date._day = 1;
                Date._month = 1;
                Date._year++;
            }
            else
            {
                Date._day = 1;
                Date._month++;
            }
        }
        else
        {
            Date._day++;
        }

        return Date;
    }

    int DiffInDaysVer2(clsDate Date2, bool EndDay)
    {
        return DiffInDaysVer2(*this, Date2, EndDay);
    }
    static int DiffInDaysVer2(clsDate Date1, clsDate Date2, bool EndDay)
    {
        int TotalDiffDays = 0;

        if (!is_Date1BeforeDate2(Date1, Date2))
        {
            clsDate temp = Date1;
            Date1 = Date2;
            Date2 = temp;
        }

        while (Date2._year - Date1._year > 1)
        {
            TotalDiffDays += DaysInYear(Date1._year);
            Date1._year++;
        }

        while (Date1._year < Date2._year || Date1._month < Date2._month)
        {
            TotalDiffDays += DaysInMonth(Date1._month, Date1._year);
            Date1._month++;

            if (Date1._month > 12)
            {
                Date1._month = 1;
                Date1._year++;
            }
        }

        TotalDiffDays += (Date2._day - Date1._day);

        return EndDay ? TotalDiffDays + 1 : TotalDiffDays;
    }

    void swapDate(clsDate &Date2)
    {
        swapDate(*this, Date2);
    }
    static void swapDate(clsDate &Date1, clsDate &Date2)
    {
        clsDate temp = Date1;
        Date1 = Date2;
        Date2 = temp;
    }

    int DiffInDays(clsDate Date2, bool EndDay)
    {
        return DiffInDays(*this, Date2, EndDay);
    }
    static int DiffInDays(clsDate Date1, clsDate Date2, bool EndDay)
    {
        int DaysDiff = 0;
        short SwapFlag = 1;
        if (!is_Date1BeforeDate2(Date1, Date2))
        {
            swapDate(Date1, Date2);
            SwapFlag = -1;
        }
        while (is_Date1BeforeDate2(Date1, Date2))
        {
            DaysDiff++;
            Date1 = IncreaseDateByOneDay(Date1);
        }

        return (EndDay) ? (DaysDiff + 1) * SwapFlag : DaysDiff * SwapFlag;
    }

    static int AgeInDays(clsDate BirhDate)
    {
        clsDate NowDate = GetRealTime();
        return DiffInDays(BirhDate, NowDate, true);
    }

    string DateToString()
    {
        return DateToString(*this);
    }
    static string DateToString(const clsDate &Date)
    {
        return to_string(Date._day) + "/" +
               to_string(Date._month) + "/" +
               to_string(Date._year);
    }

    bool is_Date1BeforeDate2(clsDate Date2)
    {
        return is_Date1BeforeDate2(*this, Date2);
    }
    static bool is_Date1BeforeDate2(const clsDate &Date1, const clsDate &Date2)
    {
        return (Date1._year < Date2._year) ||
               (Date1._year == Date2._year && Date1._month < Date2._month) ||
               (Date1._year == Date2._year &&
                Date1._month == Date2._month &&
                Date1._day < Date2._day);
    }

    int GregorianDayOfWeek()
    {
        return GregorianDayOfWeek(*this);
    }
    static int GregorianDayOfWeek(const clsDate &Date)
    {
        int a = (14 - Date._month) / 12;
        int y = Date._year - a;
        int m = Date._month + (12 * a) - 2;

        return (Date._day + y + (y / 4) - (y / 100) +
                (y / 400) + ((31 * m) / 12)) %
               7;
    }

    bool is_EndOfWeek()
    {
        return is_EndOfWeek(*this);
    }
    static bool is_EndOfWeek(const clsDate &Date)
    {
        return GregorianDayOfWeek(Date) == 6;
    }

    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }
    static bool IsWeekEnd(const clsDate &Date)
    {
        int dayIndex = GregorianDayOfWeek(Date);
        return (dayIndex == 5 || dayIndex == 6);
    }

    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }
    static bool IsBusinessDay(const clsDate &Date)
    {
        return !IsWeekEnd(Date);
    }

    int DaysUntilEndOfWeek()
    {
        return DaysUntilEndOfWeek(*this);
    }
    static int DaysUntilEndOfWeek(const clsDate &Date)
    {
        return 6 - GregorianDayOfWeek(Date);
    }

    int DaysUntilEndOfMonth()
    {
        return DaysUntilEndOfMonth(*this);
    }
    static int DaysUntilEndOfMonth(const clsDate &Date)
    {
        return (DaysInMonth(Date._month, Date._year) - Date._day) + 1;
    }

    clsDate EndOfYear()
    {
        return EndOfYear(*this);
    }
    static clsDate EndOfYear(clsDate Date)
    {
        Date._day = 31;
        Date._month = 12;
        return Date;
    }

    int DaysUntilEndOfYear()
    {
        return DaysUntilEndOfYear(*this);
    }
    static int DaysUntilEndOfYear(const clsDate &Date)
    {
        return DiffInDays(Date, EndOfYear(Date), true);
    }

    int CalculateVacationDays(clsDate DateTo)
    {
        return CalculateVacationDays(*this, DateTo);
    }
    static int CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        int Days = 0;
        while (is_Date1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return Days;
    }

    clsDate CalculateVacationDate(int VactionDays)
    {
        return CalculateVacationDate(*this, VactionDays);
    }
    static clsDate CalculateVacationDate(clsDate DateFrom, int VactionDays)
    {
        while (VactionDays > 0)
        {
            if (IsBusinessDay(DateFrom))
                VactionDays--;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DateFrom;
    }

    bool IsValidDate()
    {
        return IsValidDate(*this);
    }
    static bool IsValidDate(const clsDate &Date)
    {
        if (Date._month < 1 || Date._month > 12)
            return false;
        if (Date._day < 1 || Date._day > DaysInMonth(Date._month, Date._year))
            return false;
        return true;
    }

    clsDate DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
        return *this;
    }
    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date._day > 1)
        {
            Date._day--;
        }
        else
        {
            if (Date._month > 1)
            {
                Date._month--;
                Date._day = DaysInMonth(Date._month, Date._year);
            }
            else
            {
                Date._month = 12;
                Date._year--;
                Date._day = 31;
            }
        }
        return Date;
    }

    bool is_FirstDayInMonth()
    {
        return is_FirstDayInMonth(_day);
    }
    static bool is_FirstDayInMonth(int Day)
    {
        return (Day == 1);
    }

    bool is_FirstMonthInYear()
    {
        return is_FirstMonthInYear(_month);
    }
    static bool is_FirstMonthInYear(int month)
    {
        return month == 1;
    }

    static int WeekToDays(int Week)
    {
        return Week * 7;
    }
    clsDate DecreaseDateByXDay(int X = 1)
    {
        *this = DecreaseDateByXDay(*this, X);
        return *this;
    }
    static clsDate DecreaseDateByXDay(clsDate Date, int X = 1)
    {
        clsDate NewDate = Date;
        for (int i = 0; i < X; i++)
        {
            NewDate = DecreaseDateByOneDay(NewDate);
        }
        return NewDate;
    }

    clsDate DecreaseDateByOneAndXWeek(int X = 1)
    {
        *this = DecreaseDateByOneAndXWeek(*this, X);
        return *this;
    }
    static clsDate DecreaseDateByOneAndXWeek(clsDate Date, int X = 1)
    {
        for (int i = 0; i < X; i++)
        {

            Date = DecreaseDateByXDay(Date, 7);
        }
        return Date;
    }

    clsDate DecreaseDateByOneMonth()
    {
        *this = DecreaseDateByOneMonth(*this);
        return *this;
    }
    static clsDate DecreaseDateByOneMonth(clsDate Date)
    {
        if (is_FirstMonthInYear(Date._month))
        {
            Date._month = 12;
            Date._year--;
        }
        else
        {
            Date._month--;
        }
        short maxDaysInNewMonth = DaysInMonth(Date._month, Date._year);
        if (Date._day > maxDaysInNewMonth)
            Date._day = maxDaysInNewMonth;

        return Date;
    }

    clsDate DecreaseDateByOneAndXMonth(int X = 1)
    {
        *this = DecreaseDateByOneAndXMonth(*this, X);
        return *this;
    }
    static clsDate DecreaseDateByOneAndXMonth(clsDate Date, int X = 1)
    {
        for (int i = 0; i < X; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    clsDate DecreaseDateByOneYear()
    {
        *this = DecreaseDateByOneYear(*this);
        return *this;
    }
    static clsDate DecreaseDateByOneYear(clsDate Date)
    {
        Date._year--;
        return Date;
    }

    clsDate DecreaseDateByXYears(short Years)
    {
        *this = DecreaseDateByXYears(*this, Years);
        return *this;
    }
    static clsDate DecreaseDateByXYears(clsDate Date, short Years)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    clsDate DecreaseDateByOneAndXYearFaster(int X = 1)
    {
        *this = DecreaseDateByOneAndXYearFaster(*this, X);
        return *this;
    }
    static clsDate DecreaseDateByOneAndXYearFaster(clsDate Date, int X = 1)
    {
        Date._year -= X;
        if (Date._month == 2 && Date._day == 29 && !is_leapYear(Date._year))
            Date._day = 28;

        return Date;
    }

    clsDate DecreaseDateByOneAndXDecades(int X = 1)
    {
        *this = DecreaseDateByOneAndXDecades(*this, X);
        return *this;
    }
    static clsDate DecreaseDateByOneAndXDecades(clsDate Date, int X = 1)
    {
        for (int i = 0; i < X; i++)
        {
            Date = DecreaseDateByOneAndXYearFaster(Date, 10);
        }

        return Date;
    }

    clsDate DecreaseDateByOneAndXDecadesFaster(int X = 1)
    {
        *this = DecreaseDateByOneAndXDecadesFaster(*this, X);
        return *this;
    }
    static clsDate DecreaseDateByOneAndXDecadesFaster(clsDate Date, int X = 1)
    {
        return DecreaseDateByOneAndXYearFaster(Date, 10 * X);
    }

    clsDate DecreaseDateByOneCentury()
    {
        *this = DecreaseDateByOneCentury(*this);
        return *this;
    }
    static clsDate DecreaseDateByOneCentury(clsDate Date)
    {
        return DecreaseDateByOneAndXYearFaster(Date, 100);
    }

    clsDate DecreaseDateByOneMillennium()
    {
        *this = DecreaseDateByOneMillennium(*this);
        return *this;
    }
    static clsDate DecreaseDateByOneMillennium(clsDate Date)
    {
        return DecreaseDateByOneAndXYearFaster(Date, 1000);
    }

    clsDate IncreaseDateByXDay(int X)
    {
        *this = IncreaseDateByXDay(*this, X);
        return *this;
    }
    static clsDate IncreaseDateByXDay(clsDate Date, int X)
    {
        clsDate NewDate = Date;
        for (int i = 0; i < X; i++)
        {
            NewDate = IncreaseDateByOneDay(NewDate);
        }
        return NewDate;
    }

    clsDate IncreaseDateByOneAndXWeek(int X = 1)
    {
        *this = IncreaseDateByOneAndXWeek(*this, X);
        return *this;
    }
    static clsDate IncreaseDateByOneAndXWeek(clsDate Date, int X = 1)
    {
        int DaysToAdd = WeekToDays(X);

        return AddDaysToDate(Date._day, Date._month, Date._year, DaysToAdd);
    }

    clsDate IncreaseDateByOneAndXMonth(int X = 1)
    {
        *this = IncreaseDateByOneAndXMonth(*this, X);
        return *this;
    }
    static clsDate IncreaseDateByOneAndXMonth(clsDate Date, int X = 1)
    {
        Date._month += X;

        while (Date._month > 12)
        {
            Date._month -= 12;
            Date._year++;
        }

        short maxDaysInNewMonth = DaysInMonth(Date._month, Date._year);
        if (Date._day > maxDaysInNewMonth)
        {
            Date._day = maxDaysInNewMonth;
        }

        return Date;
    }

    clsDate IncreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
        return *this;
    }
    static clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (Date._month == 12)
        {
            Date._month = 1;
            Date._year++;
        }
        else
        {
            Date._month++;
        }
        return Date;
    }

    clsDate IncreaseDateByOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
        return *this;
    }
    static clsDate IncreaseDateByOneYear(clsDate Date)
    {
        Date._year++;
        return Date;
    }

    clsDate IncreaseDateByXYears(short Years)
    {
        *this = IncreaseDateByXYears(*this, Years);
        return *this;
    }
    static clsDate IncreaseDateByXYears(clsDate Date, short Years)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    clsDate IncreaseDateByOneAndXYearFaster(int X = 1)
    {
        *this = IncreaseDateByOneAndXYearFaster(*this, X);
        return *this;
    }
    static clsDate IncreaseDateByOneAndXYearFaster(clsDate Date, int X = 1)
    {
        Date._year += X;
        if (Date._month == 2 && Date._day == 29 && !is_leapYear(Date._year))
            Date._day = 28;

        return Date;
    }

    clsDate IncreaseDateByOneAndXDecades(int X = 1)
    {
        *this = IncreaseDateByOneAndXDecades(*this, X);
        return *this;
    }
    static clsDate IncreaseDateByOneAndXDecades(clsDate Date, int X = 1)
    {
        for (int i = 0; i < X; i++)
        {
            Date = IncreaseDateByOneAndXYearFaster(Date, 10);
        }

        return Date;
    }

    clsDate IncreaseDateByOneAndXDecadesFaster(int X = 1)
    {
        *this = IncreaseDateByOneAndXDecadesFaster(*this, X);
        return *this;
    }
    static clsDate IncreaseDateByOneAndXDecadesFaster(clsDate Date, int X = 1)
    {
        return IncreaseDateByOneAndXYearFaster(Date, 10 * X);
    }

    clsDate IncreaseDateByOneCentury()
    {
        *this = IncreaseDateByOneCentury(*this);
        return *this;
    }
    static clsDate IncreaseDateByOneCentury(clsDate Date)
    {
        Date._year += 100;
        if (Date._month == 2 && Date._day == 29 && !is_leapYear(Date._year))
        {
            Date._day = 28;
        }
        return Date;
    }

    clsDate IncreaseDateByOneMillennium()
    {
        *this = IncreaseDateByOneMillennium(*this);
        return *this;
    }
    static clsDate IncreaseDateByOneMillennium(clsDate Date)
    {
        Date._year += 1000;
        if (Date._month == 2 && Date._day == 29 && !is_leapYear(Date._year))
        {
            Date._day = 28;
        }
        return Date;
    }

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };
    enDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }
    static enDateCompare CompareDates(const clsDate& Date1, const clsDate& Date2)
    {
        if (is_Date1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;
        if (is_Date1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }
};
