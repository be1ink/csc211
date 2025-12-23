// This program stores the address of a variable in a pointer.
#include <iostream>
using namespace std;

int main()
{
    int x = 25;            // int variable
    int *intptr = &x;
    int *ptr = nullptr;    // Pointer variable, can point to an int

    ptr = &x;              // Store the address of x in ptr
    cout << "The value in x is " << x << endl;
    cout << "The value in x is " << *ptr << endl;
    cout << "The value in x is " << *intptr << endl;
    cout << "The address of x is " << ptr << endl;
    cout << "The address of x is " << &x << endl;
    cout << "The address of ptr is " << &ptr << endl;

    return 0;
}