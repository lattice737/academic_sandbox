
#ifndef QUADRATIC_
#define QUADRATIC_

class Quadratic {
    private:
        double a;
        double b;
        double c;
    public:
        Quadratic();
        Quadratic(const double& newQuadraticCoefficient, const double& newLinearCoefficient, const double& newConstantTerm);
        void set(double newQuadraticCoefficient, double newLinearCoefficient, double newConstantTerm);
        double getA() const;
        double getB() const;
        double getC() const;
        double getFirstRoot() const;
        double getSecondRoot() const;
        int getNumberOfRoots() const;
};

#endif