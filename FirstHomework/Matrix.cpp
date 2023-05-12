#include "Matrix.h"
#include "Util.h"
#include <iomanip>

void Matrix::init_empty_matrix()
{
	this->values = new int* [rows];
	for (int i = 0; i < columns; i++)
	{
		this->values[i] = new int[columns];
	}
}

Matrix::Matrix()
{
	rows = 2;
	columns = 2;
	init_empty_matrix();
	
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
		for (int row_iterator = 0; row_iterator < rows; row_iterator++)
		{
			for (int col_iterator = 0; col_iterator < columns; col_iterator++)
			{
				values[row_iterator][col_iterator] = Util::random_int(1, 100);
				determinant = calculate_determinant();
			}
		}
	}
	else 
	{

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

int Matrix::calculate_determinant()
{
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
	
	return first_diagonal - second_diagnoal;	
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix)
{
	stream << std::endl << "Matrix: " << std::endl;
	for (int row_iterator = 0; row_iterator < matrix.rows; row_iterator++)
	{
		stream << std::setw(2) << std::setfill(' ') << '|';
		for (int col_iterator = 0; col_iterator < matrix.columns; col_iterator++)
		{
			stream << std::setw(4) << matrix.values[row_iterator][col_iterator];
		}
		stream << std::setw(2) << '|' << std::endl;
	}

	stream << std::endl << "Determinant: " << matrix.determinant << std::endl;

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
		}
	}

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
	result.determinant = result.calculate_determinant();
	return result;
}
