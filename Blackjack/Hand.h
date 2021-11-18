#pragma once
#include <vector>
#include "Card.h"

class Hand{
protected:
	std::vector<Card*> m_Cards;
public:
	void Add(Card* ptr);
	void Clear();
	int GetTotal() const;
};
