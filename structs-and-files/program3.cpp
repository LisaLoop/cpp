//
// program3.cpp
//
// Lisa Lehrman
// 7/31/2020
// CS14E Assignment 10
// A program that displays a menu for the user to place an order and then prints a bill.

#include <iostream> // istream
#include <iomanip>
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

void PrintItem(ostream &outputFile, MenuItem menu)
{
    outputFile << "Name: " << menu.name << "\tPrice: " << setprecision(2) << fixed << "$" << menu.price << endl;
}

void PrintMenu(ostream &outputFile, MenuItem menus[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        outputFile << (i + 1) << ". "; 
        PrintItem(outputFile, menus[i]);
    }
}

void PrintCheck(int order[], MenuItem menus[], int count)
{
    cout << "You ordered " << count << " items." << endl;
    int i;
    float totalPrice;
    for (i = 0; i < count; i++)
    {
        int menuIndex = order[i];
        if (menuIndex >= 0)
        {
            PrintItem(cout, menus[menuIndex]);
            totalPrice += menus[menuIndex].price;
        }
    }
    cout << "Grand total: " << setprecision(2) << fixed << "$" << totalPrice << endl;
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
    int order[MAX] = {-1};
    MenuItem menus[MAX] = {};

    ReadItem(inputFile, menus);
    PrintMenu(cout, menus);
    int input;
    int count = 0;
    while (input != -1)
    {
        cout << "Please enter the number of the menu item you would like." << endl;
        cin >> input;
        if (input < 0 || input > 10)
        {
            if (input != -1)
            {
                cout << "Invalid menu item selected. This will be reported on your permanent record." << endl;
            }
            continue;
        }
        int i;
        bool duplicate = false;
        for(i=0; i<MAX; i++)
        {
            if(input == order[i])
            {
                cout << "The item you ordered is no longer available." << endl;
                duplicate = true;
                break;
            }
        }
        if(duplicate == false)
        {
            order[count] = input-1;
            count++;
        }
        if(count == MAX)
        {
            break;
        }
        continue;
    }
    
    PrintCheck(order, menus, count);
    inputFile.close();
    outputFile.close();
    return 0;
}