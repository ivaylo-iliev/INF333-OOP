#include "Matrix.h"
#include "Util.h"
#include <iomanip>
#include <string>

void Matrix::init_empty_matrix()
{
	this->values = new int* [rows];
	for (int i = 0; i < columns; i++)
	{
		this->values[i] = new int[columns];
	}
}

void Matrix::calculate_rank()
{
	
}

void Matrix::calculate_properties()
{
	this->calculate_determinant();
	this->calculate_max_number_length();
}


Matrix::Matrix()
{
	this->rows = 2;
	this->columns = 2;
	this->init_empty_matrix();
	
}

Matrix::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;	
	init_empty_matrix();
}

Matrix::~Matrix(){}

void Matrix::init_values(bool random)
{
	if (random) 
	{
		this->set_random_values(100);
	}
	else 
	{
		this->set_values();
	}
	
}

int Matrix::get_column_count()
{
	return this->columns;
}

int Matrix::get_row_count()
{
	return this->rows;
}

int** Matrix::get_matrix_values()
{
	return this->values;
}

void Matrix::set_values()
{
	Matrix initMatrix(rows, columns);
	std::cin >> initMatrix;
	this->values = initMatrix.values;
	this->calculate_properties();
	
}

void Matrix::set_random_values(int maximum_value)
{
	for (int row_iterator = 0; row_iterator < rows; row_iterator++)
	{
		for (int col_iterator = 0; col_iterator < columns; col_iterator++)
		{
			values[row_iterator][col_iterator] = Util::random_int(0, maximum_value);
			calculate_properties();
		}
	}
}

void Matrix::calculate_determinant()
{
	if (rows != columns)
	{
		// Non-square matrices do not have determinants.
		this->determinant = NULL;
		return;
	}

	int col_iterator = 0;
	int first_diagonal = 1;
	for (int row_iterator = 0; row_iterator < rows; row_iterator++)
	{
		first_diagonal = first_diagonal * values[row_iterator][col_iterator];
		
		if (col_iterator < columns) {
			col_iterator++;
		}
	}

	col_iterator = 0;
	int second_diagnoal = 1;	
	for (int row_iterator = rows -1; row_iterator >= 0; row_iterator--)
	{
		second_diagnoal = second_diagnoal * values[row_iterator][col_iterator];
		if (col_iterator < columns) {
			col_iterator++;
		}
	}
	
	this->determinant = first_diagonal - second_diagnoal;	
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix)
{
	stream << "Matrix: " << std::endl;

	for (int row_iterator = 0; row_iterator < matrix.rows; row_iterator++)
	{
		stream << std::setw(2) << std::setfill(' ') << '|';
		for (int col_iterator = 0; col_iterator < matrix.columns; col_iterator++)
		{
			stream << std::setw(matrix.max_number_length) << matrix.values[row_iterator][col_iterator];
		}
		stream << std::setw(2) << '|' << std::endl;
	}

	if (matrix.determinant != NULL)
	{
		stream << std::endl << "Determinant: " << matrix.determinant << std::endl;
	}

	return stream;
}

std::istream& operator>>(std::istream& stream, Matrix& matrix)
{
	std::cout << "Enter values for the matrix." << std::endl;
	for (int i = 0; i < matrix.get_row_count(); i++)
	{
		for (int j = 0; j < matrix.get_column_count(); j++)
		{
			std::cout << "element[" << i + 1 << "][" << j + 1 << "] = ";
			stream >> matrix.values[i][j];
			std::cout << matrix.values[i][j] << std::endl;
		}
	}

	std::cout << matrix << std::endl;
	matrix.calculate_properties();

	return stream;
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	int rows = m1.rows;
	int columns = m1.columns;
	
	Matrix result(rows, columns);

	for (int row_iterator = 0; row_iterator < rows; row_iterator++) 
	{
		for (int col_iterator = 0; col_iterator < columns; col_iterator++)
		{
			result.values[row_iterator][col_iterator] = m1.values[row_iterator][col_iterator] + m2.values[row_iterator][col_iterator];
		}
	}

	result.calculate_properties();
	return result;
}

void Matrix::calculate_max_number_length()
{
	int length = 1;
	for (int row_iterator = 0; row_iterator < rows; row_iterator++)
	{
		for (int col_iterator = 0; col_iterator < columns; col_iterator++)
		{
			int val_size = std::to_string(values[row_iterator][col_iterator]).size();

			if (val_size > length)
			{
				length = val_size;
			}
		}
	}
	max_number_length = length + 1;
}