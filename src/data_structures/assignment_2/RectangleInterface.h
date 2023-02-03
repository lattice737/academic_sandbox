#ifndef RECTANGLE_INTERFACE_
#define RECTANGLE_INTERFACE_

/** Rectangle Abstract Base Class
 @file  RectangleInterface.h
 @author  Nicholas Martinez */

 typedef double DimensionType;

class RectangleInterface {
    public:
        /** Updates the length and width of this Rectangle
         @param newLength  The new length of this Rectangle.
         @param newWidth   The new width of this Rectangle.
         @pre  New length and width must be greater than 0.0.
         @post  If both new values are positive, then this Rectangle's
            length and width are updated; otherwise, the length and
            width are unchanged.
         @return  True if length & width are changed; otherwise False. */
        virtual bool set(const DimensionType& newLength, const DimensionType& newWidth) = 0;
        
        /** Returns the length of this Rectangle
         @return  The length of this rectangle. */
        virtual DimensionType getLength() const = 0;

        /** Returns the width of this Rectangle
         @return  The width of this rectangle. */
        virtual DimensionType getWidth() const = 0;

        /** Returns the area of this Rectangle
         @return  The area of this rectangle. */
        virtual DimensionType getArea() const = 0;

        /** Destroys this Rectangle and frees its assigned memory. */
        virtual ~RectangleInterface() {}
};

#endif