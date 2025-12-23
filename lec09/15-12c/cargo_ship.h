// Design a CargoShip class that is derived from the Ship class.
// The CargoShip class should have the following members:

// • A member variable for the cargo capacity in tonnage
// • A constructor and appropriate accessors and mutators
// • A print function that overrides the print function in the base class.
// The CargoShip class’s print function should display only the ship’s name and
// the ship’s cargo capacity.

#ifndef CARGO_SHIP_H
#define CARGO_SHIP_H
#include <iostream>
#include <iomanip>
#include <string>
#include "ship.h"
using namespace std;

// Set access permissions to protected for a bit more security
class Cargo_Ship : public Ship
{
    private:
        double capacity;
    public:
        // Constructor - one for simplicity. 
            // Initialize with Ship constructor in part
        Cargo_Ship() : Ship(), capacity(0.0) {};

        // Use this default constructor if above code fails "Contents of Box.h":
        // Cargo_Ship() : Ship() {capacity = 0;};

        // Mutators / Setters
        void set_capacity(double c) {capacity = c;} 

        // Accessors / Getters - const to ensure no changes to private members
        double get_capacity() const {return capacity;}

        // Virtual print function
        void display_ship() const override
        {
            cout << fixed << setprecision(2);
            cout << "Cargo Ship Details" << endl;
            cout << "------------------" << endl;
            cout << "Name: " << Ship::get_name() << endl;
            cout << "Cargo Capacity: " << get_capacity() << endl << endl;
        }
};

#endif