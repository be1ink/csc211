// 11. Corporate Sales Data Output

// Write a program that uses a structure to store the following data on a 
// company division:
//  • Division Name (such as East, West, North, or South)
//  • Quarter (1, 2, 3, or 4)
//  • Quarterly Sales
//
// The user should be asked for the four quarters’ sales figures for the East, 
// West, North, and South divisions. The data for each quarter for each division 
// should be written to a file.
//
// Input Validation: Do not accept negative numbers for any sales figures.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Define structure
struct Division
{
    string div_name;
    int quarter = 0;
    double q_sales = 0.0;
};

// Define functions
int getNum();
double getNonNegDouble();

int main()
{
    // Declare variables
    Division div_info;
    ofstream output_file;
    const string CARDINALS[4] = {"East", "West", "North", "South"};

    output_file.open("division_quarterly_figures.txt", ios::out);
    if (!output_file)
    {
        cout << "Error opening output file.\n";
        return 1;
    }

    cout << "Enter division numbers to record (0 to quit).\n";

    // Loop to accept new divisions (integer) using getNum()
    while (true)
    {
        cout << "\nEnter Division Number (0 to exit): ";
        int division_number = getNum();
        if (division_number == 0) { break; }

        // Header line for this division block
        output_file << "Division: " 
                    << setw(4) << setfill('0') << division_number 
                    << setfill(' ') << '\n';

        // For each cardinal direction, collect Q1-Q4 and write one line
        for (int d = 0; d < 4; d++)
        {
            div_info.div_name = CARDINALS[d];

            output_file << setw(6) << left << div_info.div_name << ": ";
            // Gather 4 quarters of sales for this division (validate non-negative)
            for (int q = 1; q <= 4; q++)
            {
                div_info.quarter = q;

                cout << "Enter " << div_info.div_name 
                     << " quarter " << q << " sales: ";
                div_info.q_sales = getNonNegDouble();

                // Write "Qx=value" with 2 decimals, space-separated
                output_file << "Q" << q << "=" 
                            << fixed << setprecision(2) << div_info.q_sales;
                if (q < 4) output_file << ' ';
            }
            output_file << '\n';
        }

        output_file << '\n';
        cout << "Division " << division_number << " recorded.\n";
    }

    output_file.close();
    cout << "\nAll done. Data written to division_quarterly_figures.txt\n";
    return 0;
}

// Validates non-negative integer input
int getNum()
{
    int num = 0;

    while (true)
    {
        cin >> num;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Non-integer entry. Please enter a valid number: ";
            continue;
        }

        if (num < 0)
        {
            cout << "Negative input. Please enter a positive number (or 0 to exit): ";
            continue;
        }

        break;
    }
    return num;      
}

// Validates non-negative double input (same pattern as getNum)
double getNonNegDouble()
{
    double val = 0.0;

    while (true)
    {
        cin >> val;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid entry. Please enter a number: ";
            continue;
        }

        if (val < 0.0)
        {
            cout << "Negative input. Please enter a non-negative number: ";
            continue;
        }

        break;
    }
    return val;
}