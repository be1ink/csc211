#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include <iostream>
#include <iomanip>
#include "Bank_Account.h"

class Checking_Account : public Bank_Account
{
    public:
        // Default constructor
        Checking_Account() : Bank_Account() {;}

        // Overloaded constructor
        Checking_Account(double b) : Bank_Account(b) {;}
       
        // Helper function to check if amount goes below zero.
        bool check_sub_zero(double w)
        {
            double copy_bal = balance - w;

            if (copy_bal < 0) {return true;} // Withdrawal will knock balance below zero
            else {return false;} // Still more than $0.00 in account post withdrawal
        }

        // Before the base class function is called, this function will determine if a
        // withdrawal (a check written) will cause the balance to go below $O. If
        // the balance goes below $0, a service charge of $15 will be taken from
        // the account. (The withdrawal will not be made.) If there isn't enough
        // in the account to pay the service charge, the balance will become nega-
        // tive and the customer will owe the negative amount to the bank.
        void withdraw(double w)
        {
            if(check_sub_zero(w) == true) 
            {
                balance -= 15.00;

                cout << "Not enough funds for withdrawal. A $15.00 service ";
                cout << "charge has been processed and deducted from your account ";
                cout << "balance." << endl;

                cout << fixed << setprecision(2);
                cout << "Current balance: $" << balance;
            }
            else if(check_sub_zero(w) == false) // Could have said else, but felt this is more readable
            {
                Bank_Account::withdraw(w);
            }
        }

        // monthlyProc: Before the base class function is called, this function adds the monthly
        // fee of $5 plus $0.10 per withdrawal (check written) to the base class
        // variable that holds the monthly service charges.
        void monthlyProc()
        {
            Bank_Account::month_charge += 5+0.10*num_with;
            Bank_Account::monthlyProc();
        }

};
#endif