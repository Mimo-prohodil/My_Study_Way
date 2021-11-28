#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>

template <typename T1, typename T2>
void templateInsertSorted(T1& container, const T2& value) {
	container.insert(std::lower_bound(container.begin(), container.end(), value), value);	
}

template <typename T>
void printContainer(const T& vec) {
	for (const auto& it : vec) {
		std::cout << it << " ";
	}
	std::cout << std::endl << std::endl;
}

int main() {

	std::vector<int> entranceVector{ 0,1,2,3,4,5,6,7,8,9 };
	std::cout << "Original vector:" << std::endl;
	printContainer(entranceVector);
	std::cout << "Vector after insert:" << std::endl;
	templateInsertSorted(entranceVector, 2);
	printContainer(entranceVector);	

	std::cout << "Original list:" << std::endl;	
	std::list<double> entranceList{ 0.1, 1.1, 2.2, 3.3, 4.5, 5.5, 6.6, 7.7, 8.8, 9.8 };
	printContainer(entranceList);
	templateInsertSorted(entranceList, 2.3);
	std::cout << "Vector after insert 2.3:" << std::endl;
	printContainer(entranceList);

	std::cout << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << std::endl;

	srand(time(NULL));
	const size_t SIZE{ 100 };
	std::vector<double> materialVec(SIZE);
	std::vector<int> integerVec(SIZE);
	std::vector<double> discrepancyVec(SIZE);
	
	std::generate(materialVec.begin(), materialVec.end(), 
		[]() {return (double)(rand()) / RAND_MAX * 13; });
	std::copy(materialVec.begin(), materialVec.end(), integerVec.begin());	
	printContainer(materialVec);
	printContainer(integerVec);

	//Решение без циклов
	double discrepancy = 0;
	std::transform(materialVec.begin(), materialVec.end(), discrepancyVec.begin(), 
		[](const double& d) {return (d - (int)d) * (d - (int)d); });
	discrepancy = std::accumulate(discrepancyVec.begin(), discrepancyVec.end(), 0.0);
	std::cout << discrepancy <<std::endl;

	// Решение через цикл
	discrepancy = 0;
	for (size_t i = 0; i < SIZE; ++i) {
		discrepancy += (materialVec[i] - integerVec[i]) * (materialVec[i] - integerVec[i]);
	}
	std::cout << discrepancy << std::endl;	
	std::cout << "============================================" << std::endl;
	std::cout << std::endl;

	return 0;
}