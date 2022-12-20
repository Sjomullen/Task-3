/**
 * Do not make any changes in this file.
 */

#include "Date.hpp"
#include <stdexcept>
#include <string>

Date::Date() : day(1), month(1), year(0)
{

}

Date::Date(unsigned int day, unsigned int month, unsigned int year) :
    day(day), month(month), year(year)
{
    if (!IsValidDate(this->day, this->month, this->year))
        throw std::invalid_argument(
            "Invalid date values: day=" + std::to_string(this->day)
            + ", month=" + std::to_string(this->month)
            + ", year=" + std::to_string(this->year));
}

Date::Date(const Date& other) :
    day(other.day), month(other.month), year(other.year)
{

}

Date& Date::operator=(const Date& other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    return *this;
}

bool Date::operator==(const Date& other) const
{
    return this->GetCombinedDateValue() == other.GetCombinedDateValue();
}

bool Date::operator!=(const Date& other) const
{
    return !(*this == other);
}

bool Date::operator>(const Date& other) const
{
    return this->GetCombinedDateValue() > other.GetCombinedDateValue();
}

bool Date::operator<(const Date& other) const
{
    return this->GetCombinedDateValue() < other.GetCombinedDateValue();
}

bool Date::operator>=(const Date& other) const
{
    return this->GetCombinedDateValue() >= other.GetCombinedDateValue();
}

bool Date::operator<=(const Date& other) const
{
    return this->GetCombinedDateValue() <= other.GetCombinedDateValue();
}

void Date::SetDay(unsigned int day)
{
    this->day = day;
}

void Date::SetMonth(unsigned int month)
{
    this->month = month;
}

void Date::SetYear(unsigned int year)
{
    this->year = year;
}

void Date::SetDate(unsigned int day, unsigned int month, unsigned int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

unsigned int Date::GetDay() const
{
    return this->day;    
}

unsigned int Date::GetMonth() const
{
    return this->month;
}

unsigned int Date::GetYear() const
{
    return this->year;
}

std::string Date::GetString() const
{
    return std::to_string(this->day) + "-" + std::to_string(this->month) + "-" + std::to_string(this->year);
}

unsigned int Date::GetCombinedDateValue() const
{
    /**
     * Priority: year-month-date
     * 
     * january 15th 2022 as a combined value: 20220115
     * october 9th 2023 as a combined value: 20231009
     * 
     * Comparing example: 20231009 > 20220115 Ok!
     */
    return this->year * 10000 + this->month * 100 + this->day;
}

unsigned int Date::GetTotalDaysOfMonth(unsigned int month, unsigned int year)
{
    static const unsigned int JANUARY = 1;
    static const unsigned int FEBRUARY = 2;
    static const unsigned int MARCH = 3;
    static const unsigned int APRIL = 4;
    static const unsigned int MAY = 5;
    static const unsigned int JUNE = 6;
    static const unsigned int JULY = 7;
    static const unsigned int AUGUST = 8;
    static const unsigned int SEPTEMBER = 9;
    static const unsigned int OCTOBER = 10;
    static const unsigned int NOVEMBER = 11;
    static const unsigned int DECEMBER = 12;

    // February is a special case -> handle it first
    unsigned int day = 0;
    if (month == FEBRUARY)
        day = 28 + ((IsLeapYear(year)) ? 1 : 0); 
    else
    {
        switch (month)
        {
            case JANUARY:
            case MARCH:
            case MAY:
            case JULY:
            case AUGUST:
            case OCTOBER:
            case DECEMBER:
                day = 31;
                break;
            case APRIL:
            case JUNE:
            case SEPTEMBER:
            case NOVEMBER:
                day = 30;
                break;
        };
    }
    return day;
}

bool Date::IsLeapYear(unsigned int year)
{
    /**
     * https://en.wikipedia.org/wiki/Leap_year : 
     * 
     *    "Every year that is exactly divisible by four is a leap year, except
     *     for years that are exactly divisible by 100, but these centurial
     *     years are leap years if they are exactly divisible by 400. For
     *     example, the years 1700, 1800, and 1900 are not leap years, but the
     *     years 1600 and 2000 are."
     */

    bool divisableByFour = (year % 4 == 0);
    bool divisableByHundred = (year % 100 == 0);
    bool divisableByFourHundred = (year % 400 == 0);
    
    if (!divisableByFour)
        return false;
    if (!divisableByHundred) // && divisableByFour
        return true;
    return divisableByFourHundred; // && divisableByFour && divisableByHundred
}

bool Date::IsValidDate(unsigned int day, unsigned int month, unsigned int year)
{
    bool isValid = true;
    isValid = isValid && (month <= 12);
    isValid = isValid && (day <= GetTotalDaysOfMonth(month, year));
    return isValid;
}
