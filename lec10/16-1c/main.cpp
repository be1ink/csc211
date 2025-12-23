// Date Exceptions

// Demonstrate the class in a driver program.

#include <iostream>
#include "date.h"
using namespace std;

int main()
{

    Date date;
    int day = 0;
    int month = 0;
    int year = 0;

    cout << "Please enter the day: ";
    cin >> day;
    date.set_day(day);

    cout << "Please enter the month: ";
    cin >> month;
    date.set_month(month); 

    cout << "Please enter the year: ";
    cin >> year;
    date.set_year(year);

    // Final Date
    cout << date.get_month() << "/" << date.get_day() << "/" << date.get_year() << endl;

    return 0;
}