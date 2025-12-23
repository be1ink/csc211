// This program is a driver that tests a function comparing the
// contents of two int arrays.
#include <iostream>
#include <vector>
using namespace std;

// Function Prototype
bool testPIN(vector<short>, vector<short>);

int main ()
{
    const int NUM_DIGITS = 7; // Number of digits in a PIN
    vector<short> pin1 (NUM_DIGITS); {2, 4, 1, 8, 7, 9, 0;} // Base set of values.
    vector<short> pin2 (NUM_DIGITS); {2, 4, 6, 8, 7, 9, 0;} // Only 1 element is different from pin1.
    vector<short> pin3 (NUM_DIGITS); {1, 2, 3, 4, 5, 6, 7;} // All elements are different from pin1.
    // int pin1[NUM_DIGITS] = {2, 4, 1, 8, 7, 9, 0}; // Base set of values.
    // int pin2[NUM_DIGITS] = {2, 4, 6, 8, 7, 9, 0}; // Only 1 element is different from pin1.
    // int pin3[NUM_DIGITS] = {1, 2, 3, 4, 5, 6, 7}; // All elements are different from pin1.

    if (testPIN(pin1, pin2))
        cout << "ERROR: pin1 and pin2 report to be the same.\n";
    else
        cout << "SUCCESS: pin1 and pin2 are different.\n";

    if (testPIN(pin1, pin3))
        cout << "ERROR: pin1 and pin3 report to be the same.\n";
    else
        cout << "SUCCESS: pin1 and pin3 are different.\n";

    if (testPIN(pin1, pin1))
        cout << "SUCCESS: pin1 and pin1 report to be the same.\n";
    else
        cout << "ERROR: pin1 and pin1 report to be different.\n";

    return 0;
}

bool testPIN(vector<short> custPin, vector<short> databasePin)
{
    bool status = true;
    
    for (short ndx = 0; ndx < 7; ndx++)
    {
        if (custPin[ndx] != databasePin[ndx])
        
        status = false; // We've found two different values.
    }
    return status; // If we make it this far, the values are the same.
}

// bool testPIN(const int custPIN[], const int databasePIN[], int size)
// {
//     for (int index = 0; index < size; index++)
//     {
//         if (custPIN[index] != databasePIN[index])
//             return false; // We've found two different values.
//     }
//     return true; // If we make it this far, the values are the same.
// }