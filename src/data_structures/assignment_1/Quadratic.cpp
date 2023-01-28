#include "Quadratic.h"
#include <cmath>

Quadratic::Quadratic() {
    quadraticCoefficient = 0.0;
    linearCoefficient = 0.0;
    constantTerm = 0.0;
    discriminant = 0.0;
}

Quadratic::Quadratic(const double& newQuadraticCoefficient, const double& newLinearCoefficient, const double& newConstantTerm) {
    set(newQuadraticCoefficient, newLinearCoefficient, newConstantTerm);
}

void Quadratic::set(double newQuadraticCoefficient, double newLinearCoefficient, double newConstantTerm) {
    quadraticCoefficient = newQuadraticCoefficient;
    linearCoefficient = newLinearCoefficient;
    constantTerm = newConstantTerm;
    setDiscriminant(newQuadraticCoefficient, newLinearCoefficient, newConstantTerm);
}

void Quadratic::setDiscriminant(double quadraticCoefficient, double linearCoefficient, double constantTerm) {
    discriminant = pow(linearCoefficient, 2) - 4 * quadraticCoefficient * constantTerm;
}

double Quadratic::getDiscriminant() const {
    return discriminant;
}

double Quadratic::getQuadraticCoefficient() const {
    return quadraticCoefficient;
}

double Quadratic::getLinearCoefficient() const {
    return linearCoefficient;
}

double Quadratic::getConstantTerm() const {
    return constantTerm;
}

int Quadratic::getNumberOfRoots() const {
    
    // *1) a != 0 and discriminant > 0 -> 2
    // *2) a != 0 and discriminant == 0 -> 1
    // *3) a != 0 and discriminant < 0 -> 0
    // *4) a == 0 and b != 0 -> 1
    // *5) a, b == 0, 0 and c != 0 -> 0
    // *6) a, b, c == 0, 0, 0 -> 3

    if (quadraticCoefficient != 0.0) {
        if (getDiscriminant() > 0.0) {
            return 2;
        } else if (getDiscriminant() == 0.0) {
            return 1;
        } else {
            return 0;
        }

    } else if (linearCoefficient != 0.0) {
        return 1;
    } else if (constantTerm != 0.0) {
        return 0;
    }

    return 3;
}

double Quadratic::getFirstRoot() const {

    // *1) 1 root: a == 0 and b != 0 -> -c/b
    // *2) 1 root: a != 0 and discriminant == 0 -> -b/2a
    // *3) 2 roots: (+/-sqrt(discriminant) - b) / (2 * a)
    
    int numberOfRoots = getNumberOfRoots();

    if (numberOfRoots == 1) {
        if (quadraticCoefficient == 0.0 & linearCoefficient != 0.0) {
            return -constantTerm / linearCoefficient;
        }
        return -linearCoefficient / (2 * quadraticCoefficient);
    }

    return (sqrt(getDiscriminant()) - linearCoefficient) / (2 * quadraticCoefficient);
}

double Quadratic::getSecondRoot() const {

    // *1) 1 root: getFirstRoot()
    // *2) 2 roots: -(b + discriminant) / (2 * a)
    
    if (getNumberOfRoots() == 1) {
        return getFirstRoot();
    }

    return -(sqrt(getDiscriminant()) + linearCoefficient) / (2 * quadraticCoefficient);
}