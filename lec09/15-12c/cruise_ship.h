// Design a CruiseShip class that is derived from the Ship class.
// The CruiseShip class should have the following members:

// • A member variable for the maximum number of passengers (an int)
// • A constructor and appropriate accessors and mutators
// • A print function that overrides the print function in the base class.
// The CruiseShip class’s print function should display only the ship’s name and 
// the maximum number of passengers.

#ifndef CRUISE_SHIP_H
#define CRUISE_SHIP_H
#include <iostream>
#include <string>
#include "ship.h"
using namespace std;

// Set access permissions to protected for a bit more security
class Cruise_Ship : public Ship
{
    private:
        int max_pass;
    public:
        // Constructor - one for simplicity. 
            // Initialize with Ship constructor in part
        Cruise_Ship() : Ship(), max_pass(0) {};

        // Use this default constructor if above code fails "Contents of Box.h":
        // Cruise_Ship() : Ship() {max_pass = 0;};

        // Mutators / Setters
        void set_max_pass(int c) {max_pass = c;} 

        // Accessors / Getters - const to ensure no changes to private members
        int get_max_pass() const {return max_pass;}

        // Virtual print function
        void display_ship() const override
        {
            cout << "Cruise Ship Details" << endl;
            cout << "-------------------" << endl;
            cout << "Name: " << Ship::get_name() << endl;
            cout << "Passengers Limit: " << get_max_pass() << endl << endl;
        }
};

#endif