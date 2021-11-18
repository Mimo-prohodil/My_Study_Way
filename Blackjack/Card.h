#pragma once
#include <iostream>
class Card {
public:
    enum class EnumSuit { DIAMONDS, CLUBS, HEARTS, SPADES };
    enum class EnumValue { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
protected:
    bool isFacingUp;
    EnumValue value;
    EnumSuit suit;
public:
    Card(const EnumValue value, const EnumSuit suit);
    void flip();
    int getValue()const;
    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);
};

 