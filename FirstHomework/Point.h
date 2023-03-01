#pragma once
#include <iostream>

class Point
{
	double x;
	double y;
public:
	Point();
	Point(double, double);
	~Point();

	void setX(double);
	void setY(double);
	const double getX() const;
	const double getY() const;

	friend std::ostream& operator<<(std::ostream& stream, const Point& point);
	friend std::istream& operator>>(std::istream& stream, Point& point);
};


