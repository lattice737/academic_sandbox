// Programmer:      Nicholas Martinez
// Project number:  2
// Project Desc:    Rectangle class with abstract base class
// Course:          COSC 2436 PF III Data Structures
// Date:            2/2/23

#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    const double DEFAULT_AREA=1.0,
                 BAD_LENGTH_AREA=-4.0,
                 BAD_WIDTH_AREA=-8.0,
                 VALID_AREA=16.0,
                 VALID_VALUE=4.0;
    enum Case {BadLength=1, BadWidth, ValidDimensions};
    bool allOnes,
         updated,
         validProduct;
    Rectangle myRectangle;

    for (int i=0; i<4; i++) {
        switch (i) {
            case BadLength:
            updated = myRectangle.set(-static_cast<double>(BadLength), VALID_VALUE);
            validProduct = myRectangle.getArea() == BAD_LENGTH_AREA;
            cout << "\nIf a negative length is set:" << endl;
            break;
            case BadWidth:
            updated = myRectangle.set(VALID_VALUE, -static_cast<double>(BadWidth));
            validProduct = myRectangle.getArea() == BAD_WIDTH_AREA;
            cout << "\nIf length negative width is set:" << endl;
            break;
            case ValidDimensions:
            updated = myRectangle.set(VALID_VALUE, VALID_VALUE);
            validProduct = myRectangle.getArea() == VALID_AREA;
            cout << "\nIf a valid length and width are set:" << endl;
            break;
            default:
            allOnes = myRectangle.getLength() == myRectangle.getWidth() == myRectangle.getArea() == DEFAULT_AREA;
            cout << "The default rectangle has length, width, and area equal to 1.0: " << (allOnes ? "True" : "False") << endl;
            continue;
        }
        cout << "1) Length and width have been updated: " << (updated ? "True" : "False") << endl
             << "2) Area is the product of new length & new width: " << (validProduct ? "True" : "False") << endl;
    }

    return 0;
}