#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee
{
    private:
    string name;
    int idNumber;
    string department;
    string position;

    public:

    // Constructors
    Employee()
    {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }
    
    Employee(string n, int id, string dep, string pos)
    {
        name = n;
        idNumber = id;
        department = dep;
        position = pos;
    }

    Employee(string n, int id)
    {
        name = n;
        idNumber = id;
        department = "";
        position = "";
    }    

    // Setters / Mutators
    void setName(string n)
    {
        name = n;
    }

    void setidNumber(int id)
    {
        idNumber = id;
    }

    void setDepartment(string dep)
    {
        department = dep;
    }

    void setPosition(string pos)
    {
        position = pos;
    }

    // Getters / Accessors

    string getName()
    {
        return name;
    }

    int getidNumber()
    {
        return idNumber;
    }

    string getDepartment()
    {
        return department;
    }

    string getPosition()
    {
        return position;
    }
};

#endif