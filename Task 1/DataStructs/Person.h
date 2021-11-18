#pragma once
#include <string>
#include <optional>

struct Person {
	std::string surname;
	std::string name;
	std::optional<std::string> middleName;	

	Person(const std::string surname, const std::string name, const std::string middleName);		

	friend std::ostream& operator<< (std::ostream& out, const Person& p);
	friend bool operator== (const Person& p1, const Person& p2);
	friend bool operator< (const Person& p1, const Person& p2);
};

