//
//
//  mortgage-payment.cpp
//
// Lisa Lehrman
// 6/25/2020
// CS14E - Assignment 2
// A program that calculates a monthly payment on a mortage given
// the loan amount, annual interest rate, and number of years of mortgage.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// p = monthly payment
// m = amount of loan
// r = annual interest
// n = num of years
int main() {
    float p, m, r, n, exp, top, bottom;
    // collecting input
    cout << "Please enter the loan amount. " << endl;
    cin >> m;
    cout << "Please enter the annual interest rate. (e.g., 0.08 for 8%) " << endl;
    cin >> r;
    cout << "Please enter number of years. " << endl;
    cin >> n;
    
    // calculating
    exp = 12*n;
    top = m * pow((1 + r/12),exp) * r/12;
    bottom = pow((1+r/12),exp) - 1;
    p = top/bottom;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    
    cout << "The monthly payment is $" << p << endl;
    

    return 0;
}
