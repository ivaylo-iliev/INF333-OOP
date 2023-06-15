#include "Task2.h"
#include "Matrix.h"
#include <iostream>

void Task2::manual_items()
{
	matrix1.init_values(false);
	matrix2.init_values(false);
	do_calculations();
}

void Task2::random_items()
{
	matrix1 = Matrix(2, 2);
	matrix1.init_values(true);

	matrix2 = Matrix(2, 2);
	matrix2.init_values(true);
	
	do_calculations();
	
}

void Task2::do_calculations()
{
	std::cout << matrix1;
	std::cout << matrix2;

	Matrix sum_matrix = matrix1 + matrix2;
	std::cout << sum_matrix;	
}

Task2::Task2(std::string header_value)
{
	this->initialize_menu(header_value);
}

Task2::~Task2()
{

}

