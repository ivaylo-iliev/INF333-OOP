#include "PointInSpace.h"
#include <iomanip>

PointInSpace::PointInSpace()
{
	this->setX(0);
	this->setY(0);
	this->setZ(0);
}

PointInSpace::PointInSpace(double x, double y, double z)
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
}

PointInSpace::~PointInSpace()
{
}

double PointInSpace::getZ() const
{
	return z;
}

void PointInSpace::setZ(double value)
{
	z = value;
}

PointInSpace PointInSpace::operator-()
{
	return PointInSpace(-this->getX(), -this->getY(), -this->getZ());
}

PointInSpace& PointInSpace::operator++()
{
	this->x += 1;
	this->y += 1;
	this->z += 1;
	return *this;
}

PointInSpace PointInSpace::operator++(int)
{
	PointInSpace temp = *this;
	++(*this);
	return temp;
}

std::ostream& operator<<(std::ostream& stream, const PointInSpace& point)
{
	stream << std::setprecision(5) << "x = " << point.getX() << ", y = " << point.getY() << ", z = " << point.getZ();
	return stream;
}

std::istream& operator>>(std::istream& stream, PointInSpace& point)
{
	std::cout << "Enter X coordinate: ";
	stream >> point.x;
	std::cout << "Enter Y coordinate: ";
	stream >> point.y;
	std::cout << "Enter Z coordinate: ";
	stream >> point.z;

	return stream;
}
