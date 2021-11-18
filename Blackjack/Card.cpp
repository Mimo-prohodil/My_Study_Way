#include "Card.h"

Card::Card(const EnumValue value, const EnumSuit suit) : value(value), suit(suit), isFacingUp(false) {}

void Card::flip() {
    isFacingUp = !isFacingUp;
}

int Card::getValue() const {
	if (!isFacingUp) {
		return 0;
	}
    return int(value);
}

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    const std::string VALUE[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const std::string SUIT[] = { "c", "d", "h", "s" };

    if (aCard.isFacingUp)
    {
        os << VALUE[(int)aCard.value] << SUIT[(int)aCard.suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}
