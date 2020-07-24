//
// pay-per-day.cpp
//
// Lisa Lehrman
// 7/6/2020
// CS14E Assignment 5, problem 1
// a program that prompts for a number of days, that calculates how much a person
// would earn over a period of days if they earn one cent for the first day, and their earnings continue to double over each day.

#include <iostream>
using namespace std;

int main() {
    int days;
    int earningsInCents = 0;
    int i;
    float totalPay = 0;
    cout << "Please enter a number of days" << endl;
    cin >> days;
    for(i = 0; i < days; i++)
    {
        if(i==0)
        {
            earningsInCents += 1;
        } else
        {
            earningsInCents += earningsInCents;
            
        }
        totalPay += earningsInCents;
        
        cout << "Pay for day " << i << " = " << earningsInCents << endl;
        
    }
    cout << "Total pay is " << (totalPay/100) << endl;
    
    return 0;
}
