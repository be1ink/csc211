// Benjamin Link
// CSC 211

#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype> // toupper
#include <string>
#include "business.h"
using namespace std;

// Function prototypes
char get_menu_choice();
int get_id();
string get_filename();
string get_out_filename();
void menu_display();
void menu_action(char, business&, bool&, const int);

int main()
{
    // Declare variables
    const double ss_rates = 0.062;
    const double ny_tax_rate = 0.185;
    const int id_width = 4;
    business biz(ny_tax_rate, ss_rates);
    char choice;
    bool data_loaded = false;

    do
    {
        menu_display();
        choice = get_menu_choice();
        menu_action(choice, biz, data_loaded, id_width);

    } while(choice != 'G');

    return 0;
}

char get_menu_choice()
{
    char c;
    cout << "Choice: ";
    cin >> c;
    // Ensures that inputs like a or A both are accepted and map to the same
        // program behavior.
    return static_cast<char>(toupper(static_cast<unsigned char>(c)));
}

int get_id()
{
    int id = 0;

    cout << "Please input ID number: ";
    while(true)
    {
        // Get ID if stream doesn't fail, the final char is a newline char
            // and it's within four digits
        if(cin >> id && cin.peek() == '\n' && id > 0 && id < 9999)
            {return id;}
        else
        {
            // clear error flag
            cin.clear();
            // If non-numerical char in buffer, could loop infinitely. This
                // ignores text in the buffer up to the maximum size of the
                // stream, or until a newline char is encountered
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please try again: ";
        }
    }
}

string get_filename()
{
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;
    return filename;
}

string get_out_filename()
{
    string filename;
    cout << "Enter output filename: ";
    cin >> filename;
    return filename;
}

void menu_display()
{
    cout << "\nWelcome to Bootleg Oracle PeopleSoft!\n";
    cout << "==========================================\n";
    cout << "A. Load employee data.\n";
    cout << "B. Calculate taxes and net pay for all employees in registry.\n";
    cout << "C. Ouput payroll information of employees, sorted by name.\n";
    cout << "D. Display employee checks\n";
    cout << "E. Display business social security tax and total payroll summary sheet.\n";
    cout << "F. Lookup employee information.\n";
    cout << "G. Exit\n";
}

void menu_action(char choice, business& biz, bool& data_loaded, const int id_width)
{
    if(choice == 'A')
    {
        string filename = get_filename();

        data_loaded = biz.load_from_combined_file(filename);

        if(!data_loaded)
            {cout << "Could not load employee data.\n";}
        else
            {cout << "Employee data loaded.\n";}
    }
    else if(choice == 'B')
    {
        if(!data_loaded)
            {cout << "No data loaded. Please run option A first.\n";}
        else
            {cout << "Payroll calculations are computed during output.\n";}
    }
    else if(choice == 'C')
    {
        if(!data_loaded)
        {
            cout << "No data loaded. Please run option A first.\n";
        }
        else
        {
            biz.sort_by_first_name();
            biz.print_sorted_report(cout, id_width);

            string out_filename = get_out_filename();

            if(biz.write_sorted_report(out_filename, id_width))
                {cout << "Wrote: " << out_filename << "\n";}
            else
                {cout << "Could not write output file.\n";}
        }
    }
    else if(choice == 'D')
    {
        if(!data_loaded)
            {cout << "No data loaded. Please run option A first.\n";}
        else
            {biz.print_all_checks(cout, id_width);}
    }
    else if(choice == 'E')
    {
        if(!data_loaded)
            {cout << "No data loaded. Please run option A first.\n";}
        else
            {biz.print_summary_sheet(cout);}
    }
    else if(choice == 'F')
    {
        if(!data_loaded)
        {
            cout << "No data loaded. Please run option A first.\n";
        }
        else
        {
            int id_num = get_id();

            employee* emp_ptr = biz.find_by_id(id_num);

            if(!emp_ptr)
            {
                cout << "Employee not found: "
                     << setw(id_width) << setfill('0') << id_num << setfill(' ')
                     << "\n";
            }
            else
            {
                emp_ptr->print_paycheck(cout, id_width);
            }
        }
    }
    else if(choice == 'G')
    {
        cout << "Exiting program.\n";
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}