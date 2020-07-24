//
//  diamond2.cpp
//
// Lisa Lehrman
// 7/14/20
// CS14E Assignment 7, part 2
//
// A program that prints out a diamond shape to the console given appropriate input.

#include <iostream>
using namespace std;

// get and verify number of rows – do everything to make
// sure the number of rows is in the right range and is odd
int GetNRows(){
    int nRows;
    while(1)
    {
        cout << "Please enter a number of rows between 3-23:  ";
        cin >> nRows;
        if(nRows > 23 || nRows < 3)
        {
            cout << "Your input was invalid. Please try again. " << endl;
        } else {
            break;
        }
    }
    if(nRows % 2 == 0)
    {
        nRows += 1;
    }
    return nRows;
}
// given the number of rows and the current row number,
// calculate the number of spaces on this row
int CalcNumSpaces( int nRows, int row ){
    int middle, spaces, distance;
    middle = (nRows/2)+1;
     if(middle > row )
     {
         distance = middle - row;
     } else
     {
         distance = row - middle;
     }
    spaces = distance * 2;
    return spaces;
}

// given the number of rows and the current row number,
// calculate the number of stars (asterisks) on this row
int CalcNumStars( int nRows, int row ){
    int stars, spaces;
    spaces = CalcNumSpaces(nRows, row);
    stars = nRows - spaces;
    return stars;
}

// print n copies of the character ch on the current row
void PrintChars( int n, char ch ){
    int i;
    string s;
    for(i = 0; i < n; i++)
    {
        s += ch;
    }
    cout << s;
}

// draw the shape – do all the work to draw the shape
void DrawShape( int nRows ){ // totalRows
    int i, spaces, stars;
    for(i=1; i<nRows+1; i++)
    {
        spaces = CalcNumSpaces(nRows, i);
        stars = CalcNumStars(nRows, i);
        PrintChars(spaces/2, ' ');
        PrintChars(stars, '*');
        PrintChars(spaces/2, ' ');
        cout << endl;
    }
}

int main() {
    int nRows;
    nRows = GetNRows();
    DrawShape(nRows);
    return 0;
}
