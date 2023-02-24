#pragma once
#include <iostream>
#include <vector>
#include "Circle.h"

class Util
{
public:
	static bool choice_is_valid(int choice);
	static std::vector<std::string> read_task_definitions();
	static void calculate_circle_intersection_points(Circle& c1, Circle& c2, double& d);
	static double calculate_distance_between_circle_centers(Circle& c1, Circle& c2);
};

