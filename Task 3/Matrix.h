#pragma once
#include <vector>
#include <ostream>

class Matrix {
	std::vector<std::vector<double>> matrix;
	
public:	
	Matrix(const std::vector<int>& vec, const size_t& SIZE_X);
	double getDeterminator();

	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
};