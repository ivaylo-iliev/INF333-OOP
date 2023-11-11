#define _USE_MATH_DEFINES

#include "LineByPointAndAngle.h"
#include <cmath>

LineByPointAndAngle::LineByPointAndAngle()
{
	this->setPoint(0, 0);
	this->angle = 0;
}

LineByPointAndAngle::LineByPointAndAngle(Point pt, double angle)
{
	this->setPoint(0, 0);
	this->setAngle(angle);
}

LineByPointAndAngle::~LineByPointAndAngle()
{
}

void LineByPointAndAngle::setPoint(Point pt)
{
	this->pt = pt;
}

void LineByPointAndAngle::setPoint(double x, double y)
{
	this->pt.setX(x);
	this->pt.setY(y);
}

void LineByPointAndAngle::setAngle(double angle)
{
	this->angle = angle;
}

Point LineByPointAndAngle::getPoint()
{
	return this->pt;
}

double LineByPointAndAngle::getAngle()
{
	return this->angle;
}

Point LineByPointAndAngle::calculateIntersectionWithOrdinate()
{
	// Convert angle to radians
	double angleInRadians = this->angle * M_PI / 180.0;

	// Calculate intersection point coordinates
	double x = this->pt.getX() + cos(angleInRadians);
	double y = this->pt.getY() + sin(angleInRadians);

	return Point(x, y);
}

LineByPointAndAngle LineByPointAndAngle::rotateLine(Point p, double rotationAngleInDegrees)
{
	// Convert the rotation angle from degrees to radians
	double rotationAngleInRadians = rotationAngleInDegrees * M_PI / 180.0;

	// Rotate the point coordinates
	double x = p.getX() * cos(rotationAngleInRadians) - p.getY() * sin(rotationAngleInRadians);
	double y = p.getX() * sin(rotationAngleInRadians) + p.getY() * cos(rotationAngleInRadians);

	// Return the rotated point
	return LineByPointAndAngle(Point(x, y), rotationAngleInDegrees);
}

LineByPointAndAngle LineByPointAndAngle::operator*(double rotationAngle)
{
	return this->rotateLine(this->pt, rotationAngle);
}
