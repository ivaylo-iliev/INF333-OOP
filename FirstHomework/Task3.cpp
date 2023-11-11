#include "Task3.h"
#include <vector>

void Task3::manual_items()
{
	matrix1 = Matrix(2, 3);
	std::cin >> matrix1;
	std::cout << matrix1;
	matrix2 = Matrix(2, 3);
	std::cin >> matrix2;
	do_calculations();
}

void Task3::random_items()
{
	matrix1 = Matrix(2, 3);
	matrix1.init_values(true);

	matrix2 = Matrix(2, 3);
	matrix2.init_values(true);

	do_calculations();
}


void Task3::gaussianElimination(Matrix& matrix) {
	int n = matrix.get_row_count();
	int m = matrix.get_column_count();
	int** matrix_values = matrix.get_matrix_values();

	for (int i = 0; i < n; i++) {
		// Find pivot row
		int maxRow = i;
		for (int j = i + 1; j < n; j++) {
			
			if (abs(matrix_values[j][i]) > abs(matrix_values[maxRow][i])) {
				maxRow = j;
			}
		}

		// Swap rows
		std::swap(matrix_values[i], matrix_values[maxRow]);

		// Check if matrix is singular
		if (matrix_values[i][i] == 0) {
			return;
		}

		// Normalize pivot row
		for (int j = i + 1; j < n; j++) {
			int ratio = matrix_values[j][i] / matrix_values[i][i];
			for (int k = i; k < m; k++) {
				matrix_values[j][k] -= ratio * matrix_values[i][k];
			}
		}
	}
}


int Task3::calculate_rank(Matrix& matrix)
{
	gaussianElimination(matrix);
	int rank = 0;
	for (int i = 0; i < matrix.get_row_count(); i++) {
		bool isZeroRow = true;
		for (int j = 0; j < matrix.get_column_count(); j++) {
			if (matrix.get_matrix_values()[i][j] != 0) {
				isZeroRow = false;
				break;
			}
		}
		if (!isZeroRow) {
			rank++;
		}
	}
	return rank;
}

void Task3::do_calculations()
{
	std::cout << matrix1;
	if (matrix1.get_row_count() != matrix1.get_column_count()) {
		std::cout << "Rank: " << calculate_rank(matrix1) << std::endl;
	}
	
	std::cout << std::endl << matrix2;
	if (matrix1.get_row_count() != matrix1.get_column_count()) {
		std::cout << "Rank: " << calculate_rank(matrix2) << std::endl;
	}

	std::cout << std::endl << "The sum of the matrices is:" << std::endl;
	Matrix sum_matrix = matrix1 + matrix2;
	std::cout << sum_matrix;
	std::cout << "Rank: " << calculate_rank(sum_matrix) << std::endl;
}



Task3::Task3(std::string header_value)
{
	this->initialize_menu(header_value);
}

Task3::~Task3()
{
}
