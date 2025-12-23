#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include <iostream>
#include "Bank_Account.h"

class Savings_Account : public Bank_Account
{
    private:
        bool status;
    public:
        // Default constructor
        Savings_Account() : Bank_Account(), status(false) {;}

        // Overloaded constructor
        Savings_Account(double b) : Bank_Account(b), status(false) {;}

        // Helper function to check balance
        bool check_status()
        {
            if (balance >= 25.00) {status = true;} // account active
            else {status = false;} // simple else, no validation

            return status;
        }

        void withdraw(double w)
        {
            if(status == false) 
            {
                cout << "Account inactive: Less than $25.00 in account. Please ";
                cout << "deposit more funds to meet or exceed this amount." << endl;
            }
            else if(status == true) // Could have said else, but felt this is more readable
            {
                Bank_Account::withdraw(w);
            }
        }

        void deposit(double d)
        {
            // Assign account status to var before deposit
            bool status_copy = status;

            Bank_Account::deposit(d);
            check_status();
            
            // Message regarding account status
            if(status_copy == true) {;} // Account was active before deposit
            else if(status_copy == false && status == false) // still deactivated
            {
                cout << "Account inactive: Less than $25.00 in account. Please ";
                cout << "deposit more funds to meet or exceed this amount." << endl;
            }
            else if((status_copy == false && status == false)) // reactivated
            {
                cout << "Account reactivated: $25.00 amount threshold met." << endl;
            }
        }

        void monthlyProc()
        {
            if(num_with > 4)
            {
                // Add additional charge if withdrawals exceed 4 in a month
                month_charge += num_with - 4;
            }
            // Run the monthlyProc() Base class function
            Bank_Account::monthlyProc();
            // See if additional charge knocked balance below $25.00.
            check_status();
        }
};
#endif