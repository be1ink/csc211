// Specification file for the PoliceOfficer class
#ifndef POLICE_OFFICER_H
#define POLICE_OFFICER_H

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"

// PoliceOfficer class
class PoliceOfficer
{
private:
    string name;            // Officer's name
    string badgeNumber;     // Badge number
    ParkingTicket *ticket;  // Pointer to a ticket

public:
    // Default constructor
    PoliceOfficer()
    {
        name = "";
        badgeNumber = "";
        ticket = nullptr;
    }

    // Constructor
    // The parameter n is the officer's name.
    // The parameter bn is the officer's badge number.
    PoliceOfficer(string n, string bn)
    {
        name = n;
        badgeNumber = bn;
        ticket = nullptr;
    }

    // Copy constructor
    PoliceOfficer(const PoliceOfficer &officer2)
    {
        name = officer2.name;
        badgeNumber = officer2.badgeNumber;
        ticket = new ParkingTicket(*officer2.ticket);
    }

    // Mutators
    void setName(string n)
    {
        name = n;
    }

    void setBadgeNumber(string b)
    {
        badgeNumber = b;
    }

    // Accessors
    string getName() const
    {
        return name;
    }

    string getBadgeNumber() const
    {
        return badgeNumber;
    }

    // patrol function
    ParkingTicket *patrol(ParkedCar, ParkingMeter);

    // print function
    void print();
};

#endif