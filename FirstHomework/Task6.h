#pragma once
#include "Task.h"
#include "PointInSpace.h"
class Task6 : public Task
{
private:
	PointInSpace point;
public:
	Task6(std::string header_value);
	~Task6();
	void manual_items();
	void random_items();

	double calculate_distance_to_start();
	PointInSpace operator-();
};

