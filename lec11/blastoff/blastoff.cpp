#include <iostream>
using namespace std;

// Function prototypes
void countDown(int);

int main()
{
    int count_start = 0;
    cout << "Enter count timer start: ";
    cin >> count_start;

    countDown(count_start);

    return 0;
}

// Functions
void countDown(int c)
{
    if(c == 0)
    {
        cout << "Blastoff!" << endl;
    }
    else if(c >= 1)
    {
        cout << c << "..." << endl;
        countDown(c-1);
    }
}