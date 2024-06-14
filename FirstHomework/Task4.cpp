
#define _USE_MATH_DEFINES

#include "Task4.h"
#include <cmath>
#include "Util.h"
#include "Point.h"

Task4::Task4(std::string header_value)
{
	this->initialize_menu(header_value);
}

void Task4::manual_items()
{
	std::cin >> line;
	std::cout << line;
	Point intersectionPoint = this->calculateIntersection();
	std::cout << "Abscissa intersection point before retoation is: " << intersectionPoint << std::endl;

	intersectionPoint = this->calculateIntersection();

	line = line * 90;
	std::cout << line;
	intersectionPoint = calculateIntersection();
	std::cout << "Abscissa intersection point is: " << intersectionPoint << std::endl;
}

void Task4::random_items()
{
	Point pt = Point(Util::random_double(0, 100), Util::random_double(0, 100));
	double angle = Util::random_double(0, 90);
	line = LineByPointAndAngle(pt, angle);

	std::cout << line;
	Point intersectionPoint = this->calculateIntersection();
	std::cout << "Abscissa intersection point before retoation is: " << intersectionPoint << std::endl;

	intersectionPoint = this->calculateIntersection();
	
	line = line * 90;
	std::cout << line;
	intersectionPoint = calculateIntersection();
	std::cout << "Abscissa intersection point is: " << intersectionPoint << std::endl;
}
 
Task4::~Task4()
{
}

Point Task4::calculateIntersection()
{
	Point pt = this->line.getPoint();
	double angle = this->line.getAngle();

	double slope = tan(angle * M_PI / 180);
	double y_intercept = pt.getY() - slope * pt.getX();
	double x_intercect = -y_intercept / slope;
	double y_intercect = 0;

	return Point(x_intercect, y_intercect);
}
