// 13. Carpet Calculator

// The Westfield Carpet Company has asked you to write an application that 
// calculates the price of carpeting for rectangular rooms. To calculate the 
// price, you multiply the area of the floor (width times length) by the price 
// per square foot of carpet. For example, the area of floor that is 12 feet long 
// and 10 feet wide is 120 square feet. To cover that floor with carpet that 
// costs $8 per square foot would cost $960. (12 × 10 × 8 = 960.)

// First, you should create a class named RoomDimension that has two FeetInches 
// objects as attributes: one for the length of the room, and one for the width. 
// (You should use the version of the FeetInches class you created in Programming 
// Challenge 11 with the addition of a multiply member function. You can use this 
// function to calculate the area of the room.) The RoomDimension class should 
// have a member function that returns the area of the room as a FeetInches object.

// Next, you should create a RoomCarpet class that has a RoomDimension object 
// as an attribute. It should also have an attribute for the cost of the carpet 
// per square foot. The RoomCarpet class should have a member function that 
//returns the total cost of the carpet.

// Chapter 14, Programming Challenge 13: Carpet Calculator
#include <iostream>
#include <iomanip>
#include "FeetInches.h"
#include "RoomDimension.h"
#include "RoomCarpet.h"
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

// Implemented data type conversions
FeetInches::operator double() const
{
    return feet + inches / 12.0;   // total feet as a double
}

FeetInches::operator int() const
{
    return feet * 12 + inches;     // total inches as an int (common choice)
}

int main()
{
    // Declare variables:
    FeetInches length, width;
    double costPerFoot;

    // Get the room's length.
    cout << "Enter the length in two integers separated by a space (feet inches): ";
    cin >> length;
    cout << length << endl;
   
    // The the room's width.
    cout << "Enter the width in two integers separated by a space (feet inches): ";
    cin >> width;
    cout << width << endl << endl;

    // Calculate cost for a room.
    cout << "What is the cost of the carpet per foot?: $";
    cin >> costPerFoot;
    cout << endl;
    RoomDimension room1(length, width);
    RoomCarpet carpet1(room1, costPerFoot);

    // Display cost
    cout << fixed << setprecision(2);
    cout << "The total cost of the carpet is: $" << carpet1.getTotalCost() << endl;
    
    // Show off copy constructor
    RoomDimension room2 = room1;

    return 0;
}