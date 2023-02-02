//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 02/01/2023
// Status    : Completed
//
// This program calculates the time of travel for sound
// in seconds through a user-selected medium across a
// user-inputted distance (in feet).
//******************************************************************

#include<iostream>
#include<iomanip>
#include<cctype>

using namespace std;

int main() {
    const int AIR_SPEED = 1100,         // Speed of sound in air
              WATER_SPEED = 4900,       // Speed of sound in water
              STEEL_SPEED = 16400;      // Speed of sound in steel
    enum Medium {Air=1, Water, Steel};  // Media enumeration
    bool invalidInput = false;          // Invalid input flag
    double travelTime,                  // Calculated time of travel in seconds
           distance;                    // User-input travel distance in feet
    char medium;                        // User-input medium selection

    // Display menu & get user input
    
    cout << "This program calculates the time it takes in seconds for a sound wave\n"
         << "to travel a specific distance through a particular medium\n\n"
         << "Select the number of the medium for the sound to travel through:\n"
         << "\t1. Air" << endl
         << "\t2. Water" << endl
         << "\t3. Steel" << endl;
    cin >> medium;

    cout << "\nEnter the number of feet the sound wave will travel: ";
    cin >> distance;

    // Validate input

    switch (medium) {
        case 49:
        case Air: travelTime = distance / AIR_SPEED;
        break;
        case 50:
        case Water: travelTime = distance / WATER_SPEED;
        break;
        case 51:
        case Steel: travelTime = distance / STEEL_SPEED;
        break;
        default:
        invalidInput = true;
    }

    // Display results

    if (invalidInput)
        cout << "\nInvalid input: " << medium << " is not on the menu";
    else
        cout << "The sound wave will travel " << fixed << setprecision(1) << distance
             << " feet in " << setprecision(4) << travelTime << " seconds";

    return 0;
}