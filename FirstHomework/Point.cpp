#include "Point.h"
#include <iomanip>

Point::Point()
	:x(0), y(0)
{
	
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::~Point(){}

void Point::setX(double value)
{
	this->x = value;
}

const double Point::getX() const
{
	return this->x;
}

void Point::setY(double value) {
	this->y = value;
}

const double Point::getY() const
{
	return this->y;
}

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
	stream << std::setprecision(5) << "x = " << point.getX() << ", y = " << point.getY();
	return stream;
}

std::istream& operator>>(std::istream& stream, Point& point)
{
	std::cout << "Enter X coordinate: ";
	stream >> point.x;
	std::cout << "Enter Y coordinate: ";
	stream >> point.y;
	
	return stream;
}