#pragma once
#include "Hand.h"
#include <string>

class GenericPlayer : public Hand {
protected:
	std::string m_Name;
public:
	virtual bool isHitting() const = 0;
	bool IsBoosted() const {

	}
	void Bust() const {

	}
};

