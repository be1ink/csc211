// Specification file for the ParkedCar class
#ifndef PARKED_CAR_H
#define PARKED_CAR_H

#include <string>
using namespace std;

// ParkedCar class
class ParkedCar
{
private:
    string make;            // The car's make
    string model;           // The car's model
    string color;           // The car's color
    string licenseNumber;   // The car's license number
    int minutesParked;      // Minutes parked

public:
    // Default constructor
    ParkedCar()
    {
        make = "";
        model = "";
        color = "";
        licenseNumber = "";
        minutesParked = 0;
    }

    // Constructor
    ParkedCar(string mk, string md, string c, string lic, int m)
    {
        make = mk;
        model = md;
        color = c;
        licenseNumber = lic;
        minutesParked = m;
    }

    // Copy constructor
    ParkedCar(const ParkedCar &other)
    {
        make = other.make;
        model = other.model;
        color = other.color;
        licenseNumber = other.licenseNumber;
        minutesParked = other.minutesParked;
    }

    // Mutators
    void setMake(string m)          { make = m; }
    void setModel(string m)         { model = m; }
    void setColor(string c)         { color = c; }
    void setLicenseNumber(string lic) { licenseNumber = lic; }
    void setMinutesParked(int m)    { minutesParked = m; }

    // Accessors
    string getMake() const          { return make; }
    string getModel() const         { return model; }
    string getColor() const         { return color; }
    string getLicenseNumber() const { return licenseNumber; }
    int getMinutesParked() const    { return minutesParked; }

    // Print function
    void print();
};

#endif