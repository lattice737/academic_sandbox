//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 01/22/2023
// Status    : Completed
//
// This program stores my name, age, height, GPA, and middle name
// initial, then displays them
//******************************************************************

#include<iostream>
#include<string>

using namespace std;

int main() {
    string name = "Nicholas";
    int age = 31;
    double height = 5.333,
           gpa = 3.6;
    char middleInitial = 'E';

    cout << "Name: " << name << "\nAge: " << age << "\nHeight: " << height << " ft\nGPA: " << gpa << "\nMiddle initial: " << middleInitial;

    return 0;
}