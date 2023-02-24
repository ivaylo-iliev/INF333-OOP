#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>

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

double Util::calculate_distance_between_circle_centers(Circle& c1, Circle& c2)
{
	Point center1 = c1.getCenter();
	Point center2 = c2.getCenter();

	double x2x1 = std::pow((center2.getX() - center1.getX()), 2);
	double y2y1 = std::pow((center2.getY() - center1.getY()), 2);
	double distance = std::sqrt(x2x1 + y2y1);

	return distance;
}

void Util::calculate_circle_intersection_points(Circle& c1, Circle& c2, double& d)
{
	int x1 = c1.getCenter().getX();
	int y1 = c1.getCenter().getY();
	int r1 = c1.getRadius();

	int x2 = c2.getCenter().getX();
	int y2 = c2.getCenter().getY();
	int r2 = c2.getRadius();

	// Calculate distance. See documentation for details about next calculations
	double d = calculate_distance_between_circle_centers(c1, c2);

	double a = (pow(r1, 2) - pow(r2, 2) + pow(d, 2)) / 2 * d;
	double b = (pow(r2, 2) - pow(r1, 2) + pow(d, 2)) / 2 * d;
	double h = sqrt(pow(r1, 2) - pow(a, 2));

	// Calculate P5
	int x5 = x1 + (a / d) * (x2 - x1);
	int y5 = y1 + (a / d) * (y2 - y1);
	

	// Calculate intersection points P3 and P4
	Point P3;
	P3.setX(x5 - ((h * (y2 - y1)) / d));
	P3.setY(y5 + ((h * (x2 - x1)) / d));

	Point P4;
	P4.setX(x5 + ((h * (y2 - y1)) / d));
	P4.setY(y5 - ((h * (x2 - x1)) / d));

	if (d == r1 + r2) {
		std::cout << P3 << std::endl;
		return;
	}

	std::cout << "The intersection points are:" << std::endl;
	std::cout << P3 << std::endl;
	std::cout << P4 << std::endl;
}
