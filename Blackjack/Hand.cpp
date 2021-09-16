#include "Hand.h"

void Hand::Add(Card* ptr){
    m_Cards.push_back(ptr);
}

void Hand::Clear(){
    for (const Card* iter : m_Cards) {
        delete iter;        
    }
    m_Cards.clear();
}

int Hand::GetTotal() const{
    if (m_Cards.empty()) {
        return 0;
    }
    if (m_Cards[0]->getValue() == 0) {
        return 0;
    }
    int value = 0;
    bool containsAce = false;
    for (const Card* iter : m_Cards) {
       value += iter->getValue();
        if (iter->getValue() == int(Card::EnumValue::ACE)) {
            containsAce = true;
        }        
    }    
    if (containsAce && value <= 11) {        
        value += 10;
    }    
    return value;
}
