// 3. Punch Line
// Write a program that reads and prints a joke and its punch line from two different files.
// The first file contains a joke, but not its punch line. The second file has the punch line
// as its last line, preceded by “garbage.” The main function of your program should open
// the two files then call two functions, passing each one the file it needs. The first function
// should read and display each line in the file it is passed (the joke file). The second func-
// tion should display only the last line of the file it is passed (the punch line file). It should
// find this line by seeking to the end of the file and then backing up to the beginning of the
// last line. Data to test your program can be found in the joke.txt and punchline.txt files.

#include <iostream>
#include <fstream>
using namespace std;

// Function prototypes
void retrieveJoke(ifstream &);
void printPunchLine(ifstream &);

int main()
{
    ifstream input_file;
    ifstream punchline_file;

    input_file.open("joke.txt", ios::in);
    
    if(input_file)
    {
        // Print joke
        retrieveJoke(input_file);
        input_file.close();
       
    }
    else {cout << "joke.txt could not be opened. \n";}
    input_file.close();

    punchline_file.open("punchline.txt", ios::in | ios::ate);
    
    if(punchline_file)
    {
        // Print joke
        printPunchLine(punchline_file);
        punchline_file.close();
       
    }
    else {cout << "punchline.txt could not be opened. \n";}
    input_file.close();

    return 0;
}

// Functions
void retrieveJoke(ifstream &in)
{
    string line;

    while(getline(in, line))
    {
        cout << line << endl;
    }
}

// void printPunchLine(ifstream &in)
// { 
//     string line, lastLine;

//     // Move through all lines until end
//     while (getline(in, line))
//     {
//         lastLine = line;
//     }

//     cout << lastLine << endl;
// }


void printPunchLine(ifstream &in)
{ 
    // Declare variables
    char ch;
    string line;

    // Move back onto final line, away from EOF
    in.seekg(-1, ios::end);

    // Move backward until newline or beginning of file, assuming \n separator
    while (in.tellg() > 0)
    {
        in.get(ch);
        if (ch == '\n')
            break;
        // Moves fowrard one, so we must move back two
        in.seekg(-2, ios::cur);
    }

    // Read the last line
    getline(in, line);
    cout << line << endl;
}