#pragma once
#include <utility>
#include <iostream>

class Matrix
{
private:
	int** values;
	int determinant;
	int rows;
	int columns;

	void init_empty_matrix();

public:
	Matrix();
	Matrix(int rows, int columns);
	~Matrix();

	void init_values(bool random);
	
	int get_column_count();
	int get_row_count();
	int** get_matrix_values();
	int calculate_determinant();

	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
	friend std::istream& operator>>(std::istream& stream, Matrix& matrix);
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);
};

