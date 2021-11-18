#include "PhoneNumber.h"
#include <sstream>
#include <iomanip>

PhoneNumber::PhoneNumber(const unsigned int countryCode, const unsigned int cityCode,
	const std::string phoneNumber, const std::optional<unsigned int> additonalNumber)
	:	countryCode(countryCode),
		cityCode(cityCode),
		phoneNumber(phoneNumber),
		additonalNumber(additonalNumber) {}

PhoneNumber::PhoneNumber(const std::string countryCode,	const std::string cityCode,
	const std::string phoneNumber, const std::string additonalNumber)
	:	countryCode(std::stoi(countryCode)),
		cityCode(std::stoi(cityCode)),
		phoneNumber(phoneNumber),
		additonalNumber(std::nullopt) {
	if (additonalNumber.size()) {
		this->additonalNumber = std::stoi(additonalNumber);
	}
}

std::ostream& operator << (std::ostream& out, const PhoneNumber& pn) {	
	std::stringstream ss;
	ss << "\t" << '+' << pn.countryCode	<< '(' << pn.cityCode << ')' << pn.phoneNumber;	

	if (pn.additonalNumber != std::nullopt) {
		ss << ' ' << pn.additonalNumber.value();
	}	
	return out << ss.str();
}

bool operator== (const PhoneNumber& p1, const PhoneNumber& p2) {
	return std::tie(p1.countryCode, p1.cityCode, p1.phoneNumber, p1.additonalNumber) ==
		std::tie(p2.countryCode, p2.cityCode, p2.phoneNumber, p2.additonalNumber);
}

bool operator< (const PhoneNumber& p1, const PhoneNumber& p2) {
	return std::tie(p1.countryCode, p1.cityCode, p1.phoneNumber, p1.additonalNumber) <
		std::tie(p2.countryCode, p2.cityCode, p2.phoneNumber, p2.additonalNumber);
}