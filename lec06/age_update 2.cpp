#include <iostream>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) 
    {
        this->name = name;
        this->age = age;
    }

    void displayInfo() 
    {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Age: " << this->age << std::endl;
    }

    void updateAge(int newAge) 
    {
        this->age = newAge;
    }
};

int main() {
    Person person("Armaan", 25);

    person.displayInfo();
    person.updateAge(30);
    std::cout << "After updating age:" << std::endl;
    person.displayInfo();

    return 0;
}