//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 01/28/2023
// Status    : Completed
//
// This program calculates the assessed value and property tax
// for an input property value and tax rate
//******************************************************************

#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    const double ASSESSED_VALUE_PROPORTION = 0.6,   // assessed value fraction of actual value
                 TAX_UNIT = 100.0;                  // smallest dollar amount charged at tax rate
    double actualPropertyValue,                     // initial property value before tax
           assessedValue,                           // taxable proportion of actual property value
           taxRate,                                 // amount charged per tax unit
           propertyTax;                             // total tax of the assessed value 
           
    // Take initial values as input

    cout << "Enter the actual property value: $";
    cin >> actualPropertyValue;

    cout << fixed << setprecision(2);
    cout << "Enter the amount of tax per $" << TAX_UNIT << " of assessed value: $";
    cin >> taxRate;

    // Calculate final values & display

    assessedValue = ASSESSED_VALUE_PROPORTION * actualPropertyValue;
    propertyTax = assessedValue * taxRate / TAX_UNIT;

    cout << endl;
    cout << left << setw(15) << "Property Value:" << "  $" << right << setw(12) << actualPropertyValue << endl
         << left << setw(15) << "Assessed Value:" << "  $" << right << setw(12) << assessedValue << endl
         << left << setw(15) << "Property Tax:" << "  $" << right << setw(12) << propertyTax << endl;

    return 0;
}