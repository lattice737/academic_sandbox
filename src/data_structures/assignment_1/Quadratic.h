
#ifndef QUADRATIC_
#define QUADRATIC_

class Quadratic {
    private:
        double quadraticCoefficient;
        double linearCoefficient;
        double constantTerm;
        double discriminant;
    public:
        Quadratic();
        Quadratic(const double& newQuadraticCoefficient, const double& newLinearCoefficient, const double& newConstantTerm);
        void set(double newQuadraticCoefficient, double newLinearCoefficient, double newConstantTerm);
        void setDiscriminant(double quadraticCoefficient, double linearCoefficient, double constantTerm);
        double getDiscriminant() const;
        double getQuadraticCoefficient() const;
        double getLinearCoefficient() const;
        double getConstantTerm() const;
        double getFirstRoot() const;
        double getSecondRoot() const;
        int getNumberOfRoots() const;
};

#endif