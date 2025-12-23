#include <iostream>
#include "customer_data.h"
using namespace std;

int main()
{
    // Declare variables
    CustomerData customer_1;

    // Setter functions (hardcoded)
    customer_1.setCustomerNumber(1);
    customer_1.setMailingList(true);

    // Retrieve data
    cout << "Customer Information \n";
    cout << customer_1.getCustomerNumber() << endl;
    cout << customer_1.getMailingList() << endl;

    return 0;
}