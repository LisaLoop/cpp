//
// lab-5.cpp
//
// Lisa Lehrman
// CS14E 7/8/2020
// This program rewrites loops using various other loops, such as for, while, and do while.

#include <iostream>
using namespace std;

int main() {
//////////////////////// 1
//    int i,n;
//    cout << "Please enter a value for n :";
//    cin >> n;
//////////////////////// example
//    for( i = 0; i < n; i++ )
//    {
//     cout << i << " ";
//    }
//    cout << endl;
//////////////////////// 1 a
//    i = 0;
//    while(i < n)
//    {
//        cout << i << " ";
//        i++;
//    }
//    cout << endl;
//////////////////////// 1 b
//    i = 0;
//    do
//    {
//        cout << i << " ";
//        i++;
//    }while(i < n);
//     cout << endl;
//////////////////////// 2
//    int n;
//    cout << "Please enter a value for n :";
//    cin >> n;
    /////////////////////// example
//    while( n > 0 )
//    {
//     cout << n << " ";
//     n /= 2;
//    }
//    cout << endl;
//////////////////////// 2 a
//    do {
//        cout << n << " ";
//        n /= 2;
//    }while(n > 0);
//    cout << endl;
//////////////////////// 2 b
//    int i;
//    for(i=0; n > 0; i++)
//    {
//        cout << n << " ";
//        n /= 2;
//    }
//    cout << endl;
//////////////////////// 3
    // 5 -> 1 2 4
    // 10 -> 1 2 4 8
    int i, n;
    cout << "Please enter a value for n :";
    cin >> n;
//    i = 1;
//    do
//    {
//     cout << i << " ";
//     i *= 2;
//    } while( i <= n );
//    cout << endl;
//////////////////////// 3 a
//    for(i=1; i <= n; i *= 2)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
 //////////////////////// 3 b
    i = 1;
    while(i <= n)
    {
        cout << i << " ";
        i *= 2;
    }
    cout << endl;
    
    return 0;
}
