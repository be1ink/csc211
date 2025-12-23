// This program demonstrates a class that redefines a base class function
#include <iostream>
#include <iomanip>
#include "curved_activity.h"
using namespace std;

int main()
{
    // Declare variables
    double numericScore;
    double percentage;

    // Define a CurvedActivity object
    CurvedActivity exam;

    // Get the unadjusted score
    cout << "Enter the student's raw numeric score: ";
    cin >> numericScore;

    // Implement defaults
    percentage = 1 + (exam.getPercentage() / 100);
    exam.setPercentage(percentage);
    exam.setScore(numericScore); // Before applying curve

    // Display the raw grade data.
    cout << fixed << setprecision(2); // declare formatting
    cout << "The raw score is " << exam.getRawScore() << endl;
    cout << "The raw grade is " << exam.getLetterGrade() << endl << endl;

    // Compute curved data
        // Get the curve percentage
    cout << "Enter the curve percentage as a floating point number (###.##) for "; 
    cout << "this student." << endl << "i.e. Enter 25.5 for a 25.5\% increase to ";
    cout << "the score: ";
    cin >> percentage;
    percentage = 1 + (percentage / 100); // Normalize to percentage modifier

    // Send the values to the exam object
    exam.setPercentage(percentage);
    exam.setScore(numericScore);

    // Display the curved grade data.
    cout << endl << "The curved score is " << exam.getScore() << endl;
    cout << "The curved grade is " << exam.getLetterGrade() << endl;

    return 0;
}