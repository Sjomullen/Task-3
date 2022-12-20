/**
 * Do not make any changes in this file.
 */

#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date
{
public:

    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);
    Date(const Date& other);
    Date& operator=(const Date& other);

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;

    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator<=(const Date& other) const;

    void SetDay(unsigned int day);
    void SetMonth(unsigned int month);
    void SetYear(unsigned int year);
    void SetDate(unsigned int day, unsigned int month, unsigned int year);

    unsigned int GetDay() const;
    unsigned int GetMonth() const;
    unsigned int GetYear() const;

    std::string GetString() const;
    
private:

    unsigned int day;
    unsigned int month;
    unsigned int year;

    unsigned int GetCombinedDateValue() const;
    static unsigned int GetTotalDaysOfMonth(unsigned int month, unsigned int year);
    static bool IsLeapYear(unsigned int year);
    static bool IsValidDate(unsigned int day, unsigned int month, unsigned int year);
};

#endif // DATE_HPP