//
// program1.cpp
//
// Lisa Lehrman
// 7/30/2020
// CS14E Assignment 10
// A program that prints a menu item and its price to an output file

#include <iostream> // istream
#include <fstream>
using namespace std;

struct MenuItem
{
    string name;
    float price;
};

void ReadItem(istream &inputFile, MenuItem &menu)
{
    getline( inputFile, menu.name ); 
    inputFile >> menu.price;
}

void PrintItem(ostream &outputFile, MenuItem menu)
{
    outputFile << "Name: " << menu.name << "\tPrice: " << menu.price << endl;
}

int main()
{
    ofstream outputFile;
    ifstream inputFile;
    outputFile.open("output1.txt");
    inputFile.open("input1.txt");

    if (!inputFile || !outputFile)
    {
        cout << "Something went wrong" << endl;
        return -1;
    }

    MenuItem menu;
    ReadItem(inputFile, menu);
    PrintItem(outputFile, menu);
    inputFile.close();
    outputFile.close();
    cout << "The output has been stored in output1.txt" << endl;
    return 0;
}