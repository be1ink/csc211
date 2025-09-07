/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include "InventoryItem.h"

int main()
{
    // Create object with constructor #1 
    InventoryItem item1;
    item1.setDescription("Hammer");
    item1.setCost(6.95);
    item1.setUnits(12);
    
    // Create object with constructor #2
    InventoryItem item2("Pliers");
    
    // Create object with constructor #3
    InventoryItem item3("Wrench", 8.75, 20);
    
    // Create object with constructor #4
    InventoryItem item4(12);
    
    // Create object with constructor #5
    InventoryItem item5("Saw", 4);
    
    // Create object with constructor #6
    InventoryItem item6(43.25, 4);

    // Create object with constructor #7
    InventoryItem item7("Ruler", 2.15);

       // Create object with constructor #8
    InventoryItem item8(37.62);
    
    cout << "The following items are in inventory: \n\n";
    cout << setprecision(2) << fixed << showpoint;
    
    // Data for Item 1
    cout << "Description: " << item1.getDescription() << endl;
    cout << "Cost: $" << item1.getCost() << endl;
    cout << "Units on Hand: " << item1.getUnits() << endl << endl;
    
    // Data for Item 2
    cout << "Description: " << item2.getDescription() << endl;
    cout << "Cost: $" << item2.getCost() << endl;
    cout << "Units on Hand: " << item2.getUnits() << endl << endl;
    
    // Data for Item 3
    cout << "Description: " << item3.getDescription() << endl;
    cout << "Cost: $" << item3.getCost() << endl;
    cout << "Units on Hand: " << item3.getUnits() << endl << endl;
    
    // Data for Item 4
    cout << "Description: " << item4.getDescription() << endl;
    cout << "Cost: $" << item4.getCost() << endl;
    cout << "Units on Hand: " << item4.getUnits() << endl << endl;
    
    // Data for Item 5
    cout << "Description: " << item5.getDescription() << endl;
    cout << "Cost: $" << item5.getCost() << endl;
    cout << "Units on Hand: " << item5.getUnits() << endl << endl;
    
     // Data for Item 6
    cout << "Description: " << item6.getDescription() << endl;
    cout << "Cost: $" << item6.getCost() << endl;
    cout << "Units on Hand: " << item6.getUnits() << endl << endl;
    
    // Data for Item 7
    cout << "Description: " << item7.getDescription() << endl;
    cout << "Cost: $" << item7.getCost() << endl;
    cout << "Units on Hand: " << item7.getUnits() << endl << endl;

    // Data for Item 8
    cout << "Description: " << item8.getDescription() << endl;
    cout << "Cost: $" << item8.getCost() << endl;
    cout << "Units on Hand: " << item8.getUnits() << endl << endl;
    
    return 0;
}