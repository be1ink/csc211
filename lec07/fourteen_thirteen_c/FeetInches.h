#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;

class FeetInches; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator<<(ostream &, const FeetInches &);
istream &operator>>(istream &, FeetInches &);

// The FeetInches class holds distances or measurements
// expressed in feet and inches.
class FeetInches
{
private:
    int feet;   // To hold a number of feet
    int inches; // To hold a number of inches
    void simplify(); // Defined in FeetInches.cpp

public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // Add a copy constructor to the FeetInches class. This constructor should accept 
    // a FeetInches object as an argument. The constructor should assign to the feet 
    // attribute the value in the argument’s feet attribute, and assign to the inches 
    // attribute the value in the argument’s inches attribute. As a result, the new 
    // object will be a copy of the argument object.
    // FeetInches(const FeetInches &obj); 
    
    FeetInches(const FeetInches &right)
    {
        feet = right.feet;
        inches = right.inches;
    }

    // Next, add a multiply member function to the FeetInches class. The multiply 
    // function should accept a FeetInches object as an argument. The argument 
    // object’s feet and inches attributes will be multiplied by the calling 
    // object’s feet and inches attributes, and a FeetInches object containing 
    // the result will be returned.
    FeetInches multiply(const FeetInches &obj)
    {
        FeetInches result;
        result.feet = feet * obj.feet;
        result.inches = inches * obj.inches;
        // result.simplify(); // optional per your assignment
        return result;
    }

    // Mutators
    void setFeet(int f) { feet = f; }
    void setInches(int i) { inches = i; simplify(); }

    // Accessors
    int getFeet() const { return feet; }
    int getInches() const { return inches; }

    // Overloaded operator functions
    FeetInches operator+(const FeetInches &);
    FeetInches operator-(const FeetInches &);
    FeetInches &operator++();
    FeetInches operator++(int);
    bool operator>(const FeetInches &);
    bool operator<(const FeetInches &);
    bool operator==(const FeetInches &);
    // friend keyword needed as .cpp implementation accesses private
    // attributes and functions without getters
    friend ostream &operator<<(ostream &, const FeetInches &);
    friend istream &operator>>(istream &, FeetInches &);

    // Conversions
    operator double() const;
    operator int() const;
};

#endif