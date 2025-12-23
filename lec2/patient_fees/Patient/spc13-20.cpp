// Chapter 13, Programming Challenge 20: Patient Fees
#include <iostream>
#include <iomanip>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"
using namespace std;

// Function prototypes
int getSurgeryType();
int getMedicationType();

int main()
{
   int surgeryType,           // To hold the type of surgery
       medicationType;        // To hold the type of medication
   PatientAccount patient1;   // Create a PatientAccount object.
   Surgery  surgery;          // Create a Surgery object.
   Pharmacy pharmacy;         // Create a Pharmacy object.
   
   cout << "\n\nPatient Release Menu\n\n";
   
   patient1.setDays();  // Sets length of patient stay and
                        // adds daily room rate onto charges

   // Get the surgery and medication types.
   surgeryType = getSurgeryType();
   medicationType = getMedicationType();

   surgery.updateAccount(patient1, surgeryType);
   pharmacy.updateAccount(patient1, medicationType);

   cout << fixed << showpoint << setprecision(2);
   cout << "\nPatient Charges:  " << patient1.getCharges() 
	     << endl << endl;
   return 0;
}

//***********************************************
// Function getSurgeryType                      *
// Displays a menu of surgery types and gets    *
// a selection from the user. The selection     *
// is returned.                                 *
//***********************************************

int getSurgeryType()
{
   int choice;

   // Display the surgery menu
   cout << "\nTypes of Surgery We Perform\n";
   cout << "---------------------------\n";
   cout << "1 - Tonsillectomy\n";
   cout << "2 - Foot\n";
   cout << "3 - Knee\n";
   cout << "4 - Shoulder\n";
   cout << "5 - Appendectomy\n\n";
   cout << "Choose a type of Surgery (1-5):  ";
   cin  >> choice;
   while (choice < 1 || choice > 5)
   {  
      cout << "Legal values are 1-5.  Please re-enter surgery type: ";
      cin  >> choice;
   }

   return choice;
}

//***********************************************
// Function getMedicationType                   *
// Displays a menu of medication types and gets *
// a selection from the user. The selection     *
// is returned.                                 *
//***********************************************

int getMedicationType()
{
   int choice;

   // Display the medication menu
   cout << "\nTypes of Medication\n";
   cout << "---------------------------\n";
   cout << "1 - Antibiotic\n";
   cout << "2 - Ant-inausea\n";
   cout << "3 - Anti-inflamatory\n";
   cout << "4 - Light Pain\n";
   cout << "5 - Strong Pain\n\n";
   cout << "Choose a type of medication (1-5):  ";
   cin  >> choice;
   while (choice < 1 || choice > 5)
   {  
      cout << "Legal values are 1-5.  Please re-enter medication type: ";
      cin  >> choice;
   }

   return choice;
}