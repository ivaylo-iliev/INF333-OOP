#pragma once
#include "Task.h"
#include "Matrix.h"

static const double EPS = 1E-9;

class Task3 : public Task
{
private:
	Matrix matrix1, matrix2;
	void manual_items();
	void random_items();
	void gaussianElimination(Matrix& matrix);
	int calculate_rank(Matrix& matrix);
	void do_calculations();

public:
	Task3(std::string header_value);
	~Task3();
};

