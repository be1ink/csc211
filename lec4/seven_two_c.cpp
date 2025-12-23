// Rainfall Statistics
// Write a program that lets the user enter the total rainfall for each of 12 months into an
// array of doubles. The program should calculate and display the total rainfall for the
// year, the average monthly rainfall, and the months with the highest and lowest amounts.
// Input Validation: Do not accept negative numbers for monthly rainfall figures.

// Menu driven
// Write data to files?

#include <iostream>
using namespace std;

void dataEntry(double records[], int months);
bool valEntry(double rainfall);
void calcStats(double records[], int months);

int main()
{
    const int months = 12;
    double rainfall[months];

    dataEntry(rainfall, months);
    calcStats(rainfall, months);
}

void dataEntry(double records[], int months)
{
    double rainfall = 0;
    for(int i = 0; i < months; i++)
    {
        cout << "Please enter the rainfall for month " << i + 1 << endl;
        while(true)
        {
            cin >> rainfall;
            if(valEntry(rainfall) == true) {break;}
        }
        records[i] = rainfall;
    }    
}

bool valEntry(double rainfall)
{
    if (rainfall < 0)
    {
        cout << "Invalid input, number must be 0 or greater.\n";
        return false;
    }
    else {return true;}
}

void calcStats(double records[], int months)
{
    // total rainfall for the year
    // the average monthly rainfall, 
    // the months with the highest and lowest amounts.

    double total = 0;

    for(int i = 0; i < months; i++)
    {
        total += records[i];
    } 
    cout << "\nAnnual Rainfall Summary Statistics:" << endl;
    cout << "Total rainfall for the year: " << total << endl;
    cout << "Average monthly rainfall: " << total / months << endl;
    
    int max_month = 0;
    int min_month = 0;
    double max = 0;
    double min = 0;

    for(int i = 0; i < months; i++)
    {
        if (max < records[i]) 
        {
            max_month = i;
            max = records[i];
        }
        if (min > records[i]) 
        {
            min_month = i;
            min = records[i];
        }
    } 

    cout << "Month with highest rainfall: " << max_month + 1 << " at: " << max <<endl;
    cout << "Month with lowest rainfall: " << min_month + 1 << " at: " << min <<endl;
}