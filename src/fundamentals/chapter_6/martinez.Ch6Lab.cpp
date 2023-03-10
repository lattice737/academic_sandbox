//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 02/05/2023
// Status    : Completed
//
// This program displays the highest earning division of a company
// based on inputted quarterly sales for four division
//******************************************************************

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

void getSales(double&, string);
void findHighest(double, double, double, double);

int main() {
    enum Divisions {Northeast=1, Southeast, Northwest, Southwest};  // Division enumeration
    double northeastSales,  // Northeast division quarterly sales
           southeastSales,  // Southeast division quarterly sales
           northwestSales,  // Northwest division quarterly sales
           southwestSales;  // Southwest division quarterly sales

    // Take division sales amounts

    for (int division=1; division<5; division++) {
        if (division == Northeast)
            getSales(northeastSales, "Northeast");
        else if (division == Southeast)
            getSales(southeastSales, "Southeast");
        else if (division == Northwest)
            getSales(northwestSales, "Northwest");
        else if (division == Southwest)
            getSales(southwestSales, "Southwest");
    }

    // Determine & display top-selling division

    findHighest(northeastSales, southeastSales, northwestSales, southwestSales);

    return 0;
}

// Sets quarterly sales value based on validated user input
void getSales(double& quarterlySales, string divisionString) {
    string prompt = "Enter the sales for the " + divisionString + " division: ";;  // Prompt for user input

    cout << prompt;
    cin >> quarterlySales;

    while (quarterlySales < 0.0) {
        cout << "Sales figures cannot be negative. Please re-enter" << endl;
        cout << prompt;
        cin >> quarterlySales;
    }
}

// Determines the division with the highest sales and displays result
void findHighest(double northeastSales, double southeastSales, double northwestSales, double southwestSales) {
    double maxOfTwo,        // Max between two values
           maxOfThree,      // Max between maxOfTwo and another value
           maxOfFour;       // Max between maxOfThree and another value
    string divisionString;  // Section-dividing string

    // Determine division with the highest sales

    maxOfTwo = northeastSales > southeastSales ? northeastSales : southeastSales;
    maxOfThree = northwestSales > maxOfTwo ? northwestSales : maxOfTwo;
    maxOfFour = southwestSales > maxOfThree ? southwestSales : maxOfThree;

    // Display result

    if (maxOfFour == northeastSales)
        divisionString = "Northeast";
    else if (maxOfFour == southeastSales)
        divisionString = "Southeast";
    else if (maxOfFour == northwestSales)
        divisionString = "Northwest";
    else
        divisionString = "Southwest";

    cout << "\nThe " << divisionString << " division had the highest sales this quarter" << endl;
    cout << fixed << setprecision(2) << "Their sales were $" << maxOfFour;
}