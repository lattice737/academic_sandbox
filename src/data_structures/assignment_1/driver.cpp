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
                  ZERO_DISCRIMINANT_CASE_ROOT = -MIDDLE_VALUE / (2*MIDDLE_VALUE),
                  LINEAR_CASE_ROOT = -MIDDLE_VALUE / MIDDLE_VALUE,
                  _DOUBLE_ROOT_DISCRIMINANT = pow(LARGE_VALUE, 2) - 4 * SMALL_VALUE * SMALL_VALUE,
                  POSITIVE_DISCRIMINANT_CASE_ROOT1 = (sqrt(_DOUBLE_ROOT_DISCRIMINANT) - LARGE_VALUE) / (2 * SMALL_VALUE),
                  POSITIVE_DISCRIMINANT_CASE_ROOT2 = -(sqrt(_DOUBLE_ROOT_DISCRIMINANT) + LARGE_VALUE) / (2 * SMALL_VALUE);
     Quadratic myQuadratic,
               positiveDiscriminantCase(SMALL_VALUE, LARGE_VALUE, SMALL_VALUE),
               zeroDiscriminantCase(MIDDLE_VALUE, MIDDLE_VALUE, SMALL_VALUE), // test values determined from this case
               negativeDiscriminantCase(LARGE_VALUE, SMALL_VALUE, LARGE_VALUE),
               linearCase(0.0, MIDDLE_VALUE, MIDDLE_VALUE),
               constantCase(0.0, 0.0, MIDDLE_VALUE),
               nullCase(0.0, 0.0, 0.0);
     string divider;

     divider.assign(20, '=');

    // Test default state & setter

     cout << divider << " DEFAULT & SETTER " << divider << endl;
     cout << "\nThe default quadratic coefficient is " << myQuadratic.getQuadraticCoefficient() << endl
          << "The default linear coefficient is " << myQuadratic.getLinearCoefficient() << endl
          << "The default constant term is " << myQuadratic.getConstantTerm() << endl
          << "The default discriminant (b^2 - 4ac) is " << myQuadratic.getDiscriminant() << endl;
     
     cout << "\nSetting new coefficients" << endl;
     myQuadratic.set(0.5, 1.0, 1.0);

     cout << "\nThe new quadratic coefficient is " << myQuadratic.getQuadraticCoefficient() << endl
          << "The new linear coefficient is " << myQuadratic.getLinearCoefficient() << endl
          << "The new constant term is " << myQuadratic.getConstantTerm() << endl
          << "The new discriminant (b^2 - 4ac) is " << myQuadratic.getDiscriminant() << endl
          << endl;

     // Test number-of-roots getter

     cout << divider << " NUMBER-OF-ROOTS GETTER " << divider << endl << endl;
     cout << positiveDiscriminantCase.getNumberOfRoots() << " real root(s) when a is nonzero and discriminant is positive" << endl
          << zeroDiscriminantCase.getNumberOfRoots() << " real root(s) when a is nonzero and discriminant is 0" << endl
          << negativeDiscriminantCase.getNumberOfRoots() << " real root(s) when a is nonzero and discriminant is negative" << endl
          << linearCase.getNumberOfRoots() << " real root(s) when a is zero but b is nonzero" << endl
          << constantCase.getNumberOfRoots() << " real root(s) when a and b are 0 but c is nonzero" << endl
          << nullCase.getNumberOfRoots() << " real root(s) when all coefficients are 0" << endl
          << endl;

     // Test first and second root getters with single root case

     cout << divider << " GETTERS WITH SINGLE-ROOT CASE " << divider << endl;
     cout << "\nThe real root of the zero-discriminant case should be -b/2a: " << ZERO_DISCRIMINANT_CASE_ROOT << endl
          << "The first root is " << zeroDiscriminantCase.getFirstRoot() << endl
          << "The second root should be the first root: " << zeroDiscriminantCase.getSecondRoot() << endl;
     cout << "\nThe real root of the linear case should be -c/b: " << LINEAR_CASE_ROOT << endl
          << "The first root is " << linearCase.getFirstRoot() << endl
          << "The second root should be the first root: " << linearCase.getSecondRoot() << endl
          << endl;

     // Test first and second root getters with double root case

     cout << divider << " GETTERS WITH DOUBLE-ROOT CASE " << divider << endl;
     cout << "\nThe first real root of the positive-discriminant case should be (sqrt(discriminant)-b)/2a: " << POSITIVE_DISCRIMINANT_CASE_ROOT1 << endl
          << "The first root is " << positiveDiscriminantCase.getFirstRoot() << endl
          << "\nThe second real root should be -(sqrt(discriminant)+b)/2a: " << POSITIVE_DISCRIMINANT_CASE_ROOT2 << endl
          << "The second root is " << positiveDiscriminantCase.getSecondRoot() << endl;

    return 0;
}