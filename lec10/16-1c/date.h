// Modify the Date class you wrote for Programming Challenge 1 of Chapter 13 (Date). 
// The class should implement the following exception classes:

// InvalidDay
// Throw when an invalid day (< 1 or > 31) is passed to the class.

// InvalidMonth
// Throw when an invalid month (< 1 or > 12) is passed to the class.

#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
    private:
        int month = 0;
        int day = 0;
        int year = 0;
    public:
        // Exception classes to be called when error thrown.
        class InvalidDay {};
        class InvalidMonth {};

        // Setters
        void set_month(int m) 
        {
            if (m < 1 || m > 12) throw InvalidMonth();
            month = m;
        }

        void set_day(int d) 
        {
            if (d < 1 || d > 31) throw InvalidDay();
            day = d;
        }

        void set_year(int y) { year = y; }

        // Getters

        int get_day() const {return day;}
        int get_month() const {return month;}
        int get_year() const {return year;}
};

#endif