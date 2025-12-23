// Specification file for the ParkingMeter class
#ifndef PARKING_METER_H
#define PARKING_METER_H

#include <iostream>
using namespace std;

// ParkingMeter class
class ParkingMeter
{
private:
    int minutesPurchased;   // Minutes purchased

public:
    // Default constructor
    ParkingMeter()
    { 
        minutesPurchased = 0; 
    }

    // Constructor. The parameter m is the number of minutes purchased.
    ParkingMeter(int m)
    { 
        minutesPurchased = m; 
    }

    // Mutator
    void setMinutesPurchased(int m)
    { 
        minutesPurchased = m; 
    }

    // Accessor
    int getMinutesPurchased() const
    { 
        return minutesPurchased; 
    }

    // print function
    void print()
    {
        cout << "Meter Information:\n";
        cout << "\tMinutes Purchased: " 
             << minutesPurchased << endl;
    }
};

#endif