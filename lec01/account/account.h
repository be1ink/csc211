#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    private:
        double balance;
        double interestRate;
        double interest;
        int transactions;

    public:
        // Constructors
        Account(double iRate = 0.045, double bal = 0)
        {
            balance = bal;
            interestRate = iRate;
            interest = 0;
            transactions = 0;
        }

        // Destructors -- only for classes with pointers
        // ~Account()
        // {
        //     delete balance;
        //     delete interestRate;
        //     delete interest;
        //     delete transactions;
        // }

        // Setters
        void setInterestRate(double iRate)
        {
            interestRate = iRate;
        }

        void makeDeposit(double amount)
        {
            balance += amount; // defined in Account.cpp
        }

        // Unclear why we accept this input, another container?
        //void withdraw(double amount);

        bool withdraw(double amount)
        {
            if (balance < amount)
                return false; // insufficient funds
            else
            {
                balance -= amount;
                transactions++;
                return true;
            }  
        }

        // No input as it draws values from private methods after setting their values.
        // void calcInterest()
        // {
        //     interest = balance * interestRate;
        //     balance += interest;
        // }
        
        // Getters
        double getBalance() const
        {
            return balance;
        }

        double getInterestRate() const
        {
            return interestRate;
        }

        double getInterest() const
        {
            return (balance * interestRate);
        }

        int getTransactions() const
        {
            return transactions;
        }
};
#endif