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

Circle operator+(Circle& c1, Circle& c2)
{
	double distance = Util::calculate_distance_between_circle_centers(c1, c2);

	if (distance > (c1.getRadius() + c2.getRadius()))
	{
		std::cout << "The circles are too far apart and do not intersect." << std::endl;
		return;
	}

	if (distance < (c1.getRadius() + c2.getRadius()))
	{
		std::cout << "One circle is inside the other and do not intersect." << std::endl;
		return;
	}

	if (distance == 0 && c1.getRadius() == c2.getRadius())
	{
		std::cout << "The circles are merged and the smallest encompassing circle is." << std::endl;
		std::cout << c1 << std::endl;
		return c1;
	}

	if (distance == c1.getRadius() + c2.getRadius())
	{
		std::cout << "The circles touch and there is a single intersection point." << std::endl;
		Util::calculate_circle_intersection_points(c1, c2, distance);
		return;
	}

	if (distance < c1.getRadius() + c2.getRadius())
	{
		std::cout << "There are two intersection points." << std::endl;
		Util::calculate_circle_intersection_points(c1, c2, distance);
		return;
	}

}
