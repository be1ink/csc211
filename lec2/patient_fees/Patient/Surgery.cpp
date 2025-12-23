// Implementation file for the Surgery class
#include "Surgery.h"

//**********************************************************
// Default constructor                                     *
//**********************************************************

Surgery::Surgery()
{
   rate1 = 100.00;    // set rates for suregery types 1-5
   rate2 = 200.00;
   rate3 = 300.00;
   rate4 = 400.00;
   rate5 = 500.00;
}

//**********************************************************
// updateAccount member function                           *
//**********************************************************

void Surgery::updateAccount(PatientAccount& pt, int type)
{
   switch (type)
   {  
      case 1:  pt.updateCharges(rate1);
             break;
      case 2:  pt.updateCharges(rate2);
             break;
      case 3:  pt.updateCharges(rate3);
             break;
      case 4:  pt.updateCharges(rate4);
             break;
      case 5:  pt.updateCharges(rate5);
             break;
      default: ; // Do not add any charge to the account.
   }
}