//
// Created by rebecca on 11/21/20.
//

#include "ChargeCard.h"

template<typename Archive>
void ChargeCard::serialize(Archive &ar, const unsigned int version) {
    ar & cardNumber;
    ar & cardType;
    ar & active;
    ar & monthlyLimit;
    ar & relatedCardTransactions;
}
