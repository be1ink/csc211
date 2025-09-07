/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

double add (double num1, double num2)
{
   return num1 + num2; 
}

double subtract (double num1, double num2)
{
   return num1 - num2;
}

double multiply (double num1, double num2)
{
   return num1 * num2;
}

double divide (double num1, double num2)
{
   return num1 / num2;
}

int main()
{
    // std::cout << "Choose" + " " + "Operation" <<std::end1;
    // std::cout << "Options:" + "add," + "subtract," + "multiply," + "divide" <<std::end1;
    
    // Initialize
    double num1 = 0;
    double num2 = 0;
    
    // Select num1
    std::cin << num1 << std::endl;
    
    // Select num2
    std::cin << num2 << std::endl;
    
    
    // OPERATIONS //
    
    // add
    add(num1, num2);
    
    // subtract
    add(num1, num2);
    
    // multiply
    add(num1, num2);
    
    // divide
    add(num1, num2);
    
    return 0;
}
