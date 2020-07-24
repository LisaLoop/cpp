//
//  sieve-of-eratosthenes.cpp
//
//  Lisa Lehrman
//  7/22/2020
// CS14E Assignment 9
// A Program that uses Eratosthenes’ algorithm to calculate and print out all the prime numbers less than or equal to 10000 to a file.

#include <iostream>
#include <fstream>
using namespace std;

int const MAX = 10000;
int main() {
    bool a[10001] = {true};
    // sets all array elements to true
    int i;
    for(i=0; i<MAX; i++){
        a[i] = true;
    }
    a[0] = false;
    a[1] = false;
    
    int n;
    int j;
    for(n=2; n<=MAX/2; n++)
    {
        int index = n;
        bool isPrime = a[index];
        if(isPrime == true)
        {
            // turn off all multiples
            for(j=index; j <= MAX; j+= index)
            {
                if(index == j)
                {
                    continue;
                } else
                {
                    a[j] = false;
                }
                
            }
        }
    }
    

    ofstream fout;
    fout.open("primes.txt");
    if(!fout)
    {
        cout << "Error" << endl;
        return -1;
    } else {
        cout << "working";
     }
    

    int k;
    int colSize=8;
    int currCol=0;
    for(k=0; k<=MAX; k++)
    {
        bool isPrime = a[k];
        if(isPrime)
        {
            if(currCol == colSize)
            {
                fout << '\n';
                currCol = 0;
            } else if(currCol != 0)
            {
                fout << '\t';
            }
            fout << k;
            currCol++;
            
        }
       
    }
    fout.close();
    return 0;
}

