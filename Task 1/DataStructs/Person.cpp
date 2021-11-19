#include"Person.h"
#include <ostream>
#include <tuple>
#include <sstream>
#include <iomanip>

Person::Person(const std::string surname, const std::string name, const std::string middleName)
	:	surname(surname),
		name(name),
		middleName(std::nullopt) {
	if (middleName.size()) {
		this->middleName = middleName;
	}
}

std::ostream& operator<< (std::ostream& out, const Person& p) {
	std::stringstream ss;
	if (p.middleName != std::nullopt) {
		ss << std::right << std::setw(12) << p.surname
			<< std::setw(10) << p.name << std::setw(15) << p.middleName.value();
		return out << ss.str();
	}
	ss << std::right << std::setw(12) << p.surname 
		<< std::setw(10) << p.name << std::setw(15) << " ";
	return out << ss.str();
}

bool operator== (const Person& p1, const Person& p2) {
	return std::tie(p1.surname, p1.name, p1.middleName) ==
		std::tie(p2.surname, p2.name, p2.middleName);
}

bool operator< (const Person& p1, const Person& p2) {
	return std::tie(p1.surname, p1.name, p1.middleName) <
		std::tie(p2.surname, p2.name, p2.middleName);
}