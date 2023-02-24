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

	void find_intersection_points(Circle& c1, Circle& c2);
	
public:
	void execute();
	Task1();
	Task1(std::string header_value);
};

