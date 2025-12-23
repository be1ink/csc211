// Benjamin Link
// CSC 211

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "tax.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class employee : public tax_base
{
    private:
        struct emp_record
        {
            int emp_id = 0;
            string name;
            string address;
            string phone;
            double hours_wk = 0.0;
            double rate_of_pay = 0.0;
        };

        emp_record rec;

        string first_name_basic(const string& s) const
        {
            string first = "";
            for(int i = 0; i < static_cast<int>(s.length()); i++)
            {
                if(s[i] == ' ') {break;}
                first += s[i];
            }
            return first;
        }

    public:
        // Default constructor
        employee() : tax_base() {}

        // Overloaded constructor
        employee(int emp_id, string name, string address, string phone, 
            double hours_wk, double rate_of_pay, double ny = 0.185, 
            double ss = 0.062) : tax_base(ny, ss)
        {
            rec.emp_id = emp_id;
            rec.name = name;
            rec.address = address;
            rec.phone = phone;
            rec.hours_wk = hours_wk;
            rec.rate_of_pay = rate_of_pay;
        }
        // Getters
        int get_emp_id() const {return rec.emp_id;}
        string get_name() const {return rec.name;}
        string get_address() const {return rec.address;}
        string get_phone() const {return rec.phone;}
        double get_hours_wk() const {return rec.hours_wk;}
        double get_rate_of_pay() const {return rec.rate_of_pay;}
        string get_first_name() const {return first_name_basic(rec.name);}

        // Ensures that there are always four digits to an ID. Takes advantage
            // of the string class's .insert operator. I apply this each time
            // the program outputs an ID.
        static string to_padded_id(int id_num, int width)
        {
            string s = to_string(id_num);
            if(static_cast<int>(s.length()) < width)
            {
                s.insert(0, width - static_cast<int>(s.length()), '0');
            }
            return s;
        }

        double gross_pay() const
        {
            // Overtime rate - made constant as it shouldn't be mutable
            const double ot_mult = 1.5;

            // Overtime not triggered
            if(rec.hours_wk <= 40.0)
                {return rec.hours_wk * rec.rate_of_pay;}

            // Else, calculate regular pay for 40 hours, then additonal OT pay
            double reg = 40.0 * rec.rate_of_pay;
            double ot  = (rec.hours_wk - 40.0) * rec.rate_of_pay * ot_mult;

            return reg + ot;
        }

        // Helper functions

        // Calc taxes and impact on net pay
        double employee_ss_tax(double gross) const {return gross * ss_tax_rate;}
        double employer_ss_tax(double gross) const {return gross * ss_tax_rate;}

        // Overriding pure virtual function to apply NYS and SS taxes
            // override keyword ensures this function is overridden in case
            // there was some mismatch with the earlier virtual function.
            // const in play to protect private attributes.
        double tax_withheld(double gross_pay) const override
            {return (gross_pay * ny_tax_rate) + (gross_pay * ss_tax_rate);}
        double net_pay() const
        {
            double gross = gross_pay();
            return gross - tax_withheld(gross);
        }

        void print_paycheck(ostream& out_file, int id_width) const
        {
            double gross = gross_pay();
            double ny_tax = gross * ny_tax_rate;
            double ss_emp = gross * ss_tax_rate;
            double net = gross - (ny_tax + ss_emp);

            out_file << "============================================================\n";
            out_file << "                         PAY STUB\n";
            out_file << "============================================================\n";
            out_file << "EMPLOYEE: " << rec.name << "\n";
            out_file << "EMP ID:   " << to_padded_id(rec.emp_id, id_width) << "\n";
            out_file << "ADDRESS:  " << rec.address << "\n";
            out_file << "PHONE:    " << rec.phone << "\n";
            out_file << "------------------------------------------------------------\n";
            out_file << fixed << setprecision(2);

            out_file << left;
            out_file << setw(20) << "EARNINGS";
            out_file << setw(14) << "HOURS";
            out_file << setw(14) << "RATE";
            out_file << setw(14) << "AMOUNT";
            out_file << "\n";

            out_file << left;
            out_file << setw(20) << "Regular/OT";
            out_file << setw(14) << rec.hours_wk;
            out_file << setw(14) << rec.rate_of_pay;
            out_file << setw(14) << gross;
            out_file << "\n";

            out_file << "------------------------------------------------------------\n";

            out_file << left;
            out_file << setw(20) << "DEDUCTIONS";
            out_file << setw(14) << "";
            out_file << setw(14) << "RATE";
            out_file << setw(14) << "AMOUNT";
            out_file << "\n";

            out_file << left;
            out_file << setw(20) << "NY Tax";
            out_file << setw(14) << "";
            out_file << setw(14) << (ny_tax_rate * 100.0);
            out_file << setw(14) << ny_tax;
            out_file << "\n";

            out_file << left;
            out_file << setw(20) << "Social Security";
            out_file << setw(14) << "";
            out_file << setw(14) << (ss_tax_rate * 100.0);
            out_file << setw(14) << ss_emp;
            out_file << "\n";

            out_file << "------------------------------------------------------------\n";

            out_file << left;
            out_file << setw(20) << "NET PAY";
            out_file << setw(14) << "";
            out_file << setw(14) << "";
            out_file << setw(14) << net;
            out_file << "\n";

            out_file << "============================================================\n\n";
        }

        void print_sorted_row(ostream& out_file, int id_width) const
        {
            double gross = gross_pay();
            double ny_tax = gross * ny_tax_rate;
            double ss_emp = gross * ss_tax_rate;
            double net = gross - (ny_tax + ss_emp);

            out_file << left;
            out_file << setw(id_width + 2) << to_padded_id(rec.emp_id, id_width);
            out_file << setw(10) << get_first_name();
            out_file << setw(18) << rec.address;
            out_file << setw(14) << rec.phone;

            out_file << right << fixed << setprecision(2);
            out_file << setw(8)  << rec.hours_wk;
            out_file << setw(9)  << rec.rate_of_pay;
            out_file << setw(11) << gross;
            out_file << setw(10) << ny_tax;
            out_file << setw(9)  << ss_emp;
            out_file << setw(11) << net;

            out_file << "\n";
        }
};

#endif