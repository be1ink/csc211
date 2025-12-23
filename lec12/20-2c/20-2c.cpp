// Convert the following function to one that uses recursion.

// void sign(int n)
// {
//   while (n > 0)
//   cout << "No Parking\n"
//   n--;
// }

#include <iostream>
using namespace std;

// Function prototypes
void sign(int);

int main()
{
    int num = 0;

    cout << "Please input non-negative integer: ";
    cin >> num;

    cout << "\nParking detector: \n";
    cout << "=================\n";
    sign(num);
    return 0;
}

// Function definitions
void sign(int n)
{
    if(n <= 0) {}
    else 
    {
        cout << "No Parking\n";
        sign(n - 1);
    }
}