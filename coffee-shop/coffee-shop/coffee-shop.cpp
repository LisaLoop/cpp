//
//
//  coffee-shop.cpp
//
// Lisa Lehrman
// 7/29/2020
// CS14E - Assignment 8
// A program that prompts the user for his or her
// order at the coffee shop, does some calculations
// and prints out the bill to the console.


#include <iostream>
#include <iomanip> // setprecision
using namespace std;

const float COFFEE_PRICE = 3.75f;
const float BAGEL_PRICE = 3.00f;
const float DANISH_PRICE = 2.25f;
const float TAX_PERCENTAGE = 0.09f;

// The first prompts for all three input values (the quantities of the items sold) and gives them back
// to the caller; Prompt the user for the number of each item being sold, and verify the inputs
// (separately force each input value to be greater than or equal to zero).
int promptUser(string foodItem){
    int quantity;
    while(1){
        cout << "Please enter the quantity of " << foodItem << " you would like to order." << endl;
        cin >> quantity;
        if(quantity >= 0){
            break;
        }
    }
     cout << "You ordered " << quantity << ' ' << foodItem << endl;

    return quantity;
}
// the second calculates the extended line amounts, subtotal, tax, and grand total of the bill;
// quantities,
//  extended line amounts, subtotal, tax, and grand total
void calculateBill(int cQ, int bQ, int dQ, float &totalCoffeePrice, float &totalBagelPrice, float &totalDanishPrice,float &subtotal, float &taxAmount, float &grandTotal){
    totalCoffeePrice = cQ * COFFEE_PRICE;
    totalBagelPrice = bQ *  BAGEL_PRICE;
    totalDanishPrice = dQ * DANISH_PRICE;
    subtotal = totalCoffeePrice + totalBagelPrice + totalDanishPrice;
    taxAmount = subtotal * TAX_PERCENTAGE;
    grandTotal = subtotal + taxAmount;
}

void printBill(int cQ, int bQ, int dQ, float subtotal, float taxAmount, float grandTotal){
    cout << "My Coffee Shop" << endl;
    cout << "Item";
    cout << setw(15);
    cout << "Quantity";
    cout << setw(10);
    cout << "Price" << endl;
    if(cQ > 0){
        cout << "Coffee";
        cout << setw(9);
        cout << cQ;
        cout << setw(10);
        cout << "$" << COFFEE_PRICE  << endl;
    }
    if(bQ > 0){
        cout<< setprecision(2) << fixed;
        cout << "Bagel";
        cout << setw(10);
        cout <<  bQ;
        cout << setw(10);
        cout << " $" << BAGEL_PRICE << endl;
    }
    if(dQ > 0){
        cout << "Danish ";
        cout << setw(8);
        cout << dQ;
        cout << setw(10);
        cout << " $" << DANISH_PRICE << endl;
       }
    cout<< setprecision(2) << fixed;
    cout << "Sub total $" << subtotal << endl;
    cout << "Tax $" << taxAmount << endl;
    cout << "Total $" << grandTotal << endl;
    
}
 
int main() {
    int coffeeQuantity, bagelQuantity, danishQuantity;
    float subtotal, grandTotal, taxAmount;
    float totalCoffeePrice, totalBagelPrice, totalDanishPrice; // quantity * price
    coffeeQuantity = promptUser("coffees");
    bagelQuantity = promptUser("bagels");
    danishQuantity = promptUser("danishes");
    calculateBill(coffeeQuantity, bagelQuantity, danishQuantity,
                  totalCoffeePrice, totalBagelPrice, totalDanishPrice,
                  subtotal, taxAmount, grandTotal);
    printBill(coffeeQuantity, bagelQuantity, danishQuantity, subtotal, taxAmount, grandTotal);
    return 0;
}
