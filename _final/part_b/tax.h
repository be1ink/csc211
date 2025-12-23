// Benjamin Link
// CSC 211

#ifndef TAX_H
#define TAX_H

#include <iostream>
using namespace std;

class tax_base
{
    protected:
        double ny_tax_rate;     // employee-only (18.5% per prompt)
        double ss_tax_rate;     // social security (6.2% each, 12.4% total)

    public:
        // Default constructor with initialization list
        tax_base(double ny = 0.185, double ss = 0.062)
            : ny_tax_rate(ny), ss_tax_rate(ss) {}

        // Destructor
        virtual ~tax_base() = default;

        // This is a pure virtual function - it just needs to be overloaded for 
            // the other two
        virtual double tax_withheld(double gross_pay) const = 0;

        // Getters
        double get_ny_tax_rate() const {return ny_tax_rate;}
        double get_ss_tax_rate() const {return ss_tax_rate;}
};

#endif