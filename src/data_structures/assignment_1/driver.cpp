// Programmer:      Nicholas Martinez
// Project number:  1
// Project Desc:    Quadratic class
// Course:          COSC 2436 PF III Data Structures
// Date:            January 28, 2023

#include "Quadratic.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

     const double SMALL_VALUE = 1.0,
                  MIDDLE_VALUE = 4.0,
                  LARGE_VALUE = 10.0,
                  SINGLE_ROOT1 = -MIDDLE_VALUE / (2*MIDDLE_VALUE),
                  SINGLE_ROOT2 = -MIDDLE_VALUE / MIDDLE_VALUE,
                  NULL_ROOT = 0.0,
                  DOUBLE_ROOT1 = (sqrt(pow(LARGE_VALUE, 2) - 4 * SMALL_VALUE * SMALL_VALUE) - LARGE_VALUE) / (2 * SMALL_VALUE),
                  DOUBLE_ROOT2 = -(sqrt(pow(LARGE_VALUE, 2) - 4 * SMALL_VALUE * SMALL_VALUE) + LARGE_VALUE) / (2 * SMALL_VALUE);
     Quadratic myQuadratic,
               quadraticCase1(SMALL_VALUE, LARGE_VALUE, SMALL_VALUE),
               quadraticCase2(MIDDLE_VALUE, MIDDLE_VALUE, SMALL_VALUE), // test values determined from this case
               quadraticCase3(LARGE_VALUE, SMALL_VALUE, LARGE_VALUE),
               linearCase(0.0, MIDDLE_VALUE, MIDDLE_VALUE),
               constantCase(0.0, 0.0, MIDDLE_VALUE),
               nullCase(0.0, 0.0, 0.0);
     string divider;

     divider.assign(20, '=');

    // Test default state & setter

     cout << divider << " DEFAULT & SETTER " << divider << endl;
     cout << "\nThe default quadratic coefficient is " << myQuadratic.getA() << endl
          << "The default linear coefficient is " << myQuadratic.getB() << endl
          << "The default constant term is " << myQuadratic.getC() << endl;
     
     cout << "\nSetting new coefficients" << endl;
     myQuadratic.set(0.5, 1.0, 1.0);

     cout << "\nThe new quadratic coefficient is " << myQuadratic.getA() << endl
          << "The new linear coefficient is " << myQuadratic.getB() << endl
          << "The new constant term is " << myQuadratic.getC() << endl
          << endl;

     // Test number-of-roots getter

     cout << divider << " NUMBER-OF-ROOTS GETTER " << divider << endl << endl;
     cout << quadraticCase1.getNumberOfRoots() << " real root(s) when a is nonzero and b squared > 4ac" << endl
          << quadraticCase2.getNumberOfRoots() << " real root(s) when a is nonzero and b squared equals 4ac" << endl
          << quadraticCase3.getNumberOfRoots() << " real root(s) when a is nonzero and b squared < 4ac" << endl
          << linearCase.getNumberOfRoots() << " real root(s) when a is zero but b is nonzero" << endl
          << constantCase.getNumberOfRoots() << " real root(s) when a and b are 0 but c is nonzero" << endl
          << nullCase.getNumberOfRoots() << " real root(s) when all coefficients are 0" << endl
          << endl;

     // Test first and second root getters with single root case

     cout << divider << " GETTERS WITH SINGLE & INF ROOT CASES " << divider << endl;
     cout << "\nThe real root of the second quadratic case should be -b/2a: " << SINGLE_ROOT1 << endl
          << "The first root is " << quadraticCase2.getFirstRoot() << endl
          << "The second root should be the first root: " << quadraticCase2.getSecondRoot() << endl;
     cout << "\nThe real root of the linear case should be -c/b: " << SINGLE_ROOT2 << endl
          << "The first root is " << linearCase.getFirstRoot() << endl
          << "The second root should be the first root: " << linearCase.getSecondRoot() << endl;
     cout << "\nThe first root should be " << NULL_ROOT << " for the null-coefficient case" << endl
          << "The first root is " << nullCase.getFirstRoot() << endl
          << "The second root should be the first root: " << NULL_ROOT << endl
          << "The second root is " << nullCase.getSecondRoot() << endl
          << endl;

     // Test first and second root getters with double root case

     cout << divider << " GETTERS WITH DOUBLE-ROOT CASE " << divider << endl;
     cout << "\nThe first real root of the first quadratic case should be (sqrt(b^2 - 4ac)-b)/2a: " << DOUBLE_ROOT1 << endl
          << "The first root is " << quadraticCase1.getFirstRoot() << endl
          << "\nThe second real root should be -(sqrt(b^2 - 4ac)+b)/2a: " << DOUBLE_ROOT2 << endl
          << "The second root is " << quadraticCase1.getSecondRoot() << endl;

    return 0;
}