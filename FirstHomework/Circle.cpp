#include "Circle.h"
#include "Util.h"
#include <iomanip>

Circle::Circle()
{
	this->setCenter(0, 0);
	this->setRadius(0);

}

Circle::Circle(Point p, double radius)
{
	this->setCenter(p);
	this->setRadius(radius);

}

Circle::Circle(double x, double y, double radius)
{
	this->setCenter(x, y);
	this->setRadius(radius);
}

Circle::~Circle()
{
}

void Circle::setCenter(double x, double y)
{
	this->center.setX(x);
	this->center.setY(y);
}

void Circle::setCenter(Point center)
{	
	this->center = center;
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}

const Point Circle::getCenter() const
{
	return this->center;
}

const double Circle::getRadius() const
{
	return this->radius;
}

std::ostream& operator<<(std::ostream& stream, const Circle& circle)
{
	stream << "Center: " << circle.getCenter() << std::endl;
	stream << std::setprecision(5) << "Radius: " << circle.getRadius() << std::endl;
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

Circle operator+(const Circle& c1, const Circle& c2)
{
	double slope = Util::find_line_slope(c1.getCenter(), c2.getCenter());
	std::vector<Point> points;
	points.push_back(Util::calculate_circle_tol_line_intersect_pt(c1.getRadius(), c1.getCenter(), slope));
	points.push_back(Util::calculate_circle_tol_line_intersect_pt(-c1.getRadius(), c1.getCenter(), slope));
	points.push_back(Util::calculate_circle_tol_line_intersect_pt(c2.getRadius(), c2.getCenter(), slope));
	points.push_back(Util::calculate_circle_tol_line_intersect_pt(-c2.getRadius(), c2.getCenter(), slope));

	return Util::minimum_enclosing_circle(points);
}
