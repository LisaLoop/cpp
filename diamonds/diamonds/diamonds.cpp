//
// diamonds.cpp
//
// Lisa Lehrman 7/8/2020
// CS14E Assignment 6
// A program that prints out a diamond shape to the console given appropriate input.

#include <iostream>
using namespace std;

void printCols(int num, char c)
  {
      int i;
      string s;
      for(i = 0; i < num; i++)
      {
          s += c;
      }
      cout << s;
  }

void printRow(int halfStars, int halfSpaces)
{
// Print left half
  printCols(halfSpaces, ' ');
  printCols(halfStars,'*');
// Print the middle
  printCols(1,'*');
// Print right half
  printCols(halfStars,'*');
  printCols(halfSpaces, ' ');
  cout << endl;
}

int main() {
    int rows;
    while(1)
    {
        cout << "Please enter a number of rows between 3-23:  ";
        cin >> rows;
        if(rows > 23 || rows < 3)
        {
            cout << "Your input was invalid. Please try again. " << endl;
        } else {
            break;
        }
    }
    if(rows % 2 == 0)
    {
        rows += 1;
    }
    
    int i,j;
    int halfSpace, halfStar;
    int middleStar = 1;
    int cols = rows;
    int halfCols = (cols-middleStar)/2;
    int halfRows = (rows-1)/2;
    // Print the top
    for(i=0; i < halfRows; i++)
    {
        halfStar = i;
        halfSpace = halfCols - halfStar;
        printRow(halfStar, halfSpace);
    }
    // Print the middle
    printRow(halfCols, 0);
    // Print the bottom
    for(j=halfRows-1; j >= 0; j--)
    {
        halfStar = j;
        halfSpace = halfCols - halfStar;
        printRow(halfStar, halfSpace);
    }

    return 0;
}
/*
                 R  St
      *       <- 0, 1
     ***      <- 1, 3   L 6sp, 1st |*| R 1st 6sp
    *****     <-
   *******
  *********
 ***********
************* ------middle-------
 ***********  <- 0
  *********   <- 1
   *******    <- 2
    *****     <- 3
     ***      <- 4
      *       <- 5,
 
 
 row = 0
 
 i = 0
 middle = row/2
 **/
