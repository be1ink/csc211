// Program Author: Benjamin Link
// EMPLID: 21009239
// Course: CSC 211 - 1300

// Instructions:
    // Write a C++ menu driven program to do the following:

    // 1. Calculate Fiboncci numbers (place them in an array)
    // 2. Check input if it's a Prime number
    // 3. Find GCD of two numbers
    // 4. Calculate Factorial of a given input
    // 5. Output your Student info to a text file with all of your output
    // 6. Exit

    // Requirements:
        // Must use the following:
        // - Advance Files IO
        // - Recursion
        // - STL
        // - C++ Libraries

    // Your name must be on all programs and output.
    // You must submit all working code, files and screen shot. 
    // Your work must be original.

// Beginning of program submission:

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
int get_choice();
int get_num();
void fibonacci(int, int, vector<int>&);
void display_fib(vector<int>);
bool prime_check(int, int);
int gcd(int, int);
int factorial(int);

int main()
{
    // Declare / initialize variables
    int choice = 0;
    int fib_range = 0;
    int prime_candidate = 0;
    int gcd_num1 = 0;
    int gcd_num2 = 0;
    int gcd_result = 0;
    int factorial_num = 0;
    int factorial_result = 0;
    int out_file_counter = 0;
    bool prime_status;
    bool choice2 = false;
    bool choice3 = false;
    bool choice4 = false;
    string file_name;
    ofstream out_file;

    // I interpreted that a vector counts as an array. I use this because my
    // interpretation of the implementation is to have the user request how
    // many Fibonacci numbers to generate. Since a vector can dynamically increase
    // in size, I thought it would be the best STL container to use here.
    vector<int> fib_series;

    cout << "Welcome to NumGen 17, please consult the menu below for the latest \n";
    cout << "in 20th century numerical operations for the home computer!\n";

    // Menu
    do
    {
        cout << "\nPlease select from the below menu options:\n";
        cout << "==========================================\n";
        cout << "[1] Generate a Fibonacci Series\n";
        cout << "[2] Check if number is prime\n";
        cout << "[3] Identify the Greatest Common Divisor (GCD) between two numbers\n";
        cout << "[4] Calculate the factorial of a number\n";
        cout << "[5] Output operations to a file.\n";
        cout << "[6] Exit\n";

        choice = get_choice();
        
        if(choice == 1)
        {
            // Menu Item 1
            cout << "\n1. Fibonacci Series Generation: \n";
            cout << "---------------------------\n";
            cout << "Please enter the number of fibonacci values you'd like generated \n";
            cout << "starting from the first member of the series, 0: ";

            fib_range = get_num();

            // Clear if already called previously
            fib_series.clear();

            // Hardcode iterator - starts at 0
            fibonacci(0, fib_range, fib_series);

            display_fib(fib_series);
        }
        else if(choice == 2)
        {
            // Menu Item 2
            choice2 = true;

            cout << "\n2. Prime Number Identifier: \n";
            cout << "------------------------------\n";
            cout << "Please enter a whole number to test whether it is prime:  \n";

            prime_candidate = get_num();

            // Hardcode starting divisor at 2
            prime_status = prime_check(prime_candidate, 2);

            if(prime_status) {cout << prime_candidate << " is a prime number!" << endl;}
            else {cout << prime_candidate << " is NOT a prime number!" << endl;}
        }
        else if(choice == 3)
        {
            // Menu Item 3
            choice3 = true;

            cout << "\n3. Greatest Common Divisor: \n";
            cout << "==============================\n";
            cout << "Please enter two whole numbers to identify the greatest common \n";
            cout << "divisor between them: \n\n";

            cout << "First number: ";
            gcd_num1 = get_num();

            cout << "Second number: ";
            gcd_num2 = get_num();
            cout << endl;

            gcd_result = gcd(gcd_num1, gcd_num2);

            cout << "The greatest common divisor of " << gcd_num1 << " and " << gcd_num2;
            cout << " is: " << gcd_result << "!" << endl;
        }
        else if(choice == 4)
        {
            // Menu Item 4
            choice4 = true;

            cout << "\n4. Factorial calculator: \n";
            cout << "==============================\n";
            cout << "Please enter a whole number to apply the factorial operation to: ";

            factorial_num = get_num();

            factorial_result = factorial(factorial_num);

            cout << factorial_num << "! = " << factorial_result << endl;
        }
        else if(choice == 5)
        {
            // Menu Item 5
            if(fib_series.empty() && !choice2 && !choice3 && !choice4)
            {
                cout << "No results to output, returning to menu.\n";
                continue;
            }
            else
            {
                out_file_counter++;

                // Create a new output file each time this is selected.
                file_name = "NumGen17_output_" + to_string(out_file_counter) + ".txt";

                cout << "\n5. Output your operation results to a file! \n";
                cout << "============================================\n";

                cout << "Any operations you have performed can now be found in: ";
                cout << file_name << endl;

                out_file.open(file_name, ios::out);

                // Student Info:
                out_file << "Program Author: Benjamin Link" << endl;
                out_file << "Author EMPLID: 21009239" << endl;
                out_file << "Program Sponsor: CSC 211 — 1300" << endl << endl;

                // Data:
                out_file << "NumGen 17 Output File " + to_string(out_file_counter) << endl;
                out_file << "=======================\n";

                // Choice 1 output
                if(fib_series.empty())
                    {out_file << "No Fibonacci series generated." << endl;}
                else
                {
                    out_file << "Fibonacci series: ";
                    for(auto x : fib_series)
                    {
                        out_file << x << " ";
                    }
                    out_file << endl;
                }

                // Choice 2 output
                if(!choice2) {out_file << "2. No prime number operation performed." << endl;}
                else if(prime_status)
                    {out_file << prime_candidate << " is a prime number." << endl;}
                else
                    {out_file << prime_candidate << " is NOT a prime number." << endl;}

                // Choice 3 output
                if(!choice3) {out_file << "No GCD operation performed." << endl;}
                else 
                {
                    out_file << "The GCD of " << gcd_num1 << " and " << gcd_num2;
                    out_file << " is " << gcd_result << "." << endl;
                }

                // Choice 4 output
                if(!choice4) {out_file << "No factorial operation performed." << endl;}
                else {out_file << factorial_num << "! = " << factorial_result << endl;}
            }
            // Close out_file so that new files can be generated:
            out_file.close();
        }
    }while(choice != 6);

    cout << "Thank you for using NumGen 17! Closing program..." << endl;
        
    return 0;
}

// Function definitions
int get_choice()
{
    int num = 0;

    while (true)
    {
        // If:
            // i. the input stream operator worked correctly 
                //(also acts to receive user input)
           // ii. The character at the end of the input is a newline character
          // iii. The integer is non-negative.
        if (cin >> num && cin.peek() == '\n' && num >=1 && num <= 6)
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
        if (cin >> num && cin.peek() == '\n' && num >= 0)
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

void fibonacci(int n, int fib_range, vector<int>& fib_series)
{

    // Base case: 
    // The iterator matches or exceeds the requested Fibonacci series range exit 
    // the function.
    if (n >= fib_range) return;

    // Fill in the first two values of the fib series, assuming the base case
    // isn't already tripped.
    if (n == 0) {fib_series.push_back(0);} 
    else if (n == 1) {fib_series.push_back(1);} 

    // Recursive case: 
    // If the fib_range is greater than 2, compute the next Fibonacci numbers
    // in sequence.
    else 
    {
        // Create temp next var to hold next fib number to be computed
        int next = fib_series[n - 1] + fib_series[n - 2];
        fib_series.push_back(next);
    }
    // Continue processing cases
    fibonacci(n + 1, fib_range, fib_series);
}

void display_fib(vector<int> fib_series)
{
    // Use a for range loop to display contents of fib_series
    for(auto x : fib_series)
    {
        cout << x << " ";
    }
    cout << endl;
}

bool prime_check(int num, int i)
{
    // Base cases
    // Below ternary line:
        // If num is less than or equal to 2 return true if num is equal to 2 
        // and false if not
    if (num <= 2) return (num == 2) ? true : false;

    // Keep checking divisors incrementally from 2 onward to see if num can be
    // divided cleanly, with no remainder, from any of them. If so, then it's
    // not a prime number.
    if (num % i == 0) return false;

    // Stop iterating the divisor if it multiplied by itself exceeds the value
    // of the candidate number being assessed. This means that there are are no
    // whole number divisors beyond num and 1 that can divide num, thus it's prime.
    if (i * i > num) return true;

    // Recursive case
    // Increment the divisor and run the prior two if statements again
    return prime_check(num, i + 1);
}

int gcd(int x, int y)
{
    // If the user inputs 0 for y:
    if (y == 0) {return x;}

    // If x's remainder after dividing by 2 is y, then y is the GCD
    if(x % y == 0) {return y;}

    // Replace y with the remainder of x after being divided by y to advance
    // the recursive search for the GCD
    else {return gcd(y, x % y);}
}

int factorial(int n)
{
    // Base case
    if(n == 0) {return 1;}
    // Recursive case
        // Applies the formula n * n-1 * n-2 * n-3... with two terms per call
    else {return(n * factorial(n-1));}
}