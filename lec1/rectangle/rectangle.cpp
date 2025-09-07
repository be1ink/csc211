/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

class Rectangle
{
    private:
        double width;
        double length;
        double height;
    public:
        void setWidth(double);
        void setLength(double);
        void setHeight(double);
        double getWidth() const;
        double getLength() const;
        double getHeight() const;
        double getArea() const;
        double getVolume() const;
};

// Define setters:
void Rectangle::setWidth(double w)
{
    width = w;
};

void Rectangle::setLength(double l)
{
    length = l;
};

void Rectangle::setHeight(double h)
{
    height = h;
};


// Define getters:

double Rectangle::getWidth() const
{
    return width;
};

double Rectangle::getLength() const
{
    return length;
};

double Rectangle::getHeight() const
{
    return height;
};

double Rectangle::getArea() const
{
    return width * length;
};

double Rectangle::getVolume() const
{
    return width * length * height;
};


int main()
{
    Rectangle box;
    double rectWidth;
    double rectLength;
    double rectHeight;
   
    cout << "This program will calculate the area of a rectangle.\n";
    
    cout << "What is the width? ";
    cin >> rectWidth;
    
    cout << "What is the length? ";
    cin >> rectLength;
    
    cout << "What is the height? ";
    cin >> rectHeight;
    
    // Sort the width and length of the rectangle in the box object.
    box.setWidth(rectWidth);
    box.setLength(rectLength);
    box.setHeight(rectHeight);
    
    // Display rectangle's dimensions and computed properties:
    cout << "Here is the rectangle's data: \n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Height: " << box.getHeight() << endl;
    cout << "Area: " << box.getArea() << endl;
    cout << "Volume: " << box.getVolume() << endl;
    
    return 0;
}
