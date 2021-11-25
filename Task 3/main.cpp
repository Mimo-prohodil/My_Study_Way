#include <iostream>
#include <list>
#include <vector>
#include <tuple>
#include <clocale>
#include "Matrix.h"
#include "IntArr.h"

void insertBack(std::list<int>& list) {
	double sum = 0;
	for (const auto& i : list) {
		sum += i;
	}
	list.push_back((int)round((sum / list.size())));	
}
void printList(const std::list<int>& list) {
	for (const auto& i : list) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "Ru");
	{
		std::cout << "Ћист до вставки:" << std::endl;
		std::list<int> nums{ 78,3 };
		printList(nums);
		insertBack(nums);
		std::cout << "Ћист после вставки:" << std::endl;
		printList(nums);
		std::cout << std::endl;
	}
	std::cout << "==============================================" << std::endl;
	{
		std::cout << std::endl;
		size_t matrixSize;
		std::cout << "¬ведите размерность матрицы:" << std::endl;
		std::cin >> matrixSize;

		std::vector<int> matrix;
		srand(time(0));
		for (size_t i = 0; i < matrixSize * matrixSize; ++i) {
			matrix.emplace_back(std::rand() % 20 - 10);
		}

		Matrix m(matrix, matrixSize);
		std::cout << m << std::endl;
		std::cout << m.getDeterminator() << std::endl;
	}
	std::cout << "==============================================" << std::endl;
	{
		std::cout << std::endl;
		IntArr intArr;
		for (const auto& it : intArr) {
			std::cout << it << " ";
		}	
		std::cout << std::endl;
		for (IntArr::Iterator it{ intArr.begin() }; it != intArr.end(); ++it) {
			std::cout << *it << " ";
		}	
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "==============================================" << std::endl;
	return 0;
}