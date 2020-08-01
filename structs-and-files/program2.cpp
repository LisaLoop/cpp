//
// program2.cpp
//
// Lisa Lehrman
// 7/30/2020
// CS14E Assignment 10
// A program that prints 10 menu item structs to an output file

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;
struct MenuItem
{
    string name;
    float price;
};

void ReadItem(istream &inputFile, MenuItem menus[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        getline(inputFile, menus[i].name);
        (inputFile >> menus[i].price).get(); // returns the input string
    }
}

void PrintItem(ostream &outputFile, MenuItem menus[])
{
    int i;
    for(i=0; i<MAX; i++)
    {
    outputFile << menus[i].name << "\t" << menus[i].price << endl;
    }
}

int main()
{
    ofstream outputFile;
    ifstream inputFile;
    outputFile.open("output2.txt");
    inputFile.open("input2.txt");

    if (!inputFile || !outputFile)
    {
        cout << "Something went wrong" << endl;
        return -1;
    }

    MenuItem menus[MAX] = {};

    ReadItem(inputFile, menus);
    PrintItem(outputFile, menus);
    inputFile.close();
    outputFile.close();
    cout << "The output has been stored in output2.txt" << endl;
    return 0;
}