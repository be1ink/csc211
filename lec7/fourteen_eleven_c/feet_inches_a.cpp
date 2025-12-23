// Implementation file for the FeetInches class
#include <cstdlib>     // Needed for abs()
#include "feet_inches_a.h"

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
// Overloaded binary + operator.
//**************************************************************
FeetInches FeetInches::operator+(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

//**************************************************************
// Overloaded binary - operator.
//**************************************************************
FeetInches FeetInches::operator-(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

//**************************************************************
// Overloaded prefix ++ operator.
//**************************************************************
FeetInches FeetInches::operator++()
{
    ++inches;
    simplify();
    return *this;
}

//**************************************************************
// Overloaded postfix ++ operator.
//**************************************************************
FeetInches FeetInches::operator++(int)
{
    FeetInches temp(feet, inches);
    inches++;
    simplify();
    return temp;
}

//**************************************************************
// Overloaded > operator.
//**************************************************************
bool FeetInches::operator>(const FeetInches &right)
{
    bool status;

    if (feet > right.feet)
        status = true;
    else if (feet == right.feet && inches > right.inches)
        status = true;
    else
        status = false;

    return status;
}

//**************************************************************
// Overloaded < operator.
//**************************************************************
bool FeetInches::operator<(const FeetInches &right)
{
    bool status;

    if (feet < right.feet)
        status = true;
    else if (feet == right.feet && inches < right.inches)
        status = true;
    else
        status = false;

    return status;
}

//**************************************************************
// Overloaded == operator.
//**************************************************************
bool FeetInches::operator==(const FeetInches &right)
{
    bool status;

    if (feet == right.feet && inches == right.inches)
        status = true;
    else
        status = false;

    return status;
}

//**************************************************************
// Overloaded >= operator.
//**************************************************************
bool FeetInches::operator>=(const FeetInches &right)
{
    bool status;

    if ((*this > right) || (*this == right))
        status = true;
    else
        status = false;

    return status;
}

//**************************************************************
// Overloaded <= operator.
//**************************************************************
bool FeetInches::operator<=(const FeetInches &right)
{
    bool status;

    if ((*this < right) || (*this == right))
        status = true;
    else
        status = false;

    return status;
}

//**************************************************************
// Overloaded != operator.
//**************************************************************
bool FeetInches::operator!=(const FeetInches &right)
{
    bool status;

    if (*this == right)
        status = false;
    else
        status = true;

    return status;
}

//**************************************************************
// Overloaded << operator.
//**************************************************************
ostream &operator<<(ostream &strm, const FeetInches &obj)
{
    strm << obj.feet << " feet, " << obj.inches << " inches";
    return strm;
}

//**************************************************************
// Overloaded >> operator.
//**************************************************************
istream &operator>>(istream &strm, FeetInches &obj)
{
    cout << "Feet: ";
    strm >> obj.feet;

    cout << "Inches: ";
    strm >> obj.inches;

    obj.simplify();
    return strm;
}

//**************************************************************
// Conversion function to convert a FeetInches object to a double.
//**************************************************************
FeetInches::operator double()
{
    double temp = feet;
    temp += (inches / 12.0);
    return temp;
}

//**************************************************************
// Conversion function to convert a FeetInches object to an int.
//**************************************************************
FeetInches::operator int()
{
    return feet;
}