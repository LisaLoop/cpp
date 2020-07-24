//
// isOddDigit.cpp
//
// Lisa Lehrman
// 7/14/20.
// CS14E Assignment 7, part 1
// A program that tests whether or not a single digit character is an odd digit
// and returns a message to inform the user.

#include <iostream>
#include <cctype>
using namespace std;

bool isOddDigit(char ch){
    // 48 is the ascii value 0
    if(isdigit(ch) && (ch-48) % 2 != 0){
        return true;
    } else
    {
        return false;
    }
}

int main() {
    int i;
    string characters = "0123456789abcABC!;-%";
    for(i=0; i<characters.length(); i++){
        if(isOddDigit(characters[i]))
        {
            cout << "The character " << characters[i] << " is an odd digit" << endl;
        }
        else
        {
            cout << "The character " << characters[i] << " is not an odd digit" << endl;
        }
        
    }
    return 0;
}
