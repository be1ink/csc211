// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>       
#include <cstdlib>   
using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr;          
    int arraySize;    
    void memError();  
    void subError();  

public:
    // Default constructor
    SimpleVector()
    { aptr = 0; arraySize = 0; }

    // Constructor declaration
    SimpleVector(int);

    // Copy constructor declaration
    SimpleVector(const SimpleVector &);

    // Destructor declaration
    ~SimpleVector();

    // Accessor to return the array size
    int size() const { return arraySize; }

    // Accessor to return a specific element
    T getElementAt(int position);

    // Overloaded [] operator declaration
    T &operator[](const int &);
};

// Constructor for SimpleVector class
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    try
    {
        aptr = new T[s];
    }
    catch (bad_alloc)
    {
        memError();
    }

    // Initialize the array
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

// Copy Constructor for SimpleVector class
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    arraySize = obj.arraySize;
    aptr = new T[arraySize];
    if (aptr == 0)
        memError();

    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

// Destructor for SimpleVector class
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete[] aptr;
}

// memError function
template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

// subError function
template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//getEelmentAt function
template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

// Overloaded [] operator
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

#endif