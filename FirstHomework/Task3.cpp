#include "Task3.h"
#include <vector>

void Task3::manual_items()
{
	std::cin >> matrix1;
	std::cin >> matrix2;
}

void Task3::random_items()
{
	matrix1 = Matrix(2, 3);
	matrix1.init_values(true);

	matrix2 = Matrix(2, 3);
	matrix2.init_values(true);

	do_calculations();
}

void Task3::do_calculations()
{
	std::cout << matrix1;
	std::cout << matrix2;

	std::cout << std::endl << "The sum of the matrices is:" << std::endl;
	Matrix sum_matrix = matrix1 + matrix2;
	std::cout << sum_matrix;
}



Task3::Task3(std::string header_value)
{
	this->initialize_menu(header_value);
}

Task3::~Task3()
{
}
