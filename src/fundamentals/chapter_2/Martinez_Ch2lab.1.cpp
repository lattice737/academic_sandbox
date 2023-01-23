//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 01/22/2023
// Status    : Completed
//
// This program calculates the price that an electronics company
// should charge for a USB flash drive to make a certain margin of
// profit, based on certain initial conditions
//******************************************************************

#include<iostream>

using namespace std;

int main() {
    const int INVENTORY = 64;       // number of flash drives made
    const float UNIT_COST = 8.0,    // cost to make each flash drive
                MARGIN = .35;       // desired profit margin - 1.0 == 100%
    double unitPrice,               // price of each flash drive
           profit;                  // total earnings minus total cost


    // Calculates the needed flash drive price
    unitPrice = (1.0 + MARGIN) * UNIT_COST;
    cout << "To have a 35% profit, the flash drive should sell for $" << unitPrice << endl;

    // Displays profit amount for initial conditions
    profit = INVENTORY * (unitPrice - UNIT_COST);
    cout << "For " << INVENTORY << " units each costing $" << UNIT_COST << " to make, 35% profit is $" << profit;

    return 0;
}