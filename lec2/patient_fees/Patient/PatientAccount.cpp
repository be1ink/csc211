// Implementation file for the PatientAccount class
#include "PatientAccount.h"
#include <iostream>
using namespace std;

// Daily room rate
const double DAILY_RATE = 500.00;

//**********************************************************
// Default constructor                                     *
//**********************************************************

PatientAccount::PatientAccount()
{
   days = 0;
   charges = 0.00;
}

//**********************************************************
// setDays member function                                 *
//**********************************************************

void PatientAccount::setDays()
{
   // Get the number of days in the hospital.
   cout << "How many days was the patient in the hospital?  ";
   cin >> days;

   // Validate it.
   while (days < 0)
   {  
      cout << "Days must be 0 or more. Please re-enter: ";
      cin  >> days;
   }

   // Update charges.
   charges += days * DAILY_RATE;
}

//**********************************************************
// updateCharges member function                           *
//**********************************************************

void PatientAccount::updateCharges(double newCharge)
{   
   charges += newCharge;
}


//**********************************************************
// getCharges member function                              *
//**********************************************************

double PatientAccount::getCharges()
{
   return charges;
}