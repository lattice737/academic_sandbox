// Chapter 2 Concepts

#include<iostream>
#include<string>
using namespace std;

// Literal - a piece of data hardcoded into a program
// Identifier - a programmer-defined name representing some program element (e.g. variable)
// Bit pattern - a permutation of 0s and 1s
// Hexadecimal prefix - 0x
// Octal prefix - 0
// Mantissa - the decimal multiplicand of scientific notation
// Printable characters are encoded as integers (ASCII)
// Null terminator - a byte storing char \0, appended to the end of a string to mark its end
// Initialization - variable definition and assignment in a single statement
// lvalue - identifies a place in memory whose contents may change
// rvalue - any expression with a value
// auto - a keyword that prompts the compiler to determine a variable's data type from its initialized value,
//        usually to simplify complex declarations

// Integers
// short:                       [-32k, 32k]
// unsigned short:              [0, 65k]
// int ~ long:                  [-2.1e9, 2.1e9]
// unsigned ~ unsigned long:    [0, 4.2e9]
// long long:                   [-9.2e18, 9.2e18]
// unsigned long long:          [0, 8.4e18]

// Floating points
// float (7 sigfigs):           [+/-3.4e-38, +/-3.4e38]
// double (16 sigfigs):         [+/-1.7e-308, +/-1.7e308]
// long double (16 sigfigs):    [+/-1.7e-308, +/-1.7e308]

int main() {
    int checking;
    unsigned miles;
    long diameter;
    long long small;
    int floors =  15,
        rooms  = 300,
        suites =  30;
    float distance = 1.496E8;
    double mass = 1.989E30;
    long double example = 1034.56L;
    char letter = 65;
    string moveTitle = "Wheels of Fury";
    bool trueOrFalse = true;
    double apple;
    double basePayRate     = 18.25,
           overtimePayRate = 27.38,
           regularHours    = 40.0,
           overtimeHours   = 10,
           regularWages,
           overtimeWages,
           totalWages;

    checking = -20;
    miles = 4276;
    diameter = 100000L;
    small = 1250000LL;

    cout << "Balance: $" << checking << endl;
    cout << "Distance: " << miles << " mi\n";
    cout << "Diameter: " << diameter << " light years\n";
    cout << "\nThe Grande Hotel has " << floors << " floors\n";
    cout << "with " << rooms << " rooms and " << suites << " suites\n";
    cout << "\nThe between the Earth and the Sun is " << distance << " km\n";
    cout << "The Sun\'s mass is " << mass << " kg\n";
    cout << "\nVariable \'letter\' should be letter A: " << letter << endl;
    cout << "\nMy favorite movie is " << moveTitle << endl;
    cout << "\nVariable \'trueOrFalse\' should be integer 1: " << trueOrFalse << endl;
    cout << "\nA short integer is " << sizeof(short) << " bytes\n";
    cout << "A long integer is " << sizeof(long) << " bytes\n";
    cout << "An apple can be eaten in " << sizeof(apple) << " bytes\n";
    
    regularWages = basePayRate * regularHours;
    overtimeWages = overtimePayRate * overtimeHours;
    totalWages = regularWages + overtimeWages;
    
    cout << "\nTotal wages for the week: $" << totalWages << endl;

    return 0;
}