//
// Created by rebecca on 11/21/20.
//

#include "ChargeCard.h"

const int ChargeCard::MAX_LIMIT = 10.000;

template<typename Archive>
void ChargeCard::serialize(Archive &ar, const unsigned int version) {
    ar & cardNumber;
    ar & cardType;
    ar & active;
    ar & monthlyLimit;
    ar & relatedCardTransactions; //verificare che deserializzi anche le chiavi TODO
}

pair<string, CardType> ChargeCard::getNumberAndType() const {
    return make_pair(cardNumber,cardType);
}

bool ChargeCard::isActive() const {
    return active;
}

pair<int, int> ChargeCard::getLimits() const {
    return make_pair(monthlyLimit,MAX_LIMIT);
}

bool ChargeCard::setLimit(int newLimit) {
    bool acceptable = false;

    if(newLimit <= MAX_LIMIT){
        monthlyLimit = newLimit;
        acceptable = true;
    }
    return acceptable;
}

void ChargeCard::changeState() {
    active = !active;
}

const string &ChargeCard::getLatestTransaction() const {
    return relatedCardTransactions.crbegin()->first;
}
