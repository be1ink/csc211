// Design a class named Employee. The class should keep the following information:
// • Employee name
// • Employee number
// • Hire date
// Write one or more constructors, and the appropriate accessor and mutator 
// functions for the class.

#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
    private:
        string emp_name;
        string emp_num; // 6-digit ID, will force validation in constructor
        string hire_date; // In the format YYYY-MM-DD

    public:
        // Default constructor
        Employee() : emp_name(""), emp_num("000000"), hire_date("9999-99-99") {}

        // Overloaded default constructor. Must have ID and hire date minimum
        Employee(string num, string date) : emp_name("") 
        {
            set_emp_num(num);
            set_hire_date(date);
        }

        // Setters
        void set_emp_name(string name)
        {
            emp_name = name;
        }

        void set_emp_num(string num)
        {
            emp_num = num;
        }

        void set_hire_date(string date)
        {
            hire_date = date;
        }

        // Getters
        string get_emp_name() {return emp_name;}
        string get_emp_num() {return emp_num;}
        string get_hire_date() {return hire_date;}
};

#endif