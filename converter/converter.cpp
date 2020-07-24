//
// converter.cpp
//
//
// Lisa Lehrman
// 6/20/20
// CS14E - Assignment 1
// A program that converts a distance given in feet and inches to meters.

#include <iostream>
#include <iomanip>
using namespace std;

const float INCH_IN_CENT = 2.54;
const float CENT_IN_METERS = 100.00;
const float INCHES_IN_FOOT = 12.00;

float getUserInput(string prompt){
    float f;
    std::cout << prompt << endl;
    std::cin >> f;
    while(1){
        if(cin.fail())
        {
            std::cout << "The value you entered is invalid. Please try again" << endl;
            cin.clear();
            std::cout << prompt << endl;
            std::cin >> f;
        } else {
            break;
        }
    }
    return f;
}

int main() {
    float inches, totalInInches, centToMeter, inchesToCent,feet;
    feet = getUserInput("Please enter a number in feet");
    inches = getUserInput("Please enter a number in inches, you may use a decimal.");
    totalInInches = (feet * INCHES_IN_FOOT) + inches;
    inchesToCent = totalInInches * INCH_IN_CENT;
    centToMeter = inchesToCent / CENT_IN_METERS;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << feet << " feet and " << inches << " inches is " << centToMeter << " meters" << endl;
    
    return 0;
}

//Run with these values, plus some of your own:
//0 feet 0 inches X
//1 foot 0 inches X
//0 feet 12 inches X
//0 feet 1 inch X
//0 feet 39.37 inches X
//0 feet 39.3701 inches X
//0 feet 39.38 inches X
//3 feet 3.3701 inches X
//10 feet 2.90 inches X
//0 feet 300.34 inches X
//a feet b inches
// 1e347 feet 1e512 inches
