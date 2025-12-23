// 3. Chips and Salsa
// Write a program that lets a maker of chips and salsa keep track of sales for five differ-
// ent types of salsa: mild, medium, sweet, hot, and zesty. The program should use two
// parallel 5-element arrays: an array of strings that holds the five salsa names, and an
// array of integers that holds the number of jars sold during the past month for each salsa
// type. The salsa names should be stored using an initialization list at the time the name
// array is created. The program should prompt the user to enter the number of jars sold
// for each type. Once this sales data has been entered, the program should produce a
// report that displays sales for each salsa type, total sales, and the names of the highest
// selling and lowest selling products.
// Input Validation: Do not accept negative values for number of jars sold.

#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
const vector<string> jar_list_init();
vector<int> input_jars(const vector<string>);
int get_num();
void display_sales(vector<int>, vector<int>);
void sort_vectors(vector<int>, vector<int>);
vector<int> highest_sales(vector<int>);
vector<int> lowest_sales(vector<int>);

int main()
{



    return 0;
}

// Helper functions
const vector<string> jar_list_init() 
{
    const vector<string> salsas {'mild', 'medium', 'sweet', 'hot', 'zesty'};
    return salsas;
}

vector<int> input_jars(const vector<string> salsas)
{
    vector<int> jars_sold(salsas.size(), 0);

    cout << "Please input the number of jars sold per salsa type:\n";
    for (int i = 0; i < salsas.size(); i++)
    {
        cout << "Number of jars of " << salsas[i] << " :";
        get_num();
        cout << endl;
    }

    return jars_sold;
}

int get_num()
{
    int num = 0;
    cin >> num;

    while(num < 0 || !cin >> num || cin.peek() != '\n')
    {
        cout << "\nInvalid input. Please enter number of jars: ";
    }

    return num;
}

void display_sales(vector<int> salsas, vector<int> jars_sold)
{


}

void sort_vectors(vector<int> salsas, vector<int> jars_sold)
{
    bool swap = false;
    int temp = 0;
    string salsa_temp;

    while(swap)
    {
        swap = false;

        for(int i = 0; i < jars_sold.size(); i++)
        {
            if(jars_sold[i] > jars_sold[i+1])
            {
                temp = jars_sold[i+1];
                jars_sold[i+1] = jars_sold[i];
                jars_sold[i] = temp;

                salsa_temp = salsas[i+1];
                salsas[i+1] = salsas[i];
                salsas[i] = temp;

                swap = true;
            }
        }

    } 
}

vector<int> highest_sales(vector<int> jars_sold)
{
    vector<int> highest;

    int j = 0;
    
    highest[0] = jars_sold[jars_sold.size() - 1];

    for (int i = jars_sold.size() - 1; i >= 0; i--)
    {
        if (jars_sold[i -1] == jars_sold[i])
        {
            highest[j++] = jars_sold[i -1];
        }
        else break;
    }

    return highest;
}