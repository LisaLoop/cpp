//
// if-else-telephone.cpp
//
// Lisa Lehrman
// 7/1/2020
// CS14E Assignment 4
// A  program that takes a single character and prints the corresponding digit on the old-style
// dial telephone keypad, if it exists.

#include <iostream>
using namespace std;

int main() {
    char letter;
    int digit = 0;
    
    cout << "Please enter a single letter and the program will tell" << endl
    << "you the digit it corresponds to on the telephone keypad:" << endl;
    cin >> letter;
    if(letter == 'A' || letter == 'B' || letter == 'C')
    {
        digit = 2;
    } else if(letter == 'D' || letter == 'E' || letter == 'F')
    {
        digit = 3;
    } else if(letter == 'G' || letter == 'H' || letter == 'I')
    {
        digit = 4;
    } else if(letter == 'J' || letter == 'K' || letter == 'L')
    {
        digit = 5;
    } else if(letter == 'M' || letter == 'N' || letter == 'O')
    {
        digit = 6;
    } else if(letter == 'P' || letter == 'R' || letter == 'S')
    {
        digit = 7;
    } else if(letter == 'T' || letter == 'U' ||letter == 'V' )
    {
        digit = 8;
    } else if(letter == 'W' || letter == 'X' || letter == 'Y')
    {
        digit = 9;
    } else if (letter == 'a' || letter == 'b' || letter == 'c' || letter == 'd' || letter == 'e' || letter == 'f' || letter == 'g' || letter == 'h' || letter == 'i' || letter == 'j' || letter == 'k' || letter == 'l' || letter == 'm' || letter == 'n' || letter == 'o' || letter == 'p' || letter == 'q' || letter == 'r' || letter == 's' || letter == 't' || letter == 'u' || letter == 'v' || letter == 'w' || letter == 'x' || letter == 'y' || letter == 'z')
    {
        cout << "The character " << letter << " is not a capital letter." << endl;
    } else
    {
        cout << "The character " << letter << " doesn't correspond to any digit on the keypad." << endl;
        digit = -1;
    };
    
    if(digit > 0)
    {
        cout << "The character " << letter << " corresponds to the digit "  << digit << " on the keypad" << endl;
    }

    return 0;
}

