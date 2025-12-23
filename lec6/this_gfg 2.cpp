#include <iostream>
using namespace std;

// Class demonstrating use of 'this' pointer
class Student {
private:
    string name;
    int age;

public:

    // Constructor with parameters having the same name
    Student(string name, int age) {
        
        // 'this' is used to distinguish between class members and constructor parameters
        this->name = name;
        this->age = age;
    }

    // Member function using 'this'
    void introduce() {
        cout << "Hi, I am " << this->name
             << " and I am " << this->age << " years old." << endl;
    }

    // Returning current object using 'this'
    Student& olderBy(int years) {
        this->age += years;  
        return *this;        
    }
};

int main() {

    Student s("Alice", 20);

    // Display initial introduction
    s.introduce();

    // Increase age and reintroduce
    s.olderBy(2).introduce();

    return 0;
}