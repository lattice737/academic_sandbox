#ifndef RECTANGLE_
#define RECTANGLE_

#include "RectangleInterface.h"

class Rectangle : public RectangleInterface {
    private:
        double length;
        double width;
    public:
        Rectangle();
        bool set(const double newLength, const double newWidth);
        double getLength() const;
        double getWidth() const;
        double getArea() const;
};

#endif