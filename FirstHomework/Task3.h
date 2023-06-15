#pragma once
#include "Task.h"
#include "Matrix.h"

class Task3 : public Task
{
private:
	

	Matrix matrix1, matrix2;
	void manual_items();
	void random_items();
	void do_calculations();

public:
	Task3(std::string header_value);
	~Task3();
};

