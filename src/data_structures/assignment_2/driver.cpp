// Programmer:      Nicholas Martinez
// Project number:  2
// Project Desc:    Rectangle class with abstract base class
// Course:          COSC 2436 PF III Data Structures
// Date:            2/2/23

#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    const double DEFAULT_CASE=1.0,
                 VALID_CASE=16.0,
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
            cout << "\nIf a negative length is set:" << endl;
            break;
            case BadWidth:
            updated = myRectangle.set(VALID_VALUE, -static_cast<double>(BadWidth));
            cout << "\nIf length negative width is set:" << endl;
            break;
            case ValidDimensions:
            updated = myRectangle.set(VALID_VALUE, VALID_VALUE);
            cout << "\nIf a valid length and width are set:" << endl;
            break;
            default:
            allOnes = myRectangle.getLength() == myRectangle.getWidth() == myRectangle.getArea() == DEFAULT_CASE;
            cout << "The default rectangle has length, width, and area equal to 1.0: " << (allOnes ? "True" : "False") << endl;
            continue;
        }
        validProduct = myRectangle.getArea() == VALID_CASE;
        cout << "1) Length and width have been updated: " << (updated ? "True" : "False") << endl
             << "2) Area is the product of new length & new width: " << (validProduct ? "True" : "False") << endl;
    }

    return 0;
}