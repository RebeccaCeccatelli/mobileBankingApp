//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNT_H
#define MOBILE_BANKING_APP_BANKINGACCOUNT_H

#include <map>
#include <string>
#include <boost/serialization/string.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp>

#include "Transaction.h"
#include "ChargeCardView.h"
#include "../general_purpose_classes/DateSetter.h"

using namespace std;
using namespace boost::archive;

class BankingAccount {
public:

private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    DateSetter dateSetter;
    string IBAN;
    string accountHolder;
    int totalDepositAmount;

    map<string,Transaction*> transactions;
    ChargeCardView chargeCardView;
};



#endif //MOBILE_BANKING_APP_BANKINGACCOUNT_H
