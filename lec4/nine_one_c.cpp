// Array Allocator
// Write a fuction that dynamically allocates an array of integers. 
// The function should accept an integer argument indicating the number of elements to allocate. 
// The function should return a pointer to the array.

# include <iostream>
using namespace std;

int* dynamAlloc(int num);

int main()
{
    int num = 0;
    int *ptr = nullptr;
    cout << "Please indicate the number of elements to allocate:";
    cin >> num;

    ptr = dynamAlloc(num); 

    for (int i = 0; i < num; i++)
    {
        ptr[i] = i;
        cout << "\n" << ptr[i];
    }

    delete [] ptr;             

    return 0;
}

int* dynamAlloc(int num)
{
    int* iptr = new int[num]; // allocate array of ints
    return iptr;
}

