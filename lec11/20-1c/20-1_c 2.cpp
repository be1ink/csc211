// Iterative Factorial
// Write an iterative version (using a loop instead of recursion) of the factorial function
// shown in this chapter. Test it with a driver program.
#include <iostream>
using namespace std;

// Function prototype
int fact_it(int);

int main()
{
    int fact_num = 0;
    cout << "Please enter an integer to perform a factorial operation on: ";
    cin >> fact_num;

    cout << "Factorial is: " << fact_it(fact_num) << endl;
}

// Functions
int fact_it(int num)
{
    int factorial = 1; // 0!

    for(; num > 1; --num)
    {
        factorial *= num;
    }
    return factorial;
}