#include <iostream>
#include "employee.h"
using namespace std;

int main() 
{
    Employee Susan("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee Mark("Mark Jones", 39119, "IT", "Programmer");
    Employee Joy("Joy Rogers", 81774, "Manufacturing", "Engineer");

    cout << "Name  ID Number  Department  Position" << endl;
    cout << Susan.getName() << " " << Susan.getidNumber() 
        << " " << Susan.getDepartment() << " " << Susan.getPosition() << endl;
    cout << Mark.getName() << " " << Mark.getidNumber() 
        << " " << Mark.getDepartment() << " " << Mark.getPosition() << endl;
    cout << Joy.getName() << " " << Joy.getidNumber() 
        << " " << Joy.getDepartment() << " " << Joy.getPosition() << endl;

    return 0;
}