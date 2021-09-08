#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <vector>


class Game {
protected:
	Deck m_Deck;
	House m_House;
	std::vector<Player> m_Players;
public:
	void Play() {

	}

};

