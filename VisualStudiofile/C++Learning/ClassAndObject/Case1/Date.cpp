#include <iostream>
#include <stdexcept>
#include<string>
#include "Date.h" 
using namespace std;

Date::Date(int mn, int dy, int yr)
{
    if (mn > 0 && mn <= monthsPerYear) // validate the month
        month = mn;
    else
        throw invalid_argument("Month must be 1-12");
    

    year = yr; // could validate yr
    day = checkDay(dy); // validate the day

    // output Date object to show when its constructor is called
    cout << "Date object constructor for date ";
    print1();
    cout << endl;
} 
Date::Date(const Date& date)
{
    if (date.month > 0 && date.month <= monthsPerYear)
    {
        this->month = date.month;
    }
    else
    {
        throw invalid_argument("month must be 1-12");
    }
    this->year = date.year;
    this->day = this->checkDay(date.day);
    cout << "Date object constructor for date ";
    print1();
    cout << endl;
}
Date::Date(int dy, int yr)
{
    year = yr;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        if (dy > 0 && dy <=366)
            day = dy;
        else
            throw invalid_argument("The day must be lesser than 366");
    }
    else
    {
        if (dy > 0 && dy <= 365)
            day = dy;
        else
            throw invalid_argument("The day must be lesser than 365");
    }
    cout << "Date object constructor for date ";
    print2();
}
Date::Date(string m,int dy, int yr)
{
    bool flag = 0;
    string s[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
    for (int i = 0; i < 12; i++)
    {
        if (m == s[i])
        {
            flag = 1;
            month = i + 1;
        }
    }
    if (flag == 0)
    {
        throw invalid_argument("month must be 1-12");
    }
    else
    {
        year = yr;
        day = checkDay(dy);
        cout << "Date object constructor for date ";
        print3(m);
    }
}
void Date::print1() const
{
    cout<<month<<"/"<<day << '/' << year;
} 
void Date::print2() const
{
    cout<< day << '/' << year<<endl;
}
void Date::print3(string s)const
{
    cout << s << ' ' << day << ',' << year << endl;
}


Date::~Date()
{
    cout << "Date object destructor for date " << endl;

} 

int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[monthsPerYear + 1] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;


    if (month == 2 && testDay == 29 && (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("Invalid day for current month and year");
} 