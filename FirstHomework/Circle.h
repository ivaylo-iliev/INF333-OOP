#pragma once
#include <iostream>
#include "Point.h"

class Circle
{
private:
	Point center;
	int radius;
public:
	Circle();
	Circle(Point, int);
	Circle(int, int, int);

	~Circle();

	void setCenter(int, int);
	void setCenter(Point);
	void setRadius(int);	
	const Point getCenter() const;
	const int getRadius() const;
	

	friend std::ostream& operator<<(std::ostream& stream, const Circle& circle);
	friend std::istream& operator>>(std::istream& stream, Circle& circle);
	
};


