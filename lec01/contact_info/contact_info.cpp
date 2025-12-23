#include <iostream>
#include "contact_info.h"
using namespace std;

int main()
{
    // Define ContactInfo with data:
        // Name Kristen Lee, Phone #: 555-2021

    // string name_input;
    //char pn_input;
    //char* name_ptr = nullptr;
    //char* pn_ptr = nullptr;

    // cout << "Enter name: ";
    // cin >> name_input;
    // cout << endl;

    // cout << "Enter phone number: ";
    // cin >> pn_input;
    // cout << endl;

    // cout << name_input << endl;
    //cout << &name_input << endl;
    //cout << *name_ptr;

    //name_ptr = &name_input;
    //pn_ptr = &pn_input;

    //ContactInfo entry(&name_input, &pn_input);

    ContactInfo entry("Kristen Lee",  "555-2021");

    cout << "Contact Name: " << entry.getName() << endl;
    cout << "Phone Number: " << entry.getPhoneNumber() << endl;

    return 0;
}