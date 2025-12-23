#include <iostream>
#include <limits>
using namespace std;

// Solve recursivley
class Solution {
public:
    int climbStairs(int n) 
    {
        // Base cases
        if(n == 0) {return 1;} // we won't accept 0 as an input, otherwise would be wrong
        else if(n == -1) {return 0;} // overshot

        // Recursive cases
        else
        {
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
    }
};

// Function prototypes
int get_num();

int main()
{
    Solution s;
    int num = 0;

    cout << "This program will output all distinct ways to climb stairs if \n";
    cout << "the only two ways to move are one step at a time or two.\n\n";
    
    cout << "Please input the total number of stairs to traverse: ";

    num = get_num();

    cout << "Number of distinct ways to climb the stairs: ";
    cout << s.climbStairs(num) << endl;

    return 0;
}

// Function definitions
int get_num()
{
    int num = 0;

    while (true)
    {
        // If:
            // i. the input stream operator worked correctly 
                //(also acts to receive user input)
           // ii. The character at the end of the input is a newline character
          // iii. The integer is non-negative.
        if (cin >> num && cin.peek() == '\n' && num >= 1 && num <= 45)
            {return num;}
        cout << "Invalid input. Try again: ";

        // Clears any tripped error flags in the input stream if present
        cin.clear();

        // This allows the input stream to skip over all characters in the buffer
        // up to the theoretical maximum size of the input stream buffer until a
        // newline character is reached. This is particularly useful in dealing
        // with unanticipated non-numerical inputs that can lead to infinite looping.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}