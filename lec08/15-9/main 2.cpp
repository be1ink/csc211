// This program demonstrates the PassFailExam class.
#include <iostream>
#include<iomanip>
#include "pass_fail_exam.h"
using namespace std;

int main()
{
    // Declare variables
    int questions;
    int missed;
    double minPassing;

    // Get the number of questions on the exam.
    cout << "How many questions are on the exam? ";
    cin >> questions;

    //Get the number of questions the student missed.
    cout << "How many questions did the student miss? ";
    cin >> missed;

    // Get the minimum passing score.
    cout << "Enter the minimum passing score for this test: ";
    cin >> minPassing;

    // Define a PassFailExam object.
    PassFailExam exam(questions, missed, minPassing);

    // Display the test restuls.
    cout << fixed << setprecision(1);
    // From PassFailExam class
    cout << "\nEach question counts " << exam.getPointsEach() << " points.\n";
    // From PassFailActivity class
    cout << "The minimum passing score is " << exam.getMinPassingScore() << endl;
    // From GradedActivity class
    cout << "The student's exam score is " << exam.getScore() << endl;
    // Conflict: method function exists with both GradedActivity and 
        // PassFailActivity class. The derived one, PassFailActivity, probably 
        // overrides as it's the most recent definition of the function (redefinition).
    cout << "The student's exam score is " << exam.getLetterGrade() << endl;

    return 0;
}