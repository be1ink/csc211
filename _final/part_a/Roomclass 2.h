// Author: Benjamin Link
// Class: CSC 211

#ifndef ROOMCLASS_H
#define ROOMCLASS_H

#include <iostream>
#include <iomanip>
using namespace std;

class Roomclass
{
    private:
        double length;
        double width;
        double height;
    public:
        // default constructor using list initialization
        Roomclass() : length(0.0), width(0.0), height(0.0) {};

        // overloaded constructor with user inputs
        Roomclass(double l, double w, double h)
        {
            length = l; width = w; height = h;
        }

        // destructor using default keyword (means {})
        ~Roomclass() = default;

        // Functions
        double area_calc(double l, double w) {return l * w;}
        double volume_calc(double l, double w, double h) {return l * w * h;}
        double btu_calc(double sq) {return sq * 20.0;}

        // setters
        void set_length(double l) {length = l;}
        void set_width(double w) {width = w;}
        void set_height(double h) {height = h;}

        // getters with const to prevent modification of private attributes
        double get_length() const {return length;}
        double get_width() const {return width;}
        double get_height() const {return height;}
};

#endif