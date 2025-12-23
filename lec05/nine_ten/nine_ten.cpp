#include <iostream>
#include <memory>
using namespace std;

// Function prototypes

// int* initArray(int);
int* sortArray(int*, int);
void printArray(int*, int);

int main()
{
    // Hardcoded variables
    int size = 7;
    int array[] = {10, 76, 4, 12, 23, -1, 106};
    int *copy = nullptr;

    // Print original array
    printArray(array, size);

    //TODO Reverse array

    // Sort array
    copy = sortArray(array, size);

    // Print new array
    printArray(copy, size);

    delete [] copy;

    return 0;

}

// Functions
int* sortArray(int* array, int size)
{
    // Initialize variables:
    int* arrayCpy = new int[size];
    int tmp = 0;

    // Copy the contents of array into copy
    for (int i = 0; i < size; i++)
    {
        arrayCpy[i] = array[i];
    }

    for (int i = 0; i < size - 1; i++) 
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) 
        {
            if (arrayCpy[j] < arrayCpy[minIndex]) 
            {
                minIndex = j;
            }
        }

        // Swap if the smallest value isn't at the copy's current index:
        if (minIndex != i) 
        {
            tmp = arrayCpy[i];
            arrayCpy[i] = arrayCpy[minIndex];
            arrayCpy[minIndex] = tmp;
        }
    }
    return arrayCpy;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}