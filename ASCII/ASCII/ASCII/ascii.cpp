//
//  ascii.cpp
//
// Lisa Lehrman
// 7/6/2020
// A C++ program that prints a table of the ASCII characters from ' ' (space) to
// '~' (tilde). The characters are printed 16 to a line separated by spaces

#include <iostream>
using namespace std;

string ascii = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

int main() {
    int i;
    char newLineOrSpace;
    int width = 16;
    int counter = 1;
    
    for(i = 0; i < ascii.length(); i++)
    {
        if(counter == width)
        {
            newLineOrSpace = '\n';
            counter = 1;
        }
        else
        {
            newLineOrSpace = ' ';
            counter++;
        }
       
        if(i == ascii.length()-1)
        {
            cout << ascii[i] << endl;
        } else
        {
            cout << ascii[i] << newLineOrSpace;
        }
        
    }
    return 0;
}
