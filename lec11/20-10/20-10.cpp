// Towers of Hanoi
#include <iostream>
using namespace std;

// Function prototypes:
void moveDiscs(int, int, int, int);

int main()
{
    // const int NUM_DISCS = 3;   
    // const int FROM_PEG = 1;    
    // const int TO_PEG = 3;      
    // const int TEMP_PEG = 2;    

    int NUM_DISCS = 3;   
    int FROM_PEG = 1;    
    int TO_PEG = 3;      
    int TEMP_PEG = 2; 

    cout << "Please enter number of discs: ";
    cin >> NUM_DISCS;

    cout << "Please enter the leave peg: ";
    cin >> FROM_PEG;

    cout << "Please enter the target or goal peg: ";
    cin >> TO_PEG;

    cout << "Please enter the temporary peg: ";
    cin >> TEMP_PEG;

    moveDiscs(NUM_DISCS, FROM_PEG, TO_PEG, TEMP_PEG);
    cout << "All the pegs are moved!\n";
    return 0;
}

// Functions:
// Number of discs, leave peg, goal peg, temp peg
void moveDiscs(int num, int A, int B, int C)
{
    if (num > 0)
    {
        moveDiscs(num - 1, A, C, B);
        cout << "Move a disc from peg " << A << " to peg " << B << endl;
        moveDiscs(num - 1, C, B, A);
    }
}