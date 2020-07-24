//
// sizeof.cpp
//
// Lisa Lehrman
// 6/18/2020
// CS14E - Lab 2
// Displays the size of the different C++ data types.

#include <iostream>
using namespace std;

int main() {
    cout << "Long Double: " << sizeof(long double) << endl;
    cout << "Double: " << sizeof(double) << endl;
    cout << "Float " << sizeof(float) << endl;
    cout << "Long Long: " << sizeof(long long) << endl;
    cout << "Long: " << sizeof(long) << endl;
    cout << "Int: " << sizeof(int) << endl;
    cout << "Short: " << sizeof(short) << endl;
    cout << "Char: " << sizeof(char) << endl;
    cout << "Bool: " << sizeof(bool) << endl;

    return 0;
}
