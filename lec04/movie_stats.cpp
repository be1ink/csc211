// Movie Statistics

// Write a program that can be used to gather statistical data about the number 
// of movies college students see in a month. The program should perform the 
// following steps:

    // A) Ask the user how many students were surveyed. An array of integers with 
        // this many elements should then be dynamically allocated.
    // B) Allow the user to enter the number of movies each student saw into the array.
    // C) Calculate and display the average, median, and mode of the values entered. 
        //(Use the functions you wrote in Programming Challenges 8 and 9 to 
        // calculate the median and mode.)
    // D) Input Validation: Do not accept negative numbers for input.

// Call packages
#include <iostream>
#include <vector>
using namespace std;

// Function prototypes:
int getNum();
int* returnArray(int);
int* dataEntry(int, int*);
void calcStats(int, int*);
int* sortArray(int, int*);

int main()
{
    // Initialize variables
    int stud_num = 0;
    int* data = nullptr;

    // Input menu:
    cout << "----------------------------------------\n";
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout << "----------------------------------------\n";
    cout << "DATASiGHT (TM) BASIC -- VERSION 10.23\n\n";
    cout << "Welcome back! Project \"Movie Statistics\" initialized.\n";
    cout << "Please enter the number of students surveyed: ";

    stud_num = getNum();
    if (stud_num == 0)
    {
        cout << "\nIt appears you have no participants, please come back when you"; 
        cout << " have data to crunch!\n";
        return 0;
    }

    // Dynamically allocate an array for student data
    data = returnArray(stud_num);
    cout << "\n";

    // Input data into array
    dataEntry(stud_num, data);

    // Sort array before completing calculations
    data = sortArray(stud_num, data);

    // Generate statistics
    calcStats(stud_num, data);

    // Delete pointer
    delete data;

    return 0;
}

// Functions

int getNum()
{
    // Declare function vars
    int num = 0;

    // Retrieve user input
    cin >> num;

    // Rejects non-numerical entries, prompts reentry.
    while(true)
    {
        if(cin.fail()) // true if error bits tripped
        {
            cin.clear(); // reset error bits back to 0
            cin.ignore(1000, '\n'); // clear out 1000 chars or until '\n'
            cout << "Non-integer entry. Please enter a valid number.\n";
            cin >> num;
            continue;
        }
        else {break;}
    }

    // Rejects negative inputs
    while(true)
    {
        if(num < 0) 
        {
            cout << "Negative input. Please enter a positive number.\n";
            cin >> num;
            continue;
        }
        else {break;}
    }
    
    // Return valid entry
    return num;      
}

int* returnArray(int num)
{
    int* students = nullptr;
    students = new int[num];
    return students;
}

int* dataEntry(int length, int* students)
{
    // Initialize variables
    int num = 0;

    for (int i = 0; i < length; i++)
    {
        cout << "Please input the number of movies watched for Student " 
            << i + 1 << ": ";
        students[i] = getNum();
    }

    // Return populated array
    return students;
}

void calcStats(int length, int* students)
{
    // Initialize statistical variables
    double average = 0.0;
    int median = 0;
    vector<int> mode;

    // Initialize median calculation helpers
    int modded = 0;
    int lmid = 0;
    int rmid = 0;

    // Initialize mode calculation helpers
    vector<int> unique;
    vector<int> tally;

    // **Calculate average
    for (int i = 0; i < length; i++)
    {
        average += students[i];
    }
    average = average / length;

    // **Calculate median
    modded = length % 2;

    // If even number of students
    if (modded == 0)
    {
        rmid = length / 2;
        lmid = (length / 2) - 1;

        median = (students[rmid] + students[lmid]) / 2;
    }

    // If odd number of students
    else
    {
        median = students[length / 2];
    }

    // ** Calculate mode with sorted array
    for (int i = 0; i < length; i++) 
    {
        if (i == 0 || students[i] != unique.back()) 
        {
            unique.push_back(students[i]);
            tally.push_back(1);
        } 
        else 
        {
            tally.back()++;
        }
    }

    // Identify mode or modes
    int maxCount = 0;

    // Find the largest tally value
    for (int i = 0; i < tally.size(); i++)
    {
        if (tally[i] > maxCount)
        {
            maxCount = tally[i];
        }
    }

    // Collect all values that appear that many times
    for (int i = 0; i < tally.size(); i++)
    {
        if (tally[i] == maxCount)
        {
            mode.push_back(unique[i]);
        }
    }

    // Print stastistics
    cout << "----------------------------------------\n";
    cout << "        DESCRIPTIVE STATISTICS \n";
    cout << "----------------------------------------\n";
    cout << "Average: " << average << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: ";
    // (int) recasts the .size() output to an int from an unsigned int
    for (int i = 0; i < (int)mode.size(); i++) 
    {
        cout << mode[i];
        if (i < (int)mode.size() - 1) cout << ", ";
    }
    cout << endl;
}

int* sortArray(int num, int* array)
{
    // Initialize variables
    bool swapped = false;
    int temp = 0;

    do
    {
        // Reset swap flags
        swapped = false;

        for (int i = 0; i < num - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }

    } while (swapped);  // loop until no swaps occur

    // Return sorted array
    return array;
}