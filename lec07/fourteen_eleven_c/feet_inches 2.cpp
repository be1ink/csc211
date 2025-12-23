// 11. FeetInches Class Copy Constructor and multiply Function

// Implementation file for the FeetInches class
#include <cstdlib> // Needed for abs()
#include <iostream>
#include "feet_inches.h"
using namespace std;

//**************************************************************
// Definition of member function simplify. This function
// checks for values in the inches member greater than
// twelve or less than zero. If such a value is found,
// the numbers in feet and inches are adjusted to conform
// to a standard feet & inches expression. For example,
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and
// 5 feet -2 inches would be adjusted to 4 feet 10 inches.
//**************************************************************
void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

//**************************************************************
// Copy constructor
//**************************************************************
FeetInches::FeetInches(const FeetInches &obj)
{
    feet = obj.feet;
    inches = obj.inches;
    simplify();  // Normalizes copied data, optional but fine
}

//**********************************************
// Overloaded binary + operator.
//**********************************************
FeetInches FeetInches::operator+(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

//**********************************************
// Overloaded binary - operator.
//**********************************************
FeetInches FeetInches::operator-(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

//**************************************************************
// Overloaded stream insertion operator
//**************************************************************
ostream &operator<<(ostream &out, const FeetInches &x)
{
    out << x.feet << " feet, " << x.inches << " inches";
    return out;
}

//**************************************************************
// Overloaded stream extraction operator
//**************************************************************
istream &operator>>(istream &in, FeetInches &x)
{
    // cout << "Enter feet: ";
    in >> x.feet;
    // cout << "Enter inches: ";
    in >> x.inches;
    x.simplify();
    return in;
}

//**************************************************************
// Main function to test the FeetInches class
//**************************************************************
int main()
{
    // Create three FeetInches objects.
    FeetInches one, two, three;

    // Get a distance for the first object.
    cout << "Enter a distance in feet and inches: ";
    cin >> one;

    // Make the second object a copy of the first.
    two = one;

    // Call the multiply function to get an object
    // for the third.
    three = one.multiply(two);

    // Display the object values.
    cout << one << endl;
    cout << two << endl;
    cout << three << endl;

    return 0;
}