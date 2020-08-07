//
// accounts.cpp
//
// Lisa Lehrman
// 7/31/2020
// CS14E Final Project
// A program that reads account data from an input file and prints an
// audit trail to an output file.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX = 100;
struct ACCOUNT
{
    int number;
    string name;
    double balanceDue;
    double creditLimit;
};
struct TRANSACTION
{
    int accountNumber;
    double amount;
};
// read a single account record from the file into a struct passed by reference (for the 'A' command)
void ReadAccountRecord(istream &input, ACCOUNT &a)
{
    input >> a.number;
    input >> a.name;
    input >> a.balanceDue;
    input >> a.creditLimit;
}
// reads a single transaction record from the input file
void ReadTransactionRecord(istream &input, TRANSACTION &t)
{
    input >> t.accountNumber;
    input >> t.amount;
}
// Adds a user account from input
void AddAccount(ACCOUNT &a, ACCOUNT customers[], int &customersCount)
{
    customers[customersCount] = a;
    customersCount++;
}
// a helper function to sort accounts
void exchange(ACCOUNT &a, ACCOUNT &b)
{
    ACCOUNT temp = a;
    a = b;
    b = temp;
    return;
}
// sorts the customer's accounts by account number
void SortAccounts(ACCOUNT customers[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (customers[i].number > customers[j].number)
            {
                exchange(customers[i], customers[j]);
            }
        }
    }
}
// Prints the account information for a single customer
void PrintAccount(ostream &output, ACCOUNT a)
{
    output << setw(7) << a.number << setw(50) << a.name << setw(20) << setprecision(2) << fixed << a.balanceDue << setw(20) << setprecision(2) << fixed << a.creditLimit << endl;
}
// Prints all customer accounts
void PrintAccounts(ostream &output, ACCOUNT customers[], int customersCount)
{
    output << setw(7) << "Account" << setw(50) << "Name" << setw(20) << "Balance" << setw(20) << "Limit" << endl;
    int i;
    for (i = 0; i < customersCount; i++)
    {
        PrintAccount(output, customers[i]);
    }
    output << '\n'
           << endl;
};
// Finds an account by account number using a binary search algorithm
int FindAccount(ACCOUNT customers[], int customersCount, int accountNumber)
{
    int lo = 0, hi = customersCount - 1, mid;
    bool found = false;
    while (!found && lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (customers[mid].number == accountNumber)
        {
            found = true;
        }
        else if (customers[mid].number > accountNumber)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return found ? mid : -1;
}
// posts a payment to a customers account, over payments are allowed
void PostPayment(ACCOUNT &a, double amount)
{
    a.balanceDue -= amount;
}
// posts a charge to a customer's account
void PostCharge(ACCOUNT &a, double amount)
{
    a.balanceDue += amount;
}
// checks is the credit is available to use. Will disallow transaction that exceed the credit limit. (check happens in main)
bool isCreditAvailable(ACCOUNT a, double amount)
{
    double remainingCredit = a.creditLimit - a.balanceDue;
    return !(amount > remainingCredit);
}

int main()
{
    ofstream outputFile;
    ifstream inputFile;
    string inputFileName;
    string outputFileName;
    cout << "Please enter the name of the input file." << endl;
    cin >> inputFileName;
    cout << "Please enter the name of the output file." << endl;
    cin >> outputFileName;
    inputFile.open(inputFileName);
    outputFile.open(outputFileName);

    if (!inputFile || !outputFile)
    {
        cout << "Something went wrong" << endl;
        return -1;
    }

    ACCOUNT customers[MAX] = {};
    char input;
    char code;
    int customersCount = 0;
    while (inputFile >> input)
    {
        switch (input)
        {
        case 'A':
        {
            ACCOUNT a;
            ReadAccountRecord(inputFile, a);          // reads an account record from input
            AddAccount(a, customers, customersCount); // adds record to the customers array
            SortAccounts(customers, customersCount);  // sorts account by account number
            code = input;
        }
        break;
        case 'C':
        {
            TRANSACTION t;
            ReadTransactionRecord(inputFile, t);
            int accountIndex = FindAccount(customers, customersCount, t.accountNumber);
            if (accountIndex == -1)
            {
                outputFile << "The account does not exist\n"
                           << endl;
            }
            else
            {
                if (isCreditAvailable(customers[accountIndex], t.amount))
                {
                    outputFile << "A charge of " << t.amount << " was posted to account " << customers[accountIndex].number
                               << "\nThe account balance was: " << endl;
                    PrintAccount(outputFile, customers[accountIndex]);
                    PostCharge(customers[accountIndex], t.amount);
                    outputFile << "\nThe new account balance is: " << endl;
                    PrintAccount(outputFile, customers[accountIndex]);
                    outputFile << '\n'
                               << endl;
                }
                else
                {
                    outputFile << "The charge was disallowed."
                               << "\nAccount #        " << customers[accountIndex].number
                               << "\ncharge amount:   " << t.amount
                               << "\nbalance:         " << customers[accountIndex].balanceDue
                               << "\ncredit limit:    " << customers[accountIndex].creditLimit << '\n'
                               << endl;
                }
            }
            code = input;
        }
        break;
        case 'P':
        {
            TRANSACTION t;
            ReadTransactionRecord(inputFile, t);
            int accountIndex = FindAccount(customers, customersCount, t.accountNumber);
            if (accountIndex == -1)
            {
                outputFile << "The account does not exist\n"
                           << endl;
            }
            else
            {
                outputFile << "A payment of " << t.amount << " was posted to account " << customers[accountIndex].number
                           << "\nThe account balance was: " << endl;
                PrintAccount(outputFile, customers[accountIndex]);
                PostPayment(customers[accountIndex], t.amount);
                outputFile << "\nThe new account balance is: " << endl;
                PrintAccount(outputFile, customers[accountIndex]);
                outputFile << '\n'
                           << endl;
            }
            code = input;
        }
        break;
        case 'Q':
        {
            PrintAccounts(outputFile, customers, customersCount);
            code = input;
        }
        break;
        default:;
        }
    }

    if (code != 'Q')
    {
        PrintAccounts(outputFile, customers, customersCount);
    }
    inputFile.close();
    outputFile.close();
    return 0;
}