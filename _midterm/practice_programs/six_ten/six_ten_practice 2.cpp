// Write a menu-driven C++ program for a Health Club Membership Fee Calculator that:
// 	1.	Displays a menu of membership types:
// 	•	Standard Adult
// 	•	Child
// 	•	Senior Citizen
// 	•	Quit

// 	2.	Asks the user to enter their choice.
// 	•	Validate that the input is between 1 and 4.
// - reject non-integer entries

// 	3.	If they don’t quit:
// 	•	Ask how many months they want to pay for.
// 	•	Call a function that calculates and displays the total cost.

// 	4.	Each membership type has a different monthly rate (e.g. Adult = 40, Child = 20, Senior = 30).
// 	5.	Keep looping until the user chooses to quit.

#include <iostream>
#include <iomanip>
#include "membership.h"
using namespace std;

// Function prototypes
void display_menu();
int get_choice();
int get_months();

int main()
{
    // Initialize variables
    int choice = 0; 
    int months = 0;
    Membership mem;

    cout << "-------------------------------------------------\n";
    cout << "/////////////////////////////////////////////////\n";
    cout << "-------------------------------------------------\n";
    cout << "This program will generate the total cost of \n";
    cout << "customer membership fees.";

    while(true)
    {
        display_menu();

        choice = get_choice();

        // If exit option chosen, break
        if(choice == 4) {break;}

        mem.set_rate(choice);

        cout << "\nPlease enter the number of months of membership.\n";
        
        months = get_months();
        mem.set_cost(months);

        // cout << setprecision(2) << fixed;
        cout << "\nTotal cost for member is: $" << mem.get_cost() << endl << endl;
    }

    cout << "\nExit option selected. Thank you for using this program!" << endl;

    return 0;
}

// Functions
void display_menu()
{
    cout << "Please input a number corresponding to the menu options below:\n";
    cout << "[1] Standard Adult Rate\n";
    cout << "[2] Child Rate\n";
    cout << "[3] Senior Rate\n";
    cout << "[4] Exit\n";
}

int get_choice()
{
    int choice = 0;

    cout << "Enter option: ";
    cin >> choice;
    // while(choice < 1 || choice > 4 || !cin || cin.peek() != '\n')
    while(choice < 1 || choice > 4 || cin.peek() != '\n')
    {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again. Enter option: ";
        cin >> choice;
    }
    return choice;
}

int get_months()
{
    int months = 0;

    cout << "Enter number of months: ";
    cin >> months;
    // while(choice < 1 || choice > 4 || !cin || cin.peek() != '\n')
    while(months < 0 || cin.peek() != '\n')
    {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again. Enter number of months: ";
        cin >> months;
    }
    return months;
}