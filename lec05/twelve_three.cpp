// This program uses the setprecision and fixed
// manipulators to format file output.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    fstream dataFile;
    double num = 17.816392;

    dataFile.open("numfile.txt", ios::out); // Open in output mode

    dataFile << fixed; 
    dataFile << num << endl; 

    dataFile << setprecision(4);
    dataFile << num << endl; // Format for 4 decimal places

    dataFile << setprecision(3);
    dataFile << num << endl; // Format for 3 decimal places

    dataFile << setprecision(2);
    dataFile << num << endl; // Format for 2 decimal places

    dataFile << setprecision(1);
    dataFile << num << endl; // Format for 1 decimal place

    cout << "Done.\n";
    dataFile.close(); // Close the file
    return 0;
}