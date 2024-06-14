#define _USE_MATH_DEFINES

#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>


bool Util::choice_is_valid(int choice)
{
	return (choice > 0 && choice < 26) ? true : false;
}

std::vector<std::string> Util::read_task_definitions()
{
	std::vector<std::string> task_definitions;
	std::fstream data_file;
	data_file.open("TaskDefinitions.txt", std::ios::in);
	std::string line;

	if (data_file.is_open()) {
		while (std::getline(data_file, line))
		{
			task_definitions.push_back(line);
		}
		data_file.close();
	}

	return task_definitions;
}

int Util::random_int(int low, int high)
{
	static std::default_random_engine re{};
	using distribution = std::uniform_int_distribution<int>;
	static distribution uid{};
	return uid(re, distribution::param_type{ low, high });
}

double Util::random_double(double low, double high)
{
	static std::default_random_engine re{};
	using distribution = std::uniform_real_distribution<double>;
	static distribution uid{};
	return uid(re, distribution::param_type{ low, high });
}

double Util::find_line_slope(Point p1, Point p2)
{
	if (p2.getX() - p1.getX() != 0)
	{
		double raise = p2.getY() - p1.getY();
		double run = p2.getX() - p1.getX();
		double rise_over_run = raise / run;
		return std::atan(rise_over_run);
	}

	return INT_MAX;
}

double Util::find_line_slope_in_degrees(Point p1, Point p2)
{
	double slope_in_radians = Util::find_line_slope(p1, p2);
	return Util::find_line_slope_in_degrees(slope_in_radians);
}

double Util::find_line_slope_in_degrees(double slope_in_radians)
{
	return Util::radians_to_degrees(std::atan(slope_in_radians));
}

double Util::radians_to_degrees(double radians)
{
	return radians * (180 / M_PI);
}

Point Util::calculate_circle_tol_line_intersect_pt(double radius, Point center, double slope_in_radians)
{
	
	double x = radius * std::cos(slope_in_radians) + center.getX();
	double y = radius * std::sin(slope_in_radians) + center.getY();

	return Point(x, y);
}

// Helper method to get a circle defined by 3 points
Point Util::get_circle_center(double x1, double y1, double x2, double y2)
{
	double A = std::pow(x1, 2) + std::pow(y1, 2);
	double B = std::pow(x2, 2) + std::pow(y2, 2);
	double C = x1 * y1 - y2 * x1;
	double x_result = (y2 * A - y1 * B) / (2 * C);
	double y_result = (x1 * B - x2 * A) / (2 * C);

	return Point(x_result, y_result);
}

// Function to return the euclidean distance between two points
double Util::euclidean_distance(const Point& point1, const Point& point2)
{
	double A = std::pow(point1.getX() - point2.getX(), 2);
	double B = std::pow(point1.getY() - point2.getY(), 2);

	return std::sqrt( A + B);
}

// Function to return the smallest circle that intersects 2 points
Circle Util::circle_from(const Point& point1, const Point& point2)
{
	// Set the center to be the midpoint of point1 and point2
	double x_center = (point1.getX() + point2.getX()) / 2.0;
	double y_center = (point1.getY() + point2.getY()) / 2.0;
	Point center(x_center, y_center);

	// Set the radius to be half the distance between the two points
	double radius = euclidean_distance(point1, point2) / 2.0;
	return Circle(center, radius);
}

// Function to return a unique circle that intersects three points
Circle Util::circle_from(const Point& point1, const Point& point2, const Point& point3)
{
	Point center = get_circle_center(point2.getX() - point1.getX(), point2.getY() - point1.getY(), point3.getX() - point1.getX(), point3.getY() - point1.getY());
	double x_center = center.getX() + point1.getX();
	double y_center = center.getY() + point1.getY();

	center.setX(x_center);
	center.setY(y_center);

	return Circle(center, euclidean_distance(center, point1));
}

Circle Util::minimum_enclosing_circle(const std::vector<Point>& points)
{
	// Find the number of points
	int point_count = (int)points.size();

	if (point_count == 0)
		return { { 0, 0 }, 0 };
	if (point_count == 1)
		return Circle(points[0], 0);

	// Initialize a circle with center 0,0 and radius INT_MAX
	Circle result(Point(0, 0), INT_MAX);

	// Go over all pair of points
	for (int i = 0; i < point_count; i++) {
		for (int j = i + 1; j < point_count; j++) {
			// Get the smallest circle that intersects P[i] and P[j]
			Circle temp = circle_from(points[i], points[j]);

			// Update the result if the circle encloses all points and has a smaller radius
			if (temp.getRadius() < result.getRadius() && is_valid_circle(temp, points))
			{
				result = temp;
			}
		}
	}

	// Go over all triples of points

	for (int i = 0; i < point_count; i++)
	{
		for (int j = i + 1; j < point_count; j++)
		{
			for (int k = j + 1; k < point_count; k++)
			{
				// Get the circle that intersects all three points
				Circle temp = circle_from(points[i], points[j], points[k]);

				// Update the result if the circle encloses all points and has a smaller radius
				if (temp.getRadius() < result.getRadius() && is_valid_circle(temp, points))
				{
					result = temp;
				}
			}
		}
	}


	return result;
}

bool Util::is_valid_circle(const Circle& circle, const std::vector<Point>& points)
{
	for (const Point& point : points)
	{
		if (!point_inside_circle(circle, point))
		{
			return false;
		}
	}

	return true;
}

bool Util::point_inside_circle(const Circle& circle, const Point& point)
{
	// Due to issue in calculation with double values caused by high percision cast to int
	return (int) euclidean_distance(circle.getCenter(), point) <= (int) circle.getRadius();
	//return euclidean_distance(circle.getCenter(), point) <= circle.getRadius();
}

double Util::degrees_to_radians(double degrees) {
	return degrees * M_PI / 180.0;
}
