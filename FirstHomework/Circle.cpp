#include "Circle.h"
#include "Util.h"

Circle::Circle()
{
	this->setCenter(0, 0);
	this->setRadius(0);

}

Circle::Circle(Point p, int radius)
{
	this->setCenter(p);
	this->setRadius(radius);

}

Circle::Circle(int x, int y, int radius)
{
	this->setCenter(x, y);
	this->setRadius(radius);
}

Circle::~Circle()
{
}

void Circle::setCenter(int x, int y)
{
	this->center.setX(x);
	this->center.setY(y);
}

void Circle::setCenter(Point center)
{	
	this->center = center;
}

void Circle::setRadius(int radius)
{
	this->radius = radius;
}

const Point Circle::getCenter() const
{
	return this->center;
}

const int Circle::getRadius() const
{
	return this->radius;
}

std::ostream& operator<<(std::ostream& stream, const Circle& circle)
{
	stream << "Center: " << circle.getCenter() << std::endl;
	stream << "Radius: " << circle.getRadius() << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Circle& circle)
{
	std::cout << "Enter center point coordinates: " << std::endl;
	stream >> circle.center;
	std::cout << "Enter circle radius: ";
	stream >> circle.radius;

	return stream;
}
