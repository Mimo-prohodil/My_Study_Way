#include <iostream>
#include <utility>
#include <clocale>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_set>
#include "Timer.h"

template <typename T1, typename T2>
void Swap(T1& left, T2& right) {	
	T1 tmp = std::move(left);
	left = std::move(reinterpret_cast<T1>(right));
	right = std::move(reinterpret_cast<T2>(tmp));
}

template <typename T>
void SortPointers(std::vector<T>& vec) {
	std::sort(vec.begin(), vec.end(), [](const T& first, const T& second) 
		{return *first < *second; });
}

int countVowelByCountIfAndFind(const std::string& inpStr, const std::unordered_set<char>& CHAR_SET) {
	Timer t;
	return std::count_if(inpStr.begin(), inpStr.end(), 
		[&CHAR_SET](const char& ch)->bool {
		return CHAR_SET.find(ch) != CHAR_SET.end(); });	
}

int countVowelByCountIfAndFor(const std::string& inpStr, const std::unordered_set<char>& CHAR_SET) {
	Timer t;
	return std::count_if(inpStr.begin(), inpStr.end(), [&CHAR_SET](const char& ch)->bool {
		for (const auto& v : CHAR_SET) {
			if (ch == v) {
				return true;
			}
		}
		return false; });
}

int countVowelByForAndFind(const std::string& inpStr, const std::unordered_set<char>& CHAR_SET) {
	Timer t;
	int count = 0;
	for (const auto& iS : inpStr) {
		if (CHAR_SET.find(iS) != CHAR_SET.end()) {
			count++;
		}
	}
	return count;
}

int countVowelByForAndFor(const std::string& inpStr, const std::unordered_set<char>& CHAR_SET) {
	Timer t;
	int count = 0;
	for (const auto& iS : inpStr) {
		for (const auto& v : CHAR_SET) {
			if (iS == v) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	setlocale(LC_ALL, "Russian");
#pragma region 1
{
	int a{ 10 };	
	std::string str1{ "----------" };		
	int* ptr2 = &a;
	std::string* ptr1 = &str1;			
		
	std::cout << "До перестановок:" << std::endl;
	std::cout << "ptr 1* = " << *ptr1 << std::endl;
	std::cout << "ptr 2* = " << *ptr2 << std::endl;
	std::cout << "ptr 1 = " << ptr1 << std::endl;
	std::cout << "ptr 2 = " << ptr2 << std::endl;
	std::cout << std::endl;	

	//std::swap(ptr1, ptr2);
	Swap(ptr1, ptr2);
	std::cout << "Перестановка указателей:" << std::endl;
	std::cout << "ptr 1* = " << *(int*)ptr1 << std::endl;
	std::cout << "ptr 2* = " << *(std::string*)ptr2 << std::endl;
	std::cout << "ptr 1 = " << ptr1 << std::endl;
	std::cout << "ptr 2 = " << ptr2 << std::endl;
	std::cout << std::endl;	
}

#pragma endregion 
#pragma region 2
{
	int* ptr1 = new int{ 10 };
	int* ptr2 = new int{ 20 };
	int* ptr3 = new int{ 30 };
	int* ptr4 = new int{ 40 };
	int* ptr5 = new int{ 50 };
	int* ptr6 = new int{ 60 };
	int* ptr7 = new int{ 70 };
	int* ptr8 = new int{ 80 };
	std::vector<int*> vec{ ptr1, ptr2, ptr8, ptr7, ptr6, ptr5, ptr4, ptr3,};

	std::cout << "Изначальный массив" << std::endl;
	for (const auto& v : vec) {
		std::cout << *v << ' ';
	}
	std::cout << std::endl;

	SortPointers(vec);
	std::cout << "Отсоритированный массив" << std::endl;
	for (const auto& v : vec) {
		std::cout << *v << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;

}
#pragma endregion 
#pragma region 3

	const std::unordered_set<char>VOWELS = { 'А', 'Е', 'Ё', 'И', 'О', 'У',
		                       'Э', 'Ю', 'Я' , 'а', 'е', 'ё', 'и', 
		                       'о', 'у', 'ы', 'э', 'ю', 'я' };	
	std::ifstream file("War&peace.txt");
	std::string inpStr;
	std::string buff;
	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, buff);
			inpStr += buff;
		}
	}
	
	std::cout << "Кол-во всех символов: " << inpStr.size() << std::endl << std::endl;
	std::cout << "Подсчет с помощью count_if и find: \t" << countVowelByCountIfAndFind(inpStr, VOWELS) 
		<< std::endl << "Затраченное время: \t\t" << Timer::getDuration() << std::endl << std::endl;
	std::cout << "Подсчет с помощью count_if и for: \t" << countVowelByCountIfAndFor(inpStr, VOWELS)
		<< std::endl << "Затраченное время: \t\t" << Timer::getDuration() << std::endl << std::endl;
	std::cout << "Подсчет с помощью for и find: \t" << countVowelByForAndFind(inpStr, VOWELS)
		<< std::endl << "Затраченное время: \t\t" << Timer::getDuration() << std::endl << std::endl;
	std::cout << "Подсчет с помощью for и for: \t" << countVowelByForAndFor(inpStr, VOWELS)
		<< std::endl << "Затраченное время: \t\t" << Timer::getDuration() << std::endl;
			
#pragma endregion 

	return 0;
}

