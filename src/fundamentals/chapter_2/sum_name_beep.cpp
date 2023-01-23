//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 01/22/2023
// Status    : Completed
//
// This program stores and adds two integers, then displays
// my name and prompts the machine to beep
//******************************************************************

#include<iostream>
#include<string>

using namespace std;

int main() {
    int num1 = 62,
        num2 = 99,
        total = num1 + num2;
    string myName = "Nicholas Martinez";

    cout << "The sum of variables num1 and num2 is " << total << endl;
    cout << "My name is " << myName << "\a";

    return 0;
}