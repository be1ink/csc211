// Benjamin Link
// CSC 211

#ifndef BUSINESS_H
#define BUSINESS_H

#include "employee.h"
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

class business : public tax_base
{
    private:
        map<int, employee> emp_lookup;
        vector<employee> employees;

    public:
        business(double ny = 0.185, double ss = 0.062) : tax_base(ny, ss) {}

        // Overriding pure virtual function to apply only SS taxes.
            // override keyword ensures this function is overridden in case
            // there was some mismatch with the earlier virtual function.
            // const in play to protect private attributes.
        double tax_withheld(double gross_pay) const override
            {return gross_pay * ss_tax_rate;}

        bool load_from_combined_file(const string& filename)
        {
            emp_lookup.clear();
            employees.clear();

            // Declare ifstream object
            ifstream input_file(filename);
            // Ensure ifstream object was succesfully created
            if(!input_file) {return false;}

            // Booleans help check which part of employee file is being ingested.
                // There are two sub-blocks to track - PII (personally identifiable
                // information) and pay
            bool reading_info = false;
            bool reading_pay = false;

            string data;

            // The data processing loop for employee data files.
            while(input_file >> data)
            {
                // Each key block of employee info starts with EmpID, so we
                    // move past it and process the second field title of the
                    // block - this dictates which kind of info we are about
                    // to ingest.
                if(data == "EmpID")
                {
                    string next;
                    // Ignores whitespace, so essentially takes the next field
                    input_file >> next;

                    // If next field is name, we are in the PII block
                    if(next == "Name")
                    {
                        reading_info = true;
                        reading_pay = false;

                        input_file >> data;
                        input_file >> data;
                        continue;
                    }
                    // If next field is HoursWk, we are in the pay block
                    else if(next == "HoursWk")
                    {
                        reading_info = false;
                        reading_pay = true;

                        input_file >> data;
                        continue;
                    }
                    else
                    {
                        reading_info = false;
                        reading_pay = false;
                        continue;
                    }
                }

                // If we are in the info block, begin processing data
                if(reading_info)
                {
                    int id = 0;
                    // Check to see if the ID is numerical, if not, don't process
                        // the row. catch (...) is a catchall handler that will
                        // prevent the program from crashing since it simply
                        // lets it continue past this corrupted row.
                    try {id = stoi(data);}
                    catch (...) {continue;}

                    // Another error check. I've got code that appends 0's if the
                        // ID is too small, like 203 --> 0203, but if the program
                        // is given 12033, then I'd consider that an error not
                        // worth processing (what if we truncate it into 
                        // someone's existing ID!)
                    if(id < 0 || id > 9999) {continue;}

                    // Grab first and last name, break from this if these aren't
                        // found
                    string first, last;
                    if(!(input_file >> first >> last)) {break;}

                    // Grab the associated information
                    string address = "";
                    string part = "";
                    string phone = "";

                    // part is used to flag if we are grabbing the address or
                        // phone number. Below, we search for dashes first since
                        // this distinguishes phone numbers easily in our file.
                        // In real world applications, we'd need a better rule,
                        // but I'm defaulting to this for simplicity. string::npos
                        // means nothing was found (no position - the search failed),
                        // so then it moves past, else it'll grab the part data
                        // and populate phone.
                    while(input_file >> part)
                    {
                        if(part.find('-') != string::npos)
                        {
                            phone = part;
                            break;
                        }

                        if(address != "") {address += " ";}
                        address += part;
                    }

                    // Add data to the employee structure
                    employee emp(id, first + " " + last, address, phone, 0.0, 0.0,
                                 ny_tax_rate, ss_tax_rate);

                    // Add the employee to our map
                    emp_lookup[id] = emp;
                }
                else if(reading_pay)
                {
                    int id = 0;
                    try {id = stoi(data);}
                    catch (...) {continue;}
                    if(id < 0 || id > 9999) {continue;}

                    double hours = 0.0;
                    double rate = 0.0;

                    if(!(input_file >> hours >> rate)) {break;}

                    // Establish iterator and point it to EmpID if available
                    auto it = emp_lookup.find(id);

                    // When using .find(key), the iterator automatically points
                        // to the end of the map if nothing is found, hence
                        // why emp_lookup.end() is used. If not found, add the
                        // new ID and associated data
                    if(it == emp_lookup.end())
                    {
                        employee emp(id, "", "", "", hours, rate, ny_tax_rate, ss_tax_rate);
                        emp_lookup[id] = emp;
                    }
                    // If the ID is found, simply update the key with the new
                        // data. Maps have elements that are structs called pairs.
                        // if->first grabs the key and it->second grabs the value.
                    else
                    {
                        // Add pay data to new employee object, populate previously
                            // established info with matched ID
                        employee emp = it->second;
                        // Uses employee class methods
                        emp = employee(emp.get_emp_id(), emp.get_name(), emp.get_address(), emp.get_phone(),
                                       hours, rate, ny_tax_rate, ss_tax_rate);
                        emp_lookup[id] = emp;
                    }
                }
            }

            // for range loop to pull off a classic map look up. Have the iterator
                // go from the beginning to end (end points off map) of map and
                // ensure all values are present. If so, append new data to 
                // employees registry. Do note, EmpID is both in the key and value
                // so it can be used for map functionality AND pulled out
            for(auto it = emp_lookup.begin(); it != emp_lookup.end(); ++it)
            {
                if(it->second.get_name() != "" && it->second.get_phone() != "" && it->second.get_address() != ""
                   && it->second.get_rate_of_pay() != 0.0)
                {
                    employees.push_back(it->second);
                }
            }

            return !employees.empty();
        }

        void sort_by_first_name()
        {
            // Use the sort algorithm on the employees vector
            sort(employees.begin(), employees.end(),
                // I've been so excited to try a functor. const used to prevent
                    // mutation of the employee object, and the referenced passed
                    // to prevent copies being generated.
                [](const employee& a, const employee& b)
                {
                    return a.get_first_name() < b.get_first_name();
                });
        }

        // Outputs a pointer to the emp_id, if found
        employee* find_by_id(int emp_id)
        {
            auto it = emp_lookup.find(emp_id);
            // Again, .find(key) will go to end if nothing found, so we check
                // here to see if it failed
            if(it == emp_lookup.end()) {return nullptr;}
            // Return the address to the data for the pointer to accept
            return &(it->second);
        }

        // Calculate aggregate numbers across employees using for range loops
        double total_gross() const
        {
            double total = 0.0;
            for(const auto& emp : employees) {total += emp.gross_pay();}
            return total;
        }
        double total_ny_tax() const
        {
            double total = 0.0;
            for(const auto& emp : employees) {total += emp.gross_pay() * ny_tax_rate;}
            return total;
        }
        double total_employee_ss() const
        {
            double total = 0.0;
            for(const auto& emp : employees) {total += emp.employee_ss_tax(emp.gross_pay());}
            return total;
        }
        double total_employer_ss() const
        {
            double total = 0.0;
            for(const auto& emp : employees) {total += emp.employer_ss_tax(emp.gross_pay());}
            return total;
        }
        double total_net() const
        {
            double total = 0.0;
            for(const auto& emp : employees) {total += emp.net_pay();}
            return total;
        }

        void print_sorted_report(ostream& out_file, int id_width) const
        {
            out_file << "Processed Payroll\n";
            // Nifty trick to have the horizontal lines match true length.
                // I wanted an easier way of getting everything to line up. It's
                // basically like how we fill vectors, put the size, then the element
                // you want filled.
            out_file << string((id_width + 2) + 10 + 18 + 14 + 8 + 9 + 11 + 10 + 9 + 11, '=') << "\n";

            out_file << left;
            out_file << setw(id_width + 2) << "EmpID";
            out_file << setw(10) << "FirstName";
            out_file << setw(18) << "Address";
            out_file << setw(14) << "Phone";

            out_file << right;
            out_file << setw(8)  << "Hours";
            out_file << setw(9)  << "Rate";
            out_file << setw(11) << "Gross";
            out_file << setw(10) << "NYTax";
            out_file << setw(9)  << "SS";
            out_file << setw(11) << "Net";
            out_file << "\n";

            out_file << string((id_width + 2) + 10 + 18 + 14 + 8 + 9 + 11 + 10 + 9 + 11, '-') << "\n";

            for(const auto& emp : employees)
            {
                emp.print_sorted_row(out_file, id_width);
            }

            out_file << string((id_width + 2) + 10 + 18 + 14 + 8 + 9 + 11 + 10 + 9 + 11, '=') << "\n\n";
        }

        bool write_sorted_report(const string& out_filename, int id_width) const
        {
            ofstream out_file(out_filename, ios::out);
            if(!out_file) {return false;}

            out_file << "\nProcessed Payroll\n";
            out_file << string((id_width + 2) + 10 + 18 + 14 + 8 + 9 + 11 + 10 + 9 + 11, '=') << "\n";

            out_file << left;
            out_file << setw(id_width + 2) << "EmpID";
            out_file << setw(10) << "FirstName";
            out_file << setw(18) << "Address";
            out_file << setw(14) << "Phone";

            out_file << right;
            out_file << setw(8)  << "Hours";
            out_file << setw(9)  << "Rate";
            out_file << setw(11) << "Gross";
            out_file << setw(10) << "NYTax";
            out_file << setw(9)  << "SS";
            out_file << setw(11) << "Net";
            out_file << "\n";

            out_file << string((id_width + 2) + 10 + 18 + 14 + 8 + 9 + 11 + 10 + 9 + 11, '-') << "\n";

            for(const auto& emp : employees)
            {
                emp.print_sorted_row(out_file, id_width);
            }

            out_file << string((id_width + 2) + 10 + 18 + 14 + 8 + 9 + 11 + 10 + 9 + 11, '=') << "\n\n";

            out_file << fixed << setprecision(2);
            out_file << left;
            out_file << setw(30) << "Total Gross Payroll:";      out_file << "$" << total_gross() << "\n";
            out_file << setw(30) << "Total NY Tax (18.5%):";     out_file << "$" << total_ny_tax() << "\n";
            out_file << setw(30) << "Total Employee SS (6.2%):"; out_file << "$" << total_employee_ss() << "\n";
            out_file << setw(30) << "Total Employer SS (6.2%):"; out_file << "$" << total_employer_ss() << "\n";
            out_file << setw(30) << "Total Net Pay:";            out_file << "$" << total_net() << "\n";

            return true;
        }

        void print_all_checks(ostream& out_file, int id_width) const
        {
            // Loop through all employees in the vector
            for(const auto& emp : employees)
            {
                emp.print_paycheck(out_file, id_width);
            }
        }

        void print_summary_sheet(ostream& out_file) const
        {
            out_file << "Employer Social Security Total & Payroll Summary Sheet\n";
            out_file << "======================================================\n";
            out_file << fixed << setprecision(2);

            out_file << left << setw(30) << "Total Gross Payroll:"        << "$" << total_gross() << "\n";
            out_file << left << setw(30) << "Total NY Tax (18.5%):"       << "$" << total_ny_tax() << "\n";
            out_file << left << setw(30) << "Total Employee SS (6.2%):"   << "$" << total_employee_ss() << "\n";
            out_file << left << setw(30) << "Total Employer SS (6.2%):"   << "$" << total_employer_ss() << "\n";
            out_file << left << setw(30) << "Total Net Pay:"              << "$" << total_net() << "\n";

            out_file << "======================================================\n\n";
        }
};

#endif