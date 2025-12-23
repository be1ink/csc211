#include <iostream>
using namespace std;

int doSomething(int *x, int *y);

int main()
{
    // int* x = nullptr;
    // int* y = nullptr;

    int x = 5, y = 10;

    cout << doSomething(&x, &y) << endl;

    return 0;
}

int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}