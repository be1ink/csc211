#include <iostream>
#include <iomanip>
#include <limits> // For numeric_limits in input validation
#include "Savings_Account.h"
#include "Checking_Account.h"
using namespace std;

// Function prototypes
template <class T> 
T get_num(T, T); // for both menu options and dollar amounts
void display_menu_1();
void display_menu_2();
void account_trans(Bank_Account*);
void display_summary(int*, bool*, bool*, Bank_Account*, Bank_Account*);

int main()
{
    // Declare variables
    Savings_Account sa; // Will initialize later
    Checking_Account ca; // Will initialize later
    int menu_choice_1 = 0;
    bool savings_init = false;
    bool checking_init = false;
    int month = 1;
    double bal = 0.0;
    double bal_init = 0.0;

    // Initial message:
    cout << "Welcome to BLinK Bank. Please enter the corresponding number to select ";
    cout << "an option.\nPlease see an agent or call the bank if you have technical ";
    cout << "difficulties." << endl;

    // Menu logic: Initialize Accounts
    do
    {
        display_menu_1();
        cout << "Menu selection: ";
        menu_choice_1 = get_num(1, 6);

        // Initialize savings account
        if(menu_choice_1 == 1 && savings_init == false)
        {
            cout << "Please enter balance to be transferred to Savings Account: $";
            bal_init = get_num(0.0, numeric_limits<double>::max());
            sa = Savings_Account(bal_init);
            savings_init = true;
        }
        else if(menu_choice_1 == 1 && savings_init == true)
        {
            cout << "Savings Account already created, please select other options.";
            cout << endl;
        }

         // Initialize checking account
        else if(menu_choice_1 == 2 && checking_init == false)
        {
            cout << "Please enter balance to be transferred to Checking Account: $";
            bal_init = get_num(0.0, numeric_limits<double>::max());
            ca = Checking_Account(bal_init);
            checking_init = true;
        }
        else if(menu_choice_1 == 2 && checking_init == true)
        {
            cout << "Checking Account already created, please select other options.";
            cout << endl;
        }

        // If options 3 or 4 picked, execute a transaction:
        else if(menu_choice_1 == 3 && savings_init == true) {account_trans(&sa);}
        else if(menu_choice_1 == 3 && savings_init == false) 
        {
            cout << "No Savings Account found." << endl;
        }

        else if(menu_choice_1 == 4 && checking_init == true) {account_trans(&ca);}
        else if(menu_choice_1 == 4 && checking_init == false) 
        {
            cout << "No Checking Account found." << endl;
        }

        else if(menu_choice_1 == 5)
        {
            display_summary(&month, &savings_init, &checking_init, &sa, &ca);
        }

    }while(menu_choice_1 != 6);

    cout << "Thank you for using our online services. Have a nice day!" << endl;

    return 0;
}

// Functions
template <class T>
T get_num(T a, T b)
{
    T choice;

    while (true)
    {
        // Multiple error checks:
            // If input stream doesn't error out (accept input each time)
            // If the next character in the input buffer is the newline char
                // after the number is read
            // If the menu choice is in the correct range
        if (cin >> choice && cin.peek() == '\n' && (choice >= a && choice <= b))
        {
            return choice;
        }
        cout << "Invalid menu selection. Try again: ";
        cin.clear();
        // Ignore all unanticipated input for the maximum stream size or until
        // the new line char is enountered
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void display_menu_1()
{
    cout << endl;
    cout << "[1] Open Savings Account" << endl;
    cout << "[2] Open Checking Account" << endl;
    cout << "[3] Make a transaction with Savings Account" << endl;
    cout << "[4] Make a transaction with Checking Account" << endl;
    cout << "[5] Retrieve current monthly statement of accounts" << endl;
    cout << "[6] Exit";
    cout << endl;
}

// If options 
void display_menu_2()
{
    cout << endl;
    cout << "Transaction Menu:" << endl;
    cout << "[1] Deposit funds" << endl;
    cout << "[2] Withdraw funds" << endl;
    cout << "[3] Exit" << endl;
}

void account_trans(Bank_Account* ba)
{
    int menu_choice_2 = 0;
    double money = 0.0;
    do
    {
        display_menu_2();
        cout << "Menu selection: ";
        menu_choice_2 = get_num(1, 3);

        if(menu_choice_2 == 1) 
        {
            cout << "Please enter dollar amount to be deposited: $";
            money = get_num(0.0, numeric_limits<double>::max());
            ba->deposit(money);
            cout << endl;
        }
        else if(menu_choice_2 == 2) 
        {
            cout << "Please enter dollar amount to be withdrawn: $";
            money = get_num(0.0, numeric_limits<double>::max());
            ba->withdraw(money);
            cout << endl;
        }

    }while(menu_choice_2 != 3);
}

void display_summary(int* m, bool* s, bool* c, Bank_Account* sa, Bank_Account* ca)
{
    cout << "\nMonth " << *m << " Account(s) Summary:" << endl;

    if(*s == true)
    {
        cout << "----------------------------------\n";
        cout << "SAVINGS ACCOUNT" << endl;
        cout << "----------------------------------\n";
        cout << "Beginning balance: $" << sa->get_beg_bal() << endl;
        cout << "Total Deposits: " << sa->get_num_dep() << endl;
        cout << "Total Withdrawals: " << sa->get_num_with() << endl;

        // Process service charges and compute final balance
        sa->monthlyProc();

        cout << "Service Charges: $" << sa->get_month_charge_cpy() << endl;
        cout << "Final Balance: $" << sa->get_balance() << endl;

        sa->set_beg_bal(sa->get_balance());
    }

    if(*c == true)
    {
        cout << "----------------------------------\n";
        cout << "CHECKING ACCOUNT" << endl;
        cout << "----------------------------------\n";
        cout << "Beginning balance: $" << ca->get_beg_bal() << endl;
        cout << "Total Deposits: " << ca->get_num_dep() << endl;
        cout << "Total Withdrawals: " << ca->get_num_with() << endl;

        // Process service charges and compute final balance
        ca->monthlyProc();

        cout << "Service Charges: $" << ca->get_month_charge_cpy() << endl;
        cout << "Final Balance: $" << ca->get_balance() << endl;

        ca->set_beg_bal(ca->get_balance());
    }

    *m += 1;
}