/** @file Circle.h */

#ifndef CIRCLE_
#define CIRCLE_

class Circle
{
public:
	Circle();
	void setRadius(double newRadius);
	double getRadius() const;
	double getArea() const;
private:
	double radius;
};
#endif