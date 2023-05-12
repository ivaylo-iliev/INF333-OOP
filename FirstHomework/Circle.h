#pragma once
#include <iostream>
#include "Point.h"

class Circle
{
private:
	Point center;
	double radius;
public:
	Circle();
	Circle(Point, double);
	Circle(double, double, double);

	~Circle();

	void setCenter(double, double);
	void setCenter(Point);
	void setRadius(double);	
	const Point getCenter() const;
	const double getRadius() const;
	

	friend std::ostream& operator<<(std::ostream& stream, const Circle& circle);
	friend std::istream& operator>>(std::istream& stream, Circle& circle);
	friend Circle operator+(const Circle &c1, const Circle &c2);
	
};


