#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <iterator>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
using namespace std;

class Rectangle
{
    private:
        double length = 3.0;
        double width = 4.5;
    public:
        double get_area() {return length * width;}
};

int main()
{
    Rectangle *BoxPtr;
    BoxPtr = new Rectangle; // Must be here to initialize clas object!
    cout << BoxPtr->get_area() << endl;
    return 0;
}