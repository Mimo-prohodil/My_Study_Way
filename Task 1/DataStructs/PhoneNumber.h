#pragma once
#include <string>
#include <optional>

struct PhoneNumber {

	unsigned int countryCode;
	unsigned int cityCode;
	std::string phoneNumber;
	std::optional<unsigned int> additonalNumber;		

	PhoneNumber(const unsigned int countryCode,	const unsigned int cityCode,
		const std::string phoneNumber, const std::optional<unsigned int> additonalNumber);
		
	PhoneNumber(const std::string countryCode, const std::string cityCode,
		const std::string phoneNumber, const std::string additonalNumber);	

	friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& p);
	friend bool operator== (const PhoneNumber& p1, const PhoneNumber& p2);
	friend bool operator< (const PhoneNumber& p1, const PhoneNumber& p2);
};
