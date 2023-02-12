//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 02/12/2023
// Status    : Completed
// This program calculates and displays the gross pay of employees
// based on their hours worked and hourly rate, reported in a
// payroll file.
//******************************************************************

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

class Payroll {
    private:
        double hourlyRate;
        double hoursWorked;
    public:
        void set(double, double);
        double getHourlyRate();
        double getHoursWorked();
        double getGrossPay();
};
void Payroll::set(double newRate, double newHours) {
    hourlyRate = newRate;
    hoursWorked = newHours;
}
double Payroll::getHourlyRate() {
    return hourlyRate;
}
double Payroll::getHoursWorked() {
    return hoursWorked;
}
double Payroll::getGrossPay() {
    return hoursWorked * hourlyRate;
}

int main() {
    const string PATH = "/Users/nicholas/academic_sandbox/src/fundamentals/chapter_8/assignment_8/"; // Absolute path of payroll.dat
    const string PAYROLL_FILE = "payroll.dat";  // Payroll filename
    const int NUM_EMPLOYEES = 7;                // Number of employees
    Payroll storePayroll[NUM_EMPLOYEES];        // Array of employee Payroll instances
    ifstream payrollData(PATH+PAYROLL_FILE);    // Input file instance of payroll.dat
    double readHours,                           // Hours worked read from payroll.dat
           readRate;                            // Hourly rate read from payroll.dat

    // Validate that file opening did not fail

    if (payrollData.fail()) {
        cout << "A problem occurred when opening the file. Quitting";
        exit(-1);
    }

    // Read employee data & assign to array

    for (int i=0; i<NUM_EMPLOYEES; i++) {
        payrollData >> readHours;
        payrollData >> readRate;
        
        Payroll employeePayroll = Payroll();    // Employee's Payroll instance
        employeePayroll.set(readHours, readRate);
        
        storePayroll[i] = employeePayroll;
    }

    // Display payroll array contents

    cout << "Employee  Gross pay" << endl
         << "========  =========" << endl;
    cout << fixed << setprecision(2);

    for (int j=0; j<NUM_EMPLOYEES; j++) {
        cout << "   " << j+1 << ":     $" << setw(7) << storePayroll[j].getGrossPay() << endl;
    }

    return 0;
}