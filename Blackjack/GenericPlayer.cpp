#include "GenericPlayer.h"
#include <iostream>

GenericPlayer::GenericPlayer(const std::string& name) : m_Name(name){}

inline bool GenericPlayer::IsBusted() const{
	return GetTotal() > 21;
}
inline void GenericPlayer::Bust() const{
	if (IsBusted()) {
		std::cout << "Player: " << m_Name << " busts." << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";

    std::vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
            pCard != aGenericPlayer.m_Cards.end();
            ++pCard)
        {
            os << *(*pCard) << "\t";
        }


        if (aGenericPlayer.GetTotal() != 0)
        {
            std::cout << "(" << aGenericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}


