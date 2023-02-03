#include "Rectangle.h"

Rectangle::Rectangle() {
    length = 1.0;
    width = 1.0;
}

bool Rectangle::set(const double newLength, const double newWidth) {
    if (newLength < 0.0 || newWidth < 0.0)
        return false;
    length = newLength;
    width = newWidth;
    return true;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getArea() const {
    return length * width;
}