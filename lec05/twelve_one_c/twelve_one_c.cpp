// File Head Program
    // Write a program that asks the user for the name of a file. The program 
    // should diplay the first ten lines of the file on the screen (the "head" 
    // of the file). If the file has fewer than ten lines, the entire file should 
    // be displayed, with a message indicating the entire file has been displayed.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Initialize variables
    string file_name;
    ifstream in_file;
    string line;
    int counter = 0;

    cout << "Enter a file name: ";
    cin >> file_name;

    in_file.open(file_name);

    if (in_file)
    {
        while (getline(in_file, line) && counter < 10)
        {
            cout << line << endl;
            counter++;
        }
        in_file.close();

        if(counter < 9)
        {
            cout << "File less than 10 lines, all lines are displayed!\n";
        }
    }

    // Validation
    else
    {
        cout << "Cannot open " << file_name << endl;
    }

    return 0;
}