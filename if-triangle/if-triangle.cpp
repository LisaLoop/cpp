//
//
//  if-triangle.cpp
//
//  Lisa Lehrman
//  6/29/20
//  CS14E - Assignment 3
//
// A program that prompts for the (integer) lengths of the three sides of a triangle and
// prints a message saying whether the triangle is a right triangle or not.

#include <iostream>
using namespace std;


int main() {
    int sideA, sideB, sideC;
    bool isRight = false;
    string message;
    
    message = "It is not a right triangle.";
    
    cout << "Please enter side a: " << endl;
    cin >> sideA;
    cout << "Please enter side b: " << endl;
    cin >> sideB;
    cout << "Please enter side c: " << endl;
    cin >> sideC;
    
    // assuming sideA is the hypotenuse
    if(sideA*sideA == sideB*sideB + sideC*sideC)
    {
        isRight = true;
    }
    if(sideB*sideB == sideA*sideA + sideC*sideC)
    {
        isRight = true;
    }
    if(sideC*sideC == sideB*sideB + sideA*sideA)
    {
        isRight = true;
    }
    if(isRight)
    {
        message = "The sides you entered form a right triangle.";
    }
    
    cout << message << endl;
    return 0;
}
