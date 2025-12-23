#include <iostream>
using namespace std;

// Function prototype (default only here)
bool isPrime(int number, int divisor = 2);

int main()
{
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (isPrime(num)) 
        cout << num << " is a prime number." << endl;
    else 
        cout << num << " is not a prime number." << endl;

    return 0;
}

// Function
bool isPrime(int number, int divisor) 
{
    if (number <= 2)            // handle 0,1,2
        return (number == 2);

    if (divisor * divisor > number) 
        return true;            // no divisors up to sqrt(number)

    if (number % divisor == 0) 
        return false;           // found a divisor

    return isPrime(number, divisor + 1);  // recursion
}