#include "PhoneBook.h"
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>

PhoneBook::PhoneBook(std::ifstream& f) {
	if (!f.is_open()) {
		throw std::runtime_error("Cannot open file\n");
	}
	parseData(f);
}

void PhoneBook::parseData(std::ifstream& f) {
	std::string buff;
	std::string name;
	std::string surname;
	std::string middlename;
	std::string countryCode;
	std::string cityCode;
	std::string phoneNumber;
	std::string additonalNumber;	
	while (!f.eof()) {
		std::getline(f, buff);
		std::istringstream iss(buff);		
		iss >> name >> surname >> middlename
			>> countryCode >> cityCode >> phoneNumber >> additonalNumber;		

		if (middlename == "-") {
			middlename.clear();
		}
		if (additonalNumber == "-") {
			additonalNumber.clear();
		}
		phoneList.emplace_back(std::make_pair(Person(name, surname, middlename),
			PhoneNumber(countryCode, cityCode,
				phoneNumber, additonalNumber)));
	}
}

void PhoneBook::SortByName() {	
	std::sort(phoneList.begin(), phoneList.end(), 
		[](const std::pair<Person, PhoneNumber>& first, 
			const std::pair<Person, PhoneNumber>& second)->bool {
			return first.first < second.first;
		});
}

void PhoneBook::SortByPhone() {
	std::sort(phoneList.begin(), phoneList.end(),
		[](const std::pair<Person, PhoneNumber>& first,
			const std::pair<Person, PhoneNumber>& second)->bool {
				return first.second < second.second;
		});
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string str){
	PhoneNumber pn("1", "1", "1", "");
	int countMatches = 0;
	std::pair<std::string, PhoneNumber> out{"", pn};
	for (const auto& p : phoneList) {
		if (p.first.surname == str) {			
			countMatches++;
			if (countMatches > 1) {
				return std::make_pair("\tfound more than 1", pn);
			}
			std::get<1>(out) = std::get<1>(std::make_pair("", p.second));
		}
	}
	if (countMatches == 0) return std::make_pair("\tnot found", pn);	
	return out;
}

void PhoneBook::ChangePhoneNumber(Person p, PhoneNumber pn){
	for (auto & pL : phoneList) {
		if (pL.first == p) {
			pL.second = pn;
		}
	}
}

std::ostream& operator<< (std::ostream& out, const PhoneBook& pb) {
	std::stringstream ss;	
	for (const auto& p : pb.phoneList) {	
		ss << p.first << p.second << std::endl;		
	}
	return out << ss.str();
}