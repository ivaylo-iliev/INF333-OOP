#include "Force.h"

Force::Force()
{
	applicationPoint = Point(0,0);
	direction = 0;
	magnitude = 0;
}

Force::Force(double x, double y, double direction, double magnitude) 
{
	this->setApplicationPoint(Point(x, y));
	this->setDirection(direction);
	this->setMagnitude(magnitude);
}

Force::Force(Point point, double direction, double magnitude)
{
	this->setApplicationPoint(point);
	this->setDirection(direction);
	this->setMagnitude(magnitude);
}

Force::~Force()
{
}

void Force::setApplicationPoint(Point value)
{
	this->applicationPoint = value;
}

void Force::setApplicationPoint(double x, double y)
{
	this->applicationPoint = Point(x, y);
}

Point Force::getApplicationPoint()
{
	return this->applicationPoint;
}

void Force::setDirection(double value)
{
	this->direction = value;
}

double Force::getDirection()
{
	return this->direction;
}

void Force::setMagnitude(double value)
{
	this->magnitude = value;
}

double Force::getMagnitude()
{
	return this->magnitude;
}

std::ostream& operator<<(std::ostream& stream, const Force& force)
{
	stream << force.applicationPoint << ", direction: " << force.direction << ", magnitude: " << force.magnitude << std::endl;
}

std::istream& operator>>(std::istream& stream, Force& force)
{
	stream >> force.applicationPoint;
	std::cout << "Enter direction: ";
	stream >> force.direction;
	std::cout << "Enter magnitude: ";
	stream >> force.magnitude;

	return stream
}
