#define _USE_MATH_DEFINES

#include "LineByPointAndAngle.h"
#include <cmath>
#include <iomanip>
#include "Util.h"

LineByPointAndAngle::LineByPointAndAngle()
{
	this->setPoint(0, 0);
	this->angle = 0;
}

LineByPointAndAngle::LineByPointAndAngle(Point pt, double angle)
{
	this->setPoint(pt);
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

LineByPointAndAngle operator*(const LineByPointAndAngle& line, double rotationAngle)
{
	double rotationAngleInRadians = Util::degrees_to_radians(rotationAngle);
	double originalAngleInRadians = Util::degrees_to_radians(line.angle);

	double newAngleInRadians = originalAngleInRadians + rotationAngleInRadians;

	double newAngleInDegrees = Util::radians_to_degrees(newAngleInRadians);
	return LineByPointAndAngle(line.pt, newAngleInDegrees);
}

std::ostream& operator<<(std::ostream& stream, const LineByPointAndAngle& line)
{
	stream << line.pt << std::endl;
	stream << "Angle with the abscissa : "  << std::setprecision(5) <<  line.angle << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, LineByPointAndAngle& line)
{
	std::cout << "Enter a point trough the line passes: " << std::endl;
	stream >> line.pt;
	std::cout << "Enter the angle with the abscissa: ";
	stream >> line.angle;

	return stream;
}
