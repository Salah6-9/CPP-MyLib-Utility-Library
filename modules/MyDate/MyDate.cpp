#include "MyDate.h"
#include "../MyIO.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

namespace MyDate
{
    bool is_leapYear(int num)
    {
        return (num % 400 == 0) || (num % 4 == 0 && num % 100 != 0);
    }

    int MinHourToSecMin(int MinHour)
    {
        return MinHour * 60;
    }

    int HoureInDay(int day)
    {
        return day * 24;
    }

    int DaysInYear(int year)
    {
        return (is_leapYear(year)) ? 366 : 365;
    }

    void DisplayYearDetails(int year)
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

    int DaysInMonth(short Month, short Year)
    {
        static const int arrNumberOfDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (Month == 2) ? (is_leapYear(Year) ? 29 : 28) : arrNumberOfDays[Month];
    }

    void DisplayMonthDetails(short Month, short year)
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

    int dGregoianCalendar(short day, short month, short year)
    {
        int a = (14 - month) / 12,
            y = year - a,
            m = month + 12 * a - 2;

        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    string DayName(short d)
    {
        static const string Days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        return Days[d];
    }

    void PrintDayNameOfWeek(short day, short month, short year)
    {
        int dayOrder = dGregoianCalendar(day, month, year);
        cout << "Date   : " << day << "/" << month << "/" << year << endl;
        cout << "Day Order : " << dayOrder << endl;
        cout << "Day Name : " << DayName(dayOrder) << endl;
    }

    string MonthName(short month)
    {
        static const string Month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        return Month[month - 1];
    }

    void PrintMonthCalendar(short month, short year)
    {
        static const string Days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
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

    void PrintYearCalendar(short year)
    {
        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, year);
            cout << endl;
        }
    }

    short CalculateDaysSinceStartOfYear(short day, short month, short year)
    {
        short sum = 0, i;
        for (i = 0; i < month - 1; i++)
        {
            sum += DaysInMonth(i + 1, year);
        }
        return sum += day;
    }

    sDate GetDateFromDayOrderInYear(int DaysAdded, int year)
    {
        int i = 0;
        sDate Date;
        int DaysINMonth = DaysInMonth(i + 1, year);

        while (DaysAdded > DaysINMonth)
        {
            DaysAdded = DaysAdded - DaysINMonth;

            i++;
            if (i >= 12)
            {
                i = 0;
                year++;
            }
            DaysINMonth = DaysInMonth(i + 1, year);
        }
        Date.day = DaysAdded;
        Date.month = i + 1;
        Date.year = year;
        return Date;
    }

    sDate AddDaysToDate(short day, short month, short year, int daysToAdd)
    {
        sDate Date;

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

        Date.day = day;
        Date.month = month;
        Date.year = year;

        return Date;
    }

    sDate AddDaysToDateFromBeginingOfYear(sDate Date, int DateToAdd)
    {
        int totaldates = CalculateDaysSinceStartOfYear(Date.day, Date.month, Date.year) + DateToAdd;
        return GetDateFromDayOrderInYear(totaldates, Date.year);
    }

    sDate ReadFullDate(string title)
    {
        sDate Date;
        cout << "\n" << title;
        Date.year = MyIO::ReadPositiveNumber("\nEnter a year : ");
        Date.month = MyIO::Read_num_in_range("Enter a Month Number [1 to 12]: ", 1, 12);
        short maxDays = DaysInMonth(Date.month, Date.year);
        string dayPrompt = "Enter a Day Number [1 to " + to_string(maxDays) + "]: ";
        Date.day = MyIO::Read_num_in_range(dayPrompt, 1, maxDays);
        return Date;
    }

    bool is_Date1BeforThenDate2(sDate Date1, sDate Date2)
    {
        return (Date1.year < Date2.year) ||
               (Date1.year == Date2.year && Date1.month < Date2.month) ||
               (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day < Date2.day);
    }

    bool is_Date1EqualDate2(sDate Date1, sDate Date2)
    {
        return (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day == Date2.day);
    }

    bool is_LastDayInMonth(sDate Date)
    {
        return (Date.day == DaysInMonth(Date.month, Date.year));
    }

    bool is_LastMonthInYear(int month)
    {
        return month == 12;
    }

    sDate IncreaseDateByOneDay(sDate Date)
    {
        if (is_LastDayInMonth(Date))
        {
            if (is_LastMonthInYear(Date.month))
            {
                Date.day = 1;
                Date.month = 1;
                Date.year++;
            }
            else
            {
                Date.day = 1;
                Date.month++;
            }
        }
        else
        {
            Date.day++;
        }

        return Date;
    }

    int DiffInDaysVer2(sDate Date1, sDate Date2, bool EndDay)
    {
        int TotalDiffDays = 0;

        if (!is_Date1BeforThenDate2(Date1, Date2))
        {
            sDate temp = Date1;
            Date1 = Date2;
            Date2 = temp;
        }

        while (Date2.year - Date1.year > 1)
        {
            TotalDiffDays += DaysInYear(Date1.year);
            Date1.year++;
        }

        while (Date1.year < Date2.year || Date1.month < Date2.month)
        {
            TotalDiffDays += DaysInMonth(Date1.month, Date1.year);
            Date1.month++;

            if (Date1.month > 12)
            {
                Date1.month = 1;
                Date1.year++;
            }
        }

        TotalDiffDays += (Date2.day - Date1.day);

        return EndDay ? TotalDiffDays + 1 : TotalDiffDays;
    }

    void swapDate(sDate &Date1, sDate &Date2)
    {
        sDate temp = Date1;
        Date1 = Date2;
        Date2 = temp;
    }

    int DiffInDays(sDate Date1, sDate Date2, bool EndDay)
    {
        int DaysDiff = 0;
        short SwapFlag = 1;
        if (!is_Date1BeforThenDate2(Date1, Date2))
        {
            swapDate(Date1, Date2);
            SwapFlag = -1;
        }
        while (is_Date1BeforThenDate2(Date1, Date2))
        {
            DaysDiff++;
            Date1 = IncreaseDateByOneDay(Date1);
        }

        return (EndDay) ? (DaysDiff + 1) * SwapFlag : DaysDiff * SwapFlag;
    }

    sDate GetRealTime()
    {
        sDate Date;
        time_t t = time(0);
        tm* now = localtime(&t);
        Date.day = now->tm_mday;
        Date.month = now->tm_mon + 1;
        Date.year = now->tm_year + 1900;
        return Date;
    }

    int AgeInDays(sDate BirhDate)
    {
        sDate NowDate = GetRealTime();
        return DiffInDays(BirhDate, NowDate, true);
    }

    string DateToString(const sDate& Date)
    {
        return to_string(Date.day) + "/" +
               to_string(Date.month) + "/" +
               to_string(Date.year);
    }

    bool IsDate1BeforeDate2(const sDate& Date1, const sDate& Date2)
    {
        return (Date1.year < Date2.year) ||
               (Date1.year == Date2.year && Date1.month < Date2.month) ||
               (Date1.year == Date2.year &&
                Date1.month == Date2.month &&
                Date1.day < Date2.day);
    }

    int GregorianDayOfWeek(const sDate& Date)
    {
        int a = (14 - Date.month) / 12;
        int y = Date.year - a;
        int m = Date.month + (12 * a) - 2;

        return (Date.day + y + (y / 4) - (y / 100) +
                (y / 400) + ((31 * m) / 12)) % 7;
    }

    bool IsEndOfWeek(const sDate& Date)
    {
        return GregorianDayOfWeek(Date) == 6;
    }

    bool IsWeekEnd(const sDate& Date)
    {
        int dayIndex = GregorianDayOfWeek(Date);
        return (dayIndex == 5 || dayIndex == 6);
    }

    bool IsBusinessDay(const sDate& Date)
    {
        return !IsWeekEnd(Date);
    }

    int DaysUntilEndOfWeek(const sDate& Date)
    {
        return 6 - GregorianDayOfWeek(Date);
    }

    int DaysUntilEndOfMonth(const sDate& Date)
    {
        return (DaysInMonth(Date.month, Date.year) - Date.day) + 1;
    }

    sDate EndOfYear(sDate Date)
    {
        Date.day = 31;
        Date.month = 12;
        return Date;
    }

    int DaysUntilEndOfYear(const sDate& Date)
    {
        return DiffInDays(Date, EndOfYear(Date), true);
    }

    int CalculateVacationDays(sDate DateFrom, sDate DateTo)
    {
        int Days = 0;
        while (is_Date1BeforThenDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return Days;
    }

    sDate CalculateVacationDate(sDate DateFrom, int VactionDays)
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
}
