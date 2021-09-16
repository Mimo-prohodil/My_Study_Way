#pragma once
#include "Hand.h"
#include <string>

class GenericPlayer : public Hand {
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
protected:
	std::string m_Name;
public:
	GenericPlayer(const std::string& name = "");
	~GenericPlayer();
	virtual bool isHitting() const = 0;
	bool IsBusted() const;
	void Bust() const;
};

