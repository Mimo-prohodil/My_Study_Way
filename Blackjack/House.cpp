#include "House.h"
#include <iostream>
bool House::isHitting() const {
    return (GetTotal() <= 16);
}
void House::FlipFirstCard()
{
    if (!(m_Cards.empty()))
    {
        m_Cards[0]->flip();
    }
    else
    {
        std::cout << "No card to flip!\n";
    }
}

