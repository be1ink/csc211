// Demonstrate the classes by writing a program
// that uses a ProductionWorker object.

// Packages & Files
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <regex>
#include "production_worker.h"
using namespace std;

// Function prototypes
string get_name();
string get_emp_id();
bool valid_date_strict(const string&); 
string get_hire_date();
int get_shift();
double get_hrly_pay();
void display_emp_stats(Production_Worker&);

int main()
{
    // Declare variables
    int total_emps = 0;

    cout << "Please input the number of employees being input into system: ";
    cin >> total_emps;

    // Assuming default constructor use:
    for (int i = 0; i < total_emps; ++i)
    {
        Production_Worker worker_i;
        worker_i.set_emp_name(get_name());
        worker_i.set_emp_num(get_emp_id());
        worker_i.set_hire_date(get_hire_date());
        worker_i.set_shift(get_shift());
        worker_i.set_hrly_pay(get_hrly_pay());
        cout << endl;
        display_emp_stats(worker_i);
        cout << endl;
    }

    return 0;
}

// Function definitions
string get_name()
{
    string name;

    cout << "Please enter employee name: ";
    cin >> name;

    return name;
}

string get_emp_id()
{
    string num = "";

    cout << "Please enter employee ID (6 digits): ";
    cin >> num;

    while(num.size() != 6 || 
        // npos is a constant that contains the maximum size a string could
        // possibly be. This essentially will scour the string for any non-
        // numerical characters until the it reaches the end. find_first_not_of
        // will return npos if it doesn't find any of the matching ASCII chars,
        // hence why we say "!= string::npos".
        num.find_first_not_of("0123456789") != string::npos)
    {
        cout << "\nInvalid Employee ID. Please try again." << endl;
        cout << "Input Employee ID: ";
        cin >> num;
    }
    return num;
}

bool valid_date_strict(const string& s) 
{
    static const regex re
    (
        R"(^\d{4}-(?:0[1-9]|1[0-2])-(?:0[1-9]|[12]\d|3[01])$)"
    );
    return regex_match(s, re);
}

string get_hire_date()
{
    string date = "";

    cout << "Please enter the hire date (YYYY-MM-DD): ";
    cin >> date;

    while (!valid_date_strict(date)) 
    {
        cout << "\nInvalid date. Please try again." << endl;
        cout << "Enter hire date (YYYY-MM-DD): ";
        cin >> date;
    }
    return date;
}

int get_shift()
{
    int s = 0;

    cout << "Please enter the shift code 1 (Day) or 2 (Night): ";
    cin >> s;

    while(s < 1 || s > 2)
    {
        cout << "\nInvalid shift code. Must be either 1 (Day) or 2 ";
        cout << "(Night). Please try again." << endl;
        cout << "Input Shift Code 1 (Day) or 2 (Night): ";
        cin >> s;
    }
    return s;
}

double get_hrly_pay()
{
    double pay = 0.0;

    cout << "Please enter the hourly rate: ";
    cin >> pay;

    while(pay < 0.0)
    {
        cout << "\nInvalid hourly rate. Must be $0.00 or greater. ";
        cout << "Please try again." << endl;
        cout << "Input hourly pay rate: $";
        cin >> pay;
    }
    return pay;
}

void display_emp_stats(Production_Worker& employee)
{
    cout << employee.get_emp_name() << "'s Details: " << endl;
    cout << "Employee ID: " << employee.get_emp_num() << endl;
    cout << "Hire Date: " << employee.get_hire_date() << endl;
    cout << "Shift Code: " << employee.get_shift() << endl;
    cout << setprecision(2) << fixed;
    cout << "Hourly Pay Rate: $" << employee.get_hrly_pay() << endl;
}