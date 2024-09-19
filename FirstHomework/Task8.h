#pragma once
#include "Task.h"
#include "Point.h"
class Task8 : public Task
{
private:
	Point point;

public:
	Task8(std::string header_value);
	~Task8();
	void manual_items();
	void random_items();
};

