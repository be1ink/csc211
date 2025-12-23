// Next, write a class named ProductionWorker that is derived from the Employee class.
// The ProductionWorker class should have member variables to hold the following
// information:
// • Shift (an integer)
// • Hourly pay rate (a double)

// The workday is divided into two shifts: day and night. 
// The shift variable will hold an integer value representing the shift that the 
// employee works. The day shift is shift 1, and the night shift is shift 2. 
// Write one or more constructors, and the appropriate accessor and mutator 
// functions, for the class. 

#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include "employee.h"
using namespace std;

#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H

class Production_Worker : public Employee
{
    private:
        int shift;
        double hrly_pay;

    public:
        // Default constructor
        Production_Worker() : shift(1), hrly_pay(0.0) {}

        // Shift code provided
        Production_Worker(int s) : shift(get_shift()), hrly_pay(0.0) {}

        // Hourly pay provided
        Production_Worker(double pay) : shift(1), hrly_pay(get_hrly_pay()) {}

        // Shift code and hourly pay provided
        Production_Worker(int s, double pay) : shift(get_shift()), 
            hrly_pay(get_hrly_pay()) {}

        // Setters
        void set_shift(int s) {shift = s;}

        void set_hrly_pay(double pay)
        {
            if (get_shift() == 1) {hrly_pay = pay;}
            else if (get_shift() == 2) {hrly_pay = pay * 1.5;}
        }

        // Getters
        int get_shift() {return shift;}
        double get_hrly_pay() {return hrly_pay;}
};

#endif