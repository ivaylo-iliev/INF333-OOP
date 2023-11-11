#pragma once
#include <utility>
#include <iostream>



class Matrix
{
private:
	

	int** values;
	int determinant;
	int rank;
	int rows;
	int columns;
	int max_number_length;

	void init_empty_matrix();
	void calculate_max_number_length();
	

public:
	Matrix();
	Matrix(int rows, int columns);
	~Matrix();

	void init_values(bool random);
	
	int get_column_count();
	int get_row_count();
	int** get_matrix_values();
	void set_values();
	void set_random_values(int maximum_value);
	void calculate_determinant();
	void calculate_rank();
	void calculate_properties();

	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
	friend std::istream& operator>>(std::istream& stream, Matrix& matrix);
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);
};

