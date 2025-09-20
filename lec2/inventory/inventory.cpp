#include <iostream>
#include "inventory.h"
using namespace std;

// Function prototypes
bool checkNegativeInt(int num);
bool checkNegativeDouble(double num);

int main()
{
    Inventory Item;
    int iNum;
    int q;
    double c;

    cout << "Please enter inventory item info:" << "\n\n";
    
    while (true)
    {
        cout << "Enter item number: ";
        cin >> iNum;
        if (checkNegativeInt(iNum))
        {
            cout << "Number must be 0 or greater. Please try again." << endl;
        }
        else
        {
            Item.setItemNumber(iNum);
            cout << "Valid item number" << "\n\n";
            break;
        }
    }
    
    while (true)
    {
        cout << "Enter quantity: ";
        cin >> q;
        if (checkNegativeInt(q))
        {
            cout << "Number must be 0 or greater. Please try again." << endl;
        }
        else
        {
            Item.setQuantity(q);
            cout << "Valid quantity" << "\n\n";
            break;
        }
    }
    
    while (true)
    {
        cout << "Enter item cost: $";
        cin >> c;
        if (checkNegativeDouble(c))
        {
            cout << "Number must be 0 or greater. Please try again." << endl;
        }
        else
        {
            Item.setCost(c);
            cout << "Valid cost" << "\n\n";
            break;
        }
    }

    cout << endl << "Summary of Inventory:" << endl;
    cout << "Item Number: " << Item.getItemNumber() << endl;
    cout << "Quantity: " << Item.getQuantity() << endl;
    cout << "Cost: $" << Item.getCost() << endl;
    Item.setTotalCost();
    cout << "Total Cost: $" << Item.getTotalCost() << endl;

    return 0;
}

// Functions
bool checkNegativeInt(int num)
{
    if (num < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkNegativeDouble(double num)
{
    if (num < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
