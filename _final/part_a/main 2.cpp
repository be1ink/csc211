// Author: Benjamin Link
// Class: CSC 211

// Write a C++ program to do the following.
// You must use class and header file (Roomclass.h).
// Ask the user for Length, Width and Height. 

// Find the area and volume of living room and kitchen which the user will input.
// Calculate the BTU heating and cooling capacity (20 BTUs per square foot)?

// The heat transfer formula is Q = M x Cp x ΔT.

// BTU/hr = Sq. Ft. x Height x Temp Diff x 0.133/0.135
// BTU/hr = Square Footage x ~20 BTUs 

// Do not copy code. Work must be original and authenticated.
// Submission must include name in program, UML, picture of working program and ALL codes.

#include <iostream>
#include <iomanip>
#include <limits>
#include "Roomclass.h"
using namespace std;

// Function prototypes
double get_double();
void room_inputs(string, Roomclass&);
void room_stats(string, Roomclass);

int main()
{
    // Declare variables;
    //double length = 0.0, width = 0.0, height = 0.0;
    string room_name;

    // Living room inputs
    room_name = "Living room";
    Roomclass living_room;
    room_inputs(room_name, living_room);
    room_stats(room_name, living_room);

    // Kitchen inputs
    room_name = "Kitchen";
    Roomclass kitchen;
    room_inputs(room_name, kitchen);
    room_stats(room_name, kitchen);

    return 0;
}

// Function definitions
double get_double()
{
    double num = 0;
    while(true)
    {
        if(cin >> num && cin.peek() == '\n' && num >= 0.0) {return num;}
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "\nInvalid input. Please input the number of feet: ";    }
}

void room_inputs(string n, Roomclass &r)
{
    cout << "\nHello, please input your " << n << "'s dimensions: \n";
    cout << "Please input the length of your room in feet: ";
    r.set_length(get_double());
    cout << "Please input the width of your room in feet: ";
    r.set_width(get_double());
    cout << "Please input the height of your room in feet: ";
    r.set_height(get_double());
}

void room_stats(string n, Roomclass r)
{
    // Declare variables
    double area = 0.0;
    double volume = 0.0;

    cout << fixed << setprecision(2);
    cout << "\n" << n << " Statistics: \n";
    cout << "Length: " << r.get_length() << " ft" << endl;
    cout << "Width: " << r.get_width() << " ft" << endl;
    cout << "Height: " << r.get_height() << " ft" << endl;

    // Calculations
    area = r.area_calc(r.get_length(), r.get_width());
    volume = r.volume_calc(r.get_length(), r.get_width(), r.get_height());

    cout << "Area: " << area << " ft^2" << endl;
    cout << "Volume: " << volume << " ft^3" << endl;
    cout << "Room heating capacity: " << r.btu_calc(area) << " BTU's" << endl;
}