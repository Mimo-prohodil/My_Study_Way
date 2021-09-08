#pragma once
#include "Card.h"
#include <vector>

class Hand{
protected:
	std::vector<Card*> m_Cards;
public:
	void Add(Card* ptr);
	void Clear();
	int GetValue();
};
