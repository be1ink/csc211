// PersonData class
#ifndef PERSONDATA_H
#define PERSONDATA_H
#include <string>
using namespace std;

class PersonData
{
private:
    string lastName;   // The person's last name
    string firstName;  // The person's first name
    string address;    // The person's address
    string city;       // The person's city
    string state;      // The person's state
    string zip;        // The person's ZIP code

public:
    //*******************************************
    // Constructor
    //*******************************************
    PersonData(string ln, string fn, string addr,
               string c, string s, string z)
    {
        lastName = ln;
        firstName = fn;
        address = addr;
        city = c;
        state = s;
        zip = z;
    }

    //*******************************************
    // Default Constructor
    //*******************************************
    PersonData()
    {
        lastName = "";
        firstName = "";
        address = "";
        city = "";
        state = "";
        zip = "";
    }

    //*******************************************
    // Mutator functions
    //*******************************************
    void setLastName(string ln) { lastName = ln; }
    void setFirstName(string fn) { firstName = fn; }
    void setAddress(string addr) { address = addr; }
    void setCity(string c) { city = c; }
    void setState(string s) { state = s; }
    void setZip(string z) { zip = z; }

    //*******************************************
    // Accessor functions
    //*******************************************
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
};

#endif