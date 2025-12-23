// Implementation file for the Pharmacy class
#include "Pharmacy.h"

//***********************************************************
// Default constructor                                      *
//***********************************************************

Pharmacy::Pharmacy()
{
   price1 = 10.00;    // set prices for medicine types 1-5
   price2 = 20.00;
   price3 = 30.00;
   price4 = 40.00;
   price5 = 50.00;
}

//***********************************************************
// updateAccount member function                            *
//***********************************************************

void Pharmacy::updateAccount(PatientAccount& pt, int type)
{
   switch (type)
   {  
      case 1:  pt.updateCharges(price1);
             break;
      case 2:  pt.updateCharges(price2);
             break;
      case 3:  pt.updateCharges(price3);
             break;
      case 4:  pt.updateCharges(price4);
             break;
      case 5:  pt.updateCharges(price5);
             break;
      default: ; // Do not add any charge to the account.
   }
}