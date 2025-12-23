#ifndef SURGERY_H
#define SURGERY_H
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Surgery 
{
    private:
        string procedure_code;
        string codes[4];
        double charge;

    public:
        // Constructors
        Surgery()
        {
            procedure_code = "";
            charge = 0.00;
        }

        // Setters
        void setProcedureCode(string code) {procedure_code = code;}
        void setCodes()
        {
            codes = ["N01", "S06", "D27", "E99", "OP7"]
        }
        void setCharge(double cost) {charge = cost;}

        // Getters
        void getProcedureCode(string code) {procedure_code = code;}
        void getCharge(double cost) {charge = cost;}
};

#endif