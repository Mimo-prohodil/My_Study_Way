#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Matrix::Matrix(const std::vector<int>& vec, const size_t& SIZE_X) {
	if (vec.size() % SIZE_X && vec.size() / SIZE_X != SIZE_X) {
		throw std::runtime_error("Ошибка наполнения квадратной матрицы");
	}
	for (size_t i = 0; i < vec.size(); i += SIZE_X) {
		matrix.emplace_back(vec.begin() + i, vec.begin() + i + SIZE_X);
	}
}

double Matrix::getDeterminator() {	
	std::vector<std::vector<double>> vec = matrix;
	bool isPlus = true;
	for (size_t i = 0; i < vec.size() - 1; ++i) {
		if (vec[i][i] == 0) {
			for (size_t j = i + 1; j < vec.size(); ++j) {
				if (vec[j][i] != 0) {
					for (size_t k = i; k < vec.size(); ++k) {
						isPlus = !isPlus;
						std::swap(vec[j][k], vec[i][k]);
					}
					break;
				}
			}
			if (vec[i][i] == 0) {
				return 0;
			}
		}
		for (size_t j = i + 1; j < vec.size(); ++j) {
			if (vec[j][i] != 0) {
				double multiplier = vec[j][i] / vec[i][i];
				for (size_t k = i; k < vec.size(); ++k) {
					vec[j][k] -= multiplier * vec[i][k];
				}
			}
		}
	}
	if (vec[vec.size()-1][vec.size() - 1] == 0) {
		return 0;
	}
	double determinator{ isPlus ? 1.0 : -1.0 };
	for (size_t i = 0; i < vec.size(); ++i) {
		determinator *= vec[i][i];
	}
	return determinator;
}

std::ostream& operator<< (std::ostream& out, const Matrix& matrix) {	
	for (const auto& row : matrix.matrix) {
		for (const auto& column : row) {
			out <<std::setw(4) << column;
		}
		out << std::endl;
	}	
	return out;
}

