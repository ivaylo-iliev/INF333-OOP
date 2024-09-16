#pragma once
#include "Task.h"
#include "Point.h"

class Task7 : public Task
{
private:
	Point point;

public:
	Task7(std::string header_value);
	~Task7();
	void manual_items();
	void random_items();

	double calculate_distance_to_start();
};

