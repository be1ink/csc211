// Specification file for the ParkingTicket class
#ifndef PARKING_TICKET_H
#define PARKING_TICKET_H
#include "ParkedCar.h"

// Constant for the base fine.
const double BASE_FINE = 25.0;

// Constant for the additional hourly fine.
const double HOURLY_FINE = 10.0;

// ParkingTicket class
class ParkingTicket
{
private:
    ParkedCar car;    // The parked car
    double fine;      // The parking fine
    int minutes;      // Minutes illegally parked

    // calculateFine method
    // This method calculates the amount of the parking fine.
    double calculateFine()
    {
        double f;
        f = BASE_FINE + (HOURLY_FINE * minutes/60);
        return f;
    };

public:
    // Default Constructor
    ParkingTicket()
    {
        fine = 0.0;
        minutes = 0;
    }

    // Constructor
    ParkingTicket(ParkedCar c, int m)
    {
        car = c;
        minutes = m;
        fine = calculateFine();
    }

    // Copy constructor
    ParkingTicket(const ParkingTicket &other)
    {
        car = other.car;
        fine = other.fine;
        minutes = other.minutes;
    }

    // Mutators
    void setCar(ParkedCar c)
    {
        car = c;
    }

    void setMinutes(int m)
    {
        minutes = m;
    }

    void setFine()
    {
        fine = calculateFine();
    }

    // Accessors
    ParkedCar getCar() const
    {
        return car;
    }

    int getMinutes() const { return minutes;}

    double getFine() const
    {
        return fine;
    }

    // print function
    void print();
};

#endif