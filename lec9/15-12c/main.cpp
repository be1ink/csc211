// Demonstrate the classes in a program that has an array of Ship pointers.
// The array elements should be initialized with the addresses of dynamically 
// allocated Ship, CruiseShip, and CargoShip objects.
// (See Program 15–14, lines 17 through 22, for an example of how to do this.)
// The program should then step through the array, calling each object’s print 
// function.

#include <iostream>
#include <string>
#include "ship.h"
#include "cruise_ship.h"
#include "cargo_ship.h"

int main()
{
    const int NUM_SHIPS = 3;

    Ship* ships[NUM_SHIPS] = 
        {
            new Ship(),
            new Cruise_Ship(),
            new Cargo_Ship()
        };

    for(int i = 0; i < NUM_SHIPS; ++i)
    {
        // Method 1
        ships[i]->display_ship();
        // Method 2
        (*ships[i]).display_ship();
    }

    // Release dynamic memory
    for (int i = 0; i < NUM_SHIPS; ++i) {delete ships[i];}

    return 0;
}