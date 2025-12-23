#include <iostream>
#include "feet_inches_a.h"
using namespace std;

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
    cout << one << endl
         << two << endl
         << three << endl;

    return 0;
}