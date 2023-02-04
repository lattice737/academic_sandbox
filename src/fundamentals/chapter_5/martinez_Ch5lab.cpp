//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 02/04/2023
// Status    : Completed
//
// This program displays a bar graph of $100s sold for the day
// by three stores, based on daily sales entered
//******************************************************************

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

int main() {

    const double STAR=100;                  // $ multiples represented by one star
    const int N=3;                          // Number of stores with sales to be entered
    enum Stores {Store1=1, Store2, Store3}; // Store enumeration
    double enteredSales;                    // Sales entered by user
    string bar1,                            // $100s sold by Store 1
           bar2,                            // $100s sold by Store 2
           bar3;                            // $100s sold by Store 3
    int multiplier;                         // Star scalar

    for (int i=1; i<N+1; i++) { 

        // Take daily sales for one store & validate input

        cout << "Enter today's sales for Store " << i << ": ";
        cin >> enteredSales;

        while (enteredSales < 0.0) {
            cout << "Sales must be a positive number. Enter today's sales for Store " << i << ": ";
            cin >> enteredSales;
        }

        // Create asterisk string for a store

        multiplier = round(enteredSales / STAR);

        switch (i) {
            case Store1:
            bar1.assign(multiplier, '*');
            break;
            case Store2:
            bar2.assign(multiplier, '*');
            break;
            case Store3:
            bar3.assign(multiplier, '*');
        }
    }

    // Display results

    cout << endl;
    cout << setw(15) << "DAILY SALES" << endl
         << setw(17) << "(each * = $100)" << endl
         << "\nStore 1: " << bar1 << endl
         << "Store 2: " << bar2 << endl
         << "Store 3: " << bar3 << endl;

    return 0;
}