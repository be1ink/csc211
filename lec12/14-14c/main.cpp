#include <iostream>
#include <iomanip>
#include <string>
#include "PoliceOfficer.h"
using namespace std;

// Function prototypes
ParkedCar input_car_details();
ParkingMeter input_meter_details(ParkedCar);
ParkingTicket calc_ticket(ParkedCar, ParkingMeter);
PoliceOfficer input_officer_details();

int main()
{
    ParkedCar car;
    ParkingMeter meter;
    ParkingTicket ticket;
    PoliceOfficer officer;

    car = input_car_details();
    meter = input_meter_details(car);
    ticket = calc_ticket(car, meter);
    officer = input_officer_details();

    return 0;
}

// Function definitions
ParkedCar input_car_details()
{
    ParkedCar p;
    string make;
    string model;
    string color;
    string license;
    int minutes;

    cout << "Welcome to the car lot A21 ticketing system.\n";
    cout << "Please input your car details:\n";

    cout << " - Make: ";
    cin >> make;
    p.setMake(make);

    cout << " - Model: ";
    cin >> model;
    p.setModel(model);

    cout << " - Color: ";
    cin >> color;
    p.setColor(color);

    cout << " - License Plate: ";
    cin >> license;
    p.setLicenseNumber(license);

    cout << " - Minutes Parked: ";
    cin >> minutes;
    p.setMinutesParked(minutes);

    return p;
}

ParkingMeter input_meter_details(ParkedCar car)
{
    ParkingMeter p;

    p.setMinutesPurchased((car.getMinutesParked()-car.getMinutesParked()/3));
    cout << endl;
    p.print();

    return p;
}

ParkingTicket calc_ticket(ParkedCar c, ParkingMeter p)
{
    ParkingTicket ticket;

    // Minutes over
    ticket.setMinutes(c.getMinutesParked() - p.getMinutesPurchased());
    
    cout << "\nUh oh, the driver was over time by ";
    cout << ticket.getMinutes() << " minutes.\n";

    ticket.setFine();

    cout << "\nFine owed: $" << fixed << setprecision(2) << ticket.getFine();

    return ticket;
}

// New function for officer input
PoliceOfficer input_officer_details()
{
    PoliceOfficer officer;
    string name;
    string badge;

    cout << "\n\nPlease input the police officer's details:\n";

    cout << " - Name: ";
    cin >> name;
    officer.setName(name);

    cout << " - Badge Number: ";
    cin >> badge;
    officer.setBadgeNumber(badge);

    cout << "\nOfficer on duty: " 
         << officer.getName()
         << " (Badge " << officer.getBadgeNumber() << ")\n";

    return officer;
}