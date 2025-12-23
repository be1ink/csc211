// Design a Ship class that has the following members:
// • A member variable for the name of the ship (a string)
// • A member variable for the year that the ship was built (a string)
// • A constructor and appropriate accessors and mutators
// • A virtual print function that displays the ship’s name and the year it was 
// built.

#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <string>
using namespace std;

class Ship
{
    protected:
        string name;
        int year;
    public:
        // Constructor - one for simplicity
        Ship() : name("Default"), year(9999) {};

        // Destructor
        virtual ~Ship() = default;

        // Mutators / Setters
        void set_name(string n) {name = n;} 
        void set_year(int y) {year = y;}

        // Accessors / Getters - const to ensure no changes to private members
        string get_name() const {return name;}
        int get_year() const {return year;}

        // Virtual print function
        virtual void display_ship() const
        {
            cout << "Ship Details" << endl;
            cout << "------------" << endl;
            cout << "Name: " << get_name() << endl;
            cout << "Year: " << get_year() << endl << endl;
        }
};

#endif