#include "Quadratic.h"
#include <cmath>

Quadratic::Quadratic() {
    a = 0.0;
    b = 0.0;
    c = 0.0;
}

Quadratic::Quadratic(const double& newA, const double& newB, const double& newC) {
    set(newA, newB, newC);
}

void Quadratic::set(double newA, double newB, double newC) {
    a = newA;
    b = newB;
    c = newC;
}

double Quadratic::getA() const {
    return a;
}

double Quadratic::getB() const {
    return b;
}

double Quadratic::getC() const {
    return c;
}

int Quadratic::getNumberOfRoots() const {

    if (a != 0.0) {
        if (pow(b, 2) > 4*a*c) {
            return 2;
        } else if (pow(b, 2) == 4*a*c) {
            return 1;
        } else {
            return 0;
        }
    } else if (b != 0.0) {
        return 1;
    } else if (c != 0.0) {
        return 0;
    }
    return 3;
}

double Quadratic::getFirstRoot() const {
    
    if (getNumberOfRoots() == 1) {
        if (a == 0.0 & b != 0.0) {
            return -c / b;
        }
        return -b / (2 * a);
    } else if (getNumberOfRoots() == 3) {
        return 0.0;
    }

    return (sqrt(pow(b, 2) - 4*a*c) - b) / (2 * a);
}

double Quadratic::getSecondRoot() const {
    
    if (getNumberOfRoots() == 1) {
        return getFirstRoot();
    } else if (getNumberOfRoots() == 3) {
        return 0.0;
    }

    return -(sqrt(pow(b, 2) - 4*a*c) + b) / (2 * a);
}