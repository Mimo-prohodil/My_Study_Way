#include "GenericPlayer.h"
#include <iostream>

inline bool GenericPlayer::IsBusted(){
	return GetValue() > 21;
}
inline void GenericPlayer::Bust(){
	if (IsBusted()) {
		std::cout << "Player: " << m_Name << " has bust." << std::endl;
	}
}
