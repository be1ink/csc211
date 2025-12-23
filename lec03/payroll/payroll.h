#ifndef PAYROLL_H
#define PAYROLL_H

class PayRoll
{
    private:
        double hrlyPayRate;
        double hrsWorked;
        double wklyPay;

    public:

        // Constructor
        PayRoll()
        {
            hrlyPayRate = 0.0;
            hrsWorked = 0.0;
            wklyPay = 0.0; 
        }

        // Setters
        void setHrlyPayRate(double pay) {hrlyPayRate = pay;}
        void setHrsWorked(double hours) {hrsWorked = hours;}
        void setWklyPay(double pay, double hours) {wklyPay = pay * hours;}

        // Getters
        double getHrlyPayRate() {return hrlyPayRate;}
        double getHrsWorked() {return hrsWorked;}
        double getWklyPay() {return wklyPay;}
};
#endif