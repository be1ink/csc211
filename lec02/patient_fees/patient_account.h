#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H
// #include <iostream>
// #include <iomanip>
// #include <cstring>
// using namespace std;

class PatientAccount 
{
    private:
        int days;
        char insurance;
        double rate; // Maybe have a variable for insurance type
        int numCharges;
        double* charge; // Make only the amount of charges dynamic in memory
        double totalCharge;

        // Dynamically declare memory
        void initCharge()
        {
            charge = nullptr;
            charge = new double[numCharges]; // How do you allocate memory for digits?
        }

    public:

        // Constructors
        PatientAccount()
        {
            days = 0;
            insurance = 'N'; // No insurance
            rate = getRate(); // Make 100.00
            numCharges = 0;
            charge = 0.00;
            totalCharge = 0.00;
        }

          PatientAccount(int d, char i)
        {
            days = d;
            insurance = i;
            rate = getRate();
            numCharges = 0;
            *charge = 0.00;
            totalCharge = 0.00;
        }

        // Destructors
        ~PatientAccount()
        {
            delete [] charge;
        }

        // Setters
        void setDays(int d) {days = d;}
        void setInsurance (char i) {insurance = i;}
        void setRate ()
        {
            switch(getInsurance())
            {
                case 'N': // No coverage
                    rate = 2750.00;
                case 'O': // Out-of-network
                    rate = 1000.00;
                case 'L': // Low-grade in-network 
                    rate = 500.00;
                case 'M': // Medium-grade in-network
                    rate = 250.00;
                case 'P': // Premium-grade in-network
                    rate = 100.00;
            }     
        }
        void setNumCharges(int nc) {numCharges = nc;}
        void setCharge(double c) {charge[numCharges] = c;}
        void setTotalCharge() 
        {
            for (int i=0; i<getNumCharges(); i++)
            {
                totalCharge += charge[i];
            }
        }

        // Getters
        int getDays() {return days;}
        char getInsurance() {return insurance;} 
        double getRate() {return rate;}
        int getNumCharges() {return numCharges;}
        double getCharge() {return *charge;}
        double getTotalCharge () {return totalCharge;}

};

#endif