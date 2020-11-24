//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_CHARGECARD_H
#define MOBILE_BANKING_APP_CHARGECARD_H

#include <string>
#include <list>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/list.hpp>

#include "CardTransaction.h"

using namespace std;
using namespace boost::archive;

enum class CardType {
    credit,
    debit
};

class ChargeCard {
public:

private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    string cardNumber;
    CardType cardType;
    bool active{true};
    int monthlyLimit{500};

    list<CardTransaction> relatedCardTransactions;
};


#endif //MOBILE_BANKING_APP_CHARGECARD_H