// Specification file for the PatientAccount class
#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

class PatientAccount
{
private:
   double charges;
   int   days;
public:
   PatientAccount();
   void  setDays();
   void  updateCharges(double);
   double getCharges();
};

#endif