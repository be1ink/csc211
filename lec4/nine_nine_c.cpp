#include <iostream>
#include <cstdlib>
using namespace std;

int* dynamAlloc(int num);
double returnMedian(int* array, int num);
int* sortArray(int* array, int num);
bool checkSort(int* array, int num);

int main()
{
    int num = 0;
    int *ptr = nullptr;
    cout << "Please indicate the number of elements to allocate: ";
    cin >> num;

    ptr = dynamAlloc(num); 

    for (int i = 0; i < num; i++)
    {
        ptr[i] = rand() % 1000;
        cout << "\n" << ptr[i];
    }

    double median = returnMedian(ptr, num);

    // Print sorted array
    cout << "\nSorted array:\n";
    for (int i = 0; i < num; i++)
    {
        cout << ptr[i] << " ";
    }

    // Result
    cout << "\nMedian Value: " << median << endl;

    // Clear dynamic pointer
    delete [] ptr;             

    return 0;
}

int* dynamAlloc(int num)
{
    int* iptr = new int[num]; // allocate array of ints
    return iptr;
}

double returnMedian(int* array,int num)
{
    bool sort = false;
    int i1 = 0;
    int i2 = 0;
    double split = 0;
    double median = 0;

    // Sort array:
    while(true)
    {
        sortArray(array, num);
        sort = checkSort(array, num);
        if(sort) {break;}
    } 

    if(num % 2 == 1)
    {
        i1 = num / 2;
        median = array[i1];
        return(median);
    }
    else
    {
        i1 = (num / 2) - 1;    
        i2 = num / 2;          
        // Remember to use 2.0 for proper division
        median = (array[i1] + array[i2]) / 2.0;  
        return(median);
    }
}

int* sortArray(int* array, int num)
{
    for(int i = 0; i < num - 1; i++)
    {
        double temp = 0;

        // Finished sort
        if(i == num - 1)
        {
            return array;
        }
        else if(array[i] <= array[i+1])
        {
            continue;
        }
        else
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
}

bool checkSort(int* array, int num)
{
    for(int i = 0; i < num; i++)
    {
        cout << i << endl;
        // Reached end and no false flags tripped
        if(i == num - 1)
        {
            return true;
        }
        else if(array[i] <= array[i+1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
}

// Better algorithm
// bool checkSort(int* array, int num)
// {
//     for(int i = 0; i < num - 1; i++)  // Changed: num-1
//     {
//         if(array[i] > array[i+1])     // Simplified condition
//         {
//             return false;
//         }
//     }
//     return true;  // If we get here, it's sorted
// }