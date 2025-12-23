#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
#include <iomanip>
using namespace std;

class Bank_Account
{
    protected:
        double balance;
        double beg_bal;
        int num_dep;
        int num_with;
        double int_rate;
        double month_charge;
        double month_charge_cpy;
    public:
        // Relying on compiler to furnish default constructor
        // Decided to make default constructor to demonstrate passing arguments
            // to base constructor
        Bank_Account() : balance(0.0), beg_bal(0.0), num_dep(0), num_with(0), 
            int_rate(0.12), month_charge(0.0), month_charge_cpy(0.0) {;}

        // Overloaded constructor - allowing default initialization for other vars
        Bank_Account(double b) : balance(b), beg_bal(b), num_dep(0), num_with(0), 
            int_rate(0.12), month_charge(0.0), month_charge_cpy(0.0) {;}

        // Virtual destructor
        virtual ~Bank_Account() {};

        // Helper function
        // Display balance after withdraws and deposits
        void display_bal()
        {
            cout << fixed << setprecision(2);
            cout << "Current balance: $" << balance << endl;
        }

        virtual void deposit(double d)
        {
            balance += d;
            num_dep++;
            display_bal();
        }

        virtual void withdraw(double w)
        {
            balance -= w;
            num_with++;
            display_bal();
        }

        virtual void calcInt()
        {
            // Declare variables
            double month_rate;
            double month_int;

            // Monthly Interest Rate = (Annual Interest Rate / 12
            // Monthly Interest = Balance * Monthly Interest Rate
            // Balance = Balance + Monthly Interest
            balance += balance * (int_rate / 12);
        }

        virtual void monthlyProc()
        {
            balance -= month_charge;
            month_charge_cpy = month_charge;

            // Calculate interest accrued after service charges applied
            // Only do so if the account has money, don't want to compound 
            // negative money!
            if(balance >= 0) {calcInt();}

            // Reset vars to zero
            num_dep = 0;
            num_with = 0;
            month_charge = 0.0;
        }

        // Setters
        void set_beg_bal(double b) {beg_bal = b;}

        // Getters
        double get_balance() const {return balance;}
        double get_beg_bal() const {return beg_bal;}
        int get_num_dep() const {return num_dep;}
        int get_num_with() const {return num_with;}
        double get_month_charge_cpy() const {return month_charge_cpy;}
};
#endif