//
// program1.cpp
//
// Lisa Lehrman
// 7/27/2020
// CS14E lab 7.1
// A program that accepts 50 ints of input, does some calculations and prints the output 
// to a file. 


#include <iostream>
#include <iomanip> // setprecision, setw
using namespace std;



void sortArray(int array[], int size)
{
    bool dirty;
    int temp;
    do
    {
        dirty = false;
        for(int count = 0; count < (size-1); count++)
        {
            if(array[count] > array[count+1])
            {
                temp = array[count];
                array[count] = array[count+1];
                array[count+1] = temp;
                dirty = true;
            }
        }
    } while(dirty);
}

int main() {
    int INPUT_ARRAY_SIZE = 50;
    int arr[INPUT_ARRAY_SIZE];
    int count = 0;
    int largest = -1000; 
    int smallest = 1000;
    int sum = 0;
    float average = 0.00f;
    cout << "Please enter exactly 50 integers." << endl;
    while(count < INPUT_ARRAY_SIZE)
    {
        int value;
        cin >> value;
        arr[count] = value;
        
        if(value > largest)
        {
            largest = value;
        }
        if(value < smallest)
        {
            smallest = value;
        }
        sum += value;
        count++;
    }
    average = static_cast<float>(sum)/static_cast<float>(INPUT_ARRAY_SIZE);

    cout << "average: " << setprecision(6) << average << endl;
    cout << "sum: " << sum << endl;
    cout << "smallest: " << smallest << endl;
    cout << "largest: " << largest << endl;
    
    int i;
    int rowLength = 10;
    int currCol = 1;

    cout << "original input numbers: " << endl;
    for(i=0; i<INPUT_ARRAY_SIZE; i++)
    {
        cout << setw(4) << arr[i];
        if(rowLength == currCol)
        {
            cout << '\n';
            currCol = 0;
        } 
        else 
        {
            cout << '\t';        
        }
        currCol++;
    }

     cout << "reverse input numbers: " << endl;
    for(i=INPUT_ARRAY_SIZE-1; i>=0; i--)
    {
        cout << setw(4) << arr[i];
        if(rowLength == currCol)
        {
            cout << '\n';
            currCol = 0;
        } 
        else 
        {
            cout << '\t';        
        }
        currCol++;
    }

    sortArray(arr, INPUT_ARRAY_SIZE);
    cout << "sorted array: " << endl;
    for(i=0; i<INPUT_ARRAY_SIZE; i++)
    {
        cout << setw(4) << arr[i];
        if(rowLength == currCol)
        {
            cout << '\n';
            currCol = 0;
        } 
        else 
        {
            cout << '\t';        
        }
        currCol++;
    }
    return 0;
}
