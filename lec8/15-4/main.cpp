// This program demonstrates the order in which base and derived class
// constructors and destructors are called.

#include <iostream>
using namespace std;

// Base Class Declaration

class BaseClass
{
    public:
        // Constructor
        BaseClass()
        {
            cout << "This is the BaseClass constructor.\n";
        }

        // Destructor
        ~BaseClass()
        {
            cout << "This is the BaseClass destructor.\n";
        }
};

class DerivedClass : public BaseClass
{
    public:
        // Constructor
        DerivedClass()
        {
            cout << "This is the DerivedClass constructor.\n";
        }

        // Destructor
        ~DerivedClass()
        {
            cout << "This is the DerivedClass destructor.\n";
        }
};

int main()
{
    cout << "We will now define a DerivedClass object.\n";

    DerivedClass object;

    cout << "The program is now going to end.\n";

    return 0;
}