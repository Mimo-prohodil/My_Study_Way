#include "Card.h"

inline Card::Card(const EnumValue value, const EnumSuit suit) : value(value), suit(suit), isFacingUp(false) {}

inline void Card::flip() {
    isFacingUp = !isFacingUp;
}

inline int Card::getValue() const {
	if (!isFacingUp) {
		return 0;
	}
    return int(value);
}
