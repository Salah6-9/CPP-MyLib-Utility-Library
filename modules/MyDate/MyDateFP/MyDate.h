#pragma once
#include <string>

namespace MyDate
{
    struct sDate
    {
        short month;
        short day;
        short year;
    };

    bool is_leapYear(int num);
    int MinHourToSecMin(int MinHour);
    int HoureInDay(int day);
    int DaysInYear(int year);
    void DisplayYearDetails(int year);
    int DaysInMonth(short Month, short Year);
    void DisplayMonthDetails(short Month, short year);
    int dGregoianCalendar(short day, short month, short year);
    std::string DayName(short d);
    void PrintDayNameOfWeek(short day, short month, short year);
    std::string MonthName(short month);
    void PrintMonthCalendar(short month, short year);
    void PrintYearCalendar(short year);
    short CalculateDaysSinceStartOfYear(short day, short month, short year);
    sDate GetDateFromDayOrderInYear(int DaysAdded, int year);
    sDate AddDaysToDate(short day, short month, short year, int daysToAdd);
    sDate AddDaysToDateFromBeginingOfYear(sDate Date, int DateToAdd);
    sDate ReadFullDate(std::string title = "");
    bool is_Date1BeforThenDate2(sDate Date1, sDate Date2);
    bool is_Date1EqualDate2(sDate Date1, sDate Date2);
    bool is_LastDayInMonth(sDate Date);
    bool is_LastMonthInYear(int month);
    sDate IncreaseDateByOneDay(sDate Date);
    int DiffInDaysVer2(sDate Date1, sDate Date2, bool EndDay = false);
    void swapDate(sDate &Date1, sDate &Date2);
    int DiffInDays(sDate Date1, sDate Date2, bool EndDay = false);
    sDate GetRealTime();
    int AgeInDays(sDate BirhDate);
    std::string DateToString(const sDate& Date);
    bool IsDate1BeforeDate2(const sDate& Date1, const sDate& Date2);
    int GregorianDayOfWeek(const sDate& Date);
    bool IsEndOfWeek(const sDate& Date);
    bool IsWeekEnd(const sDate& Date);
    bool IsBusinessDay(const sDate& Date);
    int DaysUntilEndOfWeek(const sDate& Date);
    int DaysUntilEndOfMonth(const sDate& Date);
    sDate EndOfYear(sDate Date);
    int DaysUntilEndOfYear(const sDate& Date);
    int CalculateVacationDays(sDate DateFrom, sDate DateTo);
    sDate CalculateVacationDate(sDate DateFrom, int VactionDays);
}
