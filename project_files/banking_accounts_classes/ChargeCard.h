//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_CHARGECARD_H
#define MOBILE_BANKING_APP_CHARGECARD_H

#include <string>
#include <list>

#include "CardTransaction.h"

using namespace std;

enum class CardType {
    credit,
    debit
};

class ChargeCard {

private:
    string cardNumber;
    CardType cardType;
    bool active{true};
    int monthlyLimit{500};

    list<CardTransaction> relatedCardTransactions;
};


#endif //MOBILE_BANKING_APP_CHARGECARD_H
