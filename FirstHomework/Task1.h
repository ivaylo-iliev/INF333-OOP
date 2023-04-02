#pragma once
#include "Task.h"
#include "Circle.h"

class Task1 : public Task
{
private:
	Circle c1;
	Circle c2;
	
	void manual_items();
	void random_items();
	void read_from_file();
	void do_calculations();
public:
	void execute();
	Task1();
	Task1(std::string header_value);
	void calculate_circle_intersection_points();
	static double calculate_distance_between_circle_centers(Circle& c1, Circle& c2);
};

