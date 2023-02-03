#ifndef RECTANGLE_
#define RECTANGLE_

#include "RectangleInterface.h"

class Rectangle : public RectangleInterface {
    private:
        DimensionType length;
        DimensionType width;
    public:
        Rectangle();
        bool set(const DimensionType& newLength, const DimensionType& newWidth);
        DimensionType getLength() const;
        DimensionType getWidth() const;
        DimensionType getArea() const;
};

#endif