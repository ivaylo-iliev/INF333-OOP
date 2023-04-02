#define _USE_MATH_DEFINES

#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


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
			std::cout << line << std::endl;
			task_definitions.push_back(line);
		}
		data_file.close();
	}

	return task_definitions;
}

int Util::random_int(int offset, int range, int seed)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr) + seed));
	return offset + (rand() % range);
}

double Util::find_line_slope(Point p1, Point p2)
{
	if (p2.getX() - p1.getX() != 0)
	{
		double rise_over_run = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
		return std::atan(rise_over_run);
	}

	return INT_MAX;
}

double Util::find_line_slope_in_degrees(Point p1, Point p2)
{
	double slope_in_percents = Util::find_line_slope(p1, p2);
	return Util::find_line_slope_in_degrees(slope_in_percents);
}

double Util::find_line_slope_in_degrees(double slope_in_percents)
{
	return Util::radians_to_degrees(std::atan(slope_in_percents));
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
	double B = std::pow(x1, 2) + std::pow(y1, 2);
	double C = std::pow(x2, 2) + std::pow(y2, 2);
	double D = x1 * y1 - y2 * x1;
	double x_result = (y2 * B - y1 * C) / (2 * D);
	double y_result = (x1 * C - x2 * B) / (2 * D);

	return Point(x_result, y_result);
}

// Function to return the euclidean distance between two points
double Util::euclidean_distance(const Point& point1, const Point& point2)
{
	return std::ceil(std::sqrt(std::pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2)));
}

// Function to return the smallest circle that intersects 2 points
Circle Util::circle_from(const Point& point1, const Point& point2)
{
	// Set the center to be the midpoint of point1 and point2
	Point result_center = { (point1.getX() + point2.getX()) / 2.0, (point1.getY() + point2.getY()) / 2.0};

	// Set the radius to be half the distance between the two points
	return Circle( result_center, euclidean_distance(point1, point2) / 2.0 );
}

// Function to return a unique circle that intersects three points
Circle Util::circle_from(const Point& point1, const Point& point2, const Point& point3)
{
	Point temp_center = get_circle_center(point2.getX() - point1.getX(), point2.getY() - point1.getY(), point3.getX() - point1.getX(), point3.getY() - point1.getY());
	double center_x = temp_center.getX() + point1.getX();
	double center_y = temp_center.getY() + point1.getY();

	temp_center.setX(center_x);
	temp_center.setY(center_y);

	return Circle(temp_center, euclidean_distance(temp_center, point1));
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
				// Get the circle that intersects P[i], P[j], P[k]
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
	return euclidean_distance(circle.getCenter(), point) <= circle.getRadius();
}


