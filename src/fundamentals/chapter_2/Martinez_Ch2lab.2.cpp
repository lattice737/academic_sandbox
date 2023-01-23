//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 01/22/2023
// Status    : Completed
//
// This program converts a star basketball player's height from
// inches to the conventional feet plus inches form (e.g. 5'10")
//******************************************************************

#include<iostream>

using namespace std;

int main() {
    const int STAR_HEIGHT = 75,     // star player height
              INCHES_PER_FOOT = 12; // inches in one foot
    int feet,                       // total feet of height
        inches;                     // inches past total feet of height

    feet = 75 / 12;
    inches = 75 % 12;
    cout << "A 75-inch tall basketball player is " << feet << "\'" << inches << "\" tall";

    return 0;
}