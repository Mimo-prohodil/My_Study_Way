#pragma once
#include <vector>
#include <utility>
#include <fstream>
#include "DataStructs/Person.h"
#include "DataStructs/PhoneNumber.h"

class PhoneBook {

	std::vector<std::pair<Person, PhoneNumber>> phoneList;
	void parseData(std::ifstream& file);

public:
	PhoneBook(std::ifstream& f);

	void SortByName();
	void SortByPhone();
	std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string str);
	void ChangePhoneNumber(Person p, PhoneNumber pn);

	friend std::ostream& operator<< (std::ostream& out, const PhoneBook& pb);
};

