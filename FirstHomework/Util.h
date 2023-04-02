#pragma once
#include <iostream>
#include <vector>
#include "Circle.h"

class Util
{
public:
	static bool choice_is_valid(int choice);
	static std::vector<std::string> read_task_definitions();

	/*
	 * offset - The starting point for the range of random numbers
	 * range - The number of values between first and the last possible random number including the limits
	 * seed - additional value to modify the seed to get more random values on consequtive calls
	 */
	static int random_int(int offset, int range, int seed);

	static double find_line_slope(Point p1, Point p2);
	static double find_line_slope_in_degrees(Point p1, Point p2);
	static double find_line_slope_in_degrees(double slope_in_radians);
	static double radians_to_degrees(double radians);
	static Point calculate_circle_tol_line_intersect_pt(double radius, Point center, double slope_in_degrees);
	static Circle minimum_enclosing_circle(const std::vector<Point>& points);
	static Circle circle_from(const Point& point1, const Point& point2, const Point& point3);
	static Point get_circle_center(double x1, double y1, double x2, double y2);
	static Circle circle_from(const Point& point1, const Point& point2);
	static double euclidean_distance(const Point& point1, const Point& point2);
	static bool is_valid_circle(const Circle& circle, const std::vector<Point>& points);
	static bool point_inside_circle(const Circle& circle, const Point& point);
};

