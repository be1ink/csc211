#include <iostream>
#include <iomanip>
#include "sale.h"
using namespace std;

int main()
{
    // Instantiate core variables
    //const double TAX_RATE = 0.06; // set tax rate to 6%
    double cost;

    // Get the item cost from user
    cout << "Enter the cost of the item: ";
    cin >> cost;

    // Create Sale object
    // Sale itemSale(cost, TAX_RATE);
    Sale itemSale(cost);

    // Set output formatting
    cout << fixed << showpoint << setprecision(2);

    // Display values
    cout << "The amount of sales tax is $";
    cout << itemSale.getTax() << endl;
    cout << "The total of the sale is $";
    cout << itemSale.getTotal() << endl;
    return 0;
}