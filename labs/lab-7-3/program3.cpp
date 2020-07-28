//
// program3.cpp
//
// Lisa Lehrman
// 7/27/2020
// CS14E lab 7.3
// A program that accepts input does some calculations and prints the output
// to a file.

#include <iostream>
#include <iomanip> // setprecision, setw
using namespace std;

void printColumn(int value, int col, int rowLength)
{
    cout << setw(4) << value;
    if (rowLength == col)
    {
        cout << '\n';
    }
    else
    {
        cout << '\t';
    }
}

void sortArray(int array[], int size)
{
    bool dirty;
    int temp;
    do
    {
        dirty = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (array[count] > array[count + 1])
            {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                dirty = true;
            }
        }
    } while (dirty);
}

void printStats(int sum, int smallest, int largest, int size)
{
    float average = 0.00f;
    average = static_cast<float>(sum) / static_cast<float>(size);

    cout << "average: " << setprecision(6) << average << endl;
    cout << "sum: " << sum << endl;
    cout << "smallest: " << smallest << endl;
    cout << "largest: " << largest << endl;
}
void printAscending(int arr[], int size)
{
    int i;
    int rowLength = 10;
    int currCol = 1;
    for (i = 0; i < size; i++)
    {   
        if(i == size - 1)
        {
            cout << setw(4) << arr[i] << endl;    
        } 
        else 
        {
            printColumn(arr[i],currCol,rowLength);
            currCol++;
             if(currCol == rowLength+1)
            {
                currCol = 1;
            }
        }
    }
}
void printDescending(int arr[], int size)
{
    int i;
    int rowLength = 10;
    int currCol = 1;
    for (i = size - 1; i >= 0; i--)
    {
        if(i == 0)
        {
            cout << setw(4) << arr[i] << endl;
        } 
        else 
        {
            printColumn(arr[i],currCol,rowLength);
            currCol++;
             if(currCol == rowLength+1)
            {
                currCol = 1;
            }
        }
    }
}


int main()
{
    int MAX_SIZE = 50;
    int ACTUAL_SIZE;
    int arr[MAX_SIZE];
    int count = 0;
    int largest = -1000;
    int smallest = 1000;
    int sum = 0;

    cout << "Please enter any number of integers." << endl;
    while (1)
    {
        int value;
        cin >> value;

        if (value <= 0)
        {
            break;
        }
        if(count >= MAX_SIZE)
        {
            continue;
        }
        arr[count] = value;
        ACTUAL_SIZE += 1;

        if (value > largest)
        {
            largest = value;
        }
        if (value < smallest)
        {
            smallest = value;
        }
        sum += value;
        count++;
    }

    if (ACTUAL_SIZE == 0)
    {
        cout << "There is no data" << endl;
        return -1;
    }

    printStats(sum, smallest, largest, ACTUAL_SIZE);

    cout << "original input numbers: " << endl;
    printAscending(arr, ACTUAL_SIZE);

    cout << "reverse input numbers: " << endl;
    printDescending(arr, ACTUAL_SIZE);

    sortArray(arr, ACTUAL_SIZE);
    cout << "sorted array: " << endl;
    printAscending(arr, ACTUAL_SIZE);

    return 0;
}