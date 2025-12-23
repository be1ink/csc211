// CustomerData class
#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include <string>
#include "person_data.h"
using namespace std;

class CustomerData : public PersonData
{
private:
    int customerNumber;   // Customer number
    bool mailingList;     // Include in mailing list?

public:
    //*******************************************
    // Constructor
    //*******************************************
    CustomerData(string ln, string fn, string addr,
                 string c, string s, string z,
                 int cn, bool ml)
        : PersonData(ln, fn, addr, c, s, z)
    {
        customerNumber = cn;
        mailingList = ml;
    }

    //*******************************************
    // Default Constructor
    //*******************************************
    CustomerData() : PersonData()
    {
        customerNumber = 0;
        mailingList = false;
    }

    //*******************************************
    // Mutator functions
    //*******************************************
    void setCustomerNumber(int cn) { customerNumber = cn; }
    void setMailingList(bool ml) { mailingList = ml; }

    //*******************************************
    // Accessor functions
    //*******************************************
    int getCustomerNumber() const { return customerNumber; }
    bool getMailingList() const { return mailingList; }
};

#endif