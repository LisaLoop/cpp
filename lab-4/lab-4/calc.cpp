//
//
//  calc.cpp
//
//  Lisa Lehrman
//  7/1/20
//  CS14E - Lab 4
//  A program that prompts user to input a series of numbers, stopping when a negitive number is entered.
//  The program will do some calculations on the series of numbers the user entered, assuming there were values
//  greater than zero.


#include <iostream>
using namespace std;

int main() {
    int input, sum, count, largest, smallest;
    float average;
    sum = count = largest = 0;
    smallest = 999999999;
    input = 0;
    average = 1.0;

    while(1)
    {
        cout << "Please enter an integer value" << endl;
        cin >> input;
        if(input <= 0)
        {
            break;
        }

        if(input > largest)
        {
            largest = input;
        }
        if(input < smallest)
        {
            smallest = input;
        }
        sum += input;
        count++;
    }
    
    if(sum > 0 || count > 0)
    {
        average =  sum / count;
        cout << "The loop ran " << count << " times." << endl
             << "The sum of the input is " << sum << endl
             << "The largest number entered is " << largest
             << ". The smallest number entered is " << smallest << endl
             << " The average number is " << average << ". " << endl;
    } else {
        cout << "The statistics for the numbers entered don't exist." << endl;
    }
    
    
    
    return 0;
}
