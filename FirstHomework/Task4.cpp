

#include "Task4.h"
#include <cmath>
#include "Util.h"
#include "Point.h"

Task4::Task4(std::string header_value)
{
	this->angle = 0;
	this->initialize_menu(header_value);
}

void Task4::manual_items()
{
}

void Task4::random_items()
{
	Point pt = Point(Util::random_double(0, 100), Util::random_double(0, 100));
	double angle = Util::random_double(0, 360);
	this->line = LineByPointAndAngle(pt, angle);

	//Point intersectionPoint = this->calculateIntersection();
}

Task4::~Task4()
{
}

Point Task4::rotateLine(Point p, double rotationAngleInDegrees)
{
	// Convert the rotation angle from degrees to radians
	double rotationAngleInRadians = rotationAngleInDegrees * M_PI / 180.0;

	// Rotate the point coordinates
	double x = p.getX() * cos(rotationAngleInRadians) - p.getY() * sin(rotationAngleInRadians);
	double y = p.getX() * sin(rotationAngleInRadians) + p.getY() * cos(rotationAngleInRadians);

	// Return the rotated point
	return Point(x, y);
}
