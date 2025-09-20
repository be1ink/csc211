// Implmenetation files
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.h"
using namespace std;

Die::Die(int numSides)
{
    unsigned seed = time(0); // Get system time
    srand(seed); // Seed randnum generator

    // Set number of sides
    sides = numSides;

    // Do initial roll
    roll();
}

void Die::roll()
{
    // set constant for min die number
    const int MIN_VALUE = 1;

    // get random number
    value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}

// Getters
int Die::getSides()
{
    return sides;
}

int Die::getValue()
{
    return value;
}

//#include <iostream>
int main()
{
    const int DIE1_SIDES = 6; // die 1
    const int DIE2_SIDES = 12; // die 2
    const int MAX_ROLLS = 5; // max rolls each

    // create two object instances
    Die die1(DIE1_SIDES);
    Die die2(DIE2_SIDES);

    cout << "This simulates the rolling of a "
         << die1.getSides() << " sided die and a "
         << die2.getSides() << " sided die.\n";
        
    cout << "Initial value of the dice:\n";
        cout << die1.getValue() << " "
             << die2.getValue() << endl;

    // Roll five times
    cout << "Rolling the dice " << MAX_ROLLS
         << " times.\n";
    for (int count = 0; count < MAX_ROLLS; count++)
    {
        die1.roll();
        die2.roll();

        // Display values of die
        cout << die1.getValue() << " "
             << die2.getValue() << endl;
    }
    return 0;
}