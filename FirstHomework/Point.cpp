#include "Point.h"

Point::Point()
	:x(0), y(0)
{
	
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::~Point(){}

void Point::setX(int value)
{
	this->x = value;
}

const int Point::getX() const
{
	return this->x;
}

void Point::setY(int value) {
	this->y = value;
}

const int Point::getY() const
{
	return this->y;
}

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
	stream << point.getX() << ", " << point.getY();
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