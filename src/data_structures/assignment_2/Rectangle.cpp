#include "Rectangle.h"

Rectangle::Rectangle() {
    length = 1.0;
    width = 1.0;
}

bool Rectangle::set(const DimensionType& newLength, const DimensionType& newWidth) {
    if (newLength < 0.0 || newWidth < 0.0)
        return false;
    length = newLength;
    width = newWidth;
    return true;
}

DimensionType Rectangle::getLength() const {
    return length;
}

DimensionType Rectangle::getWidth() const {
    return width;
}

DimensionType Rectangle::getArea() const {
    return length * width;
}