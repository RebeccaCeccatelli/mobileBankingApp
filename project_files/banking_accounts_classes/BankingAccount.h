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
#include "ChargeCardManagerView.h"
#include "ChargeCard.h"
#include "../general_purpose_classes/DateSetter.h"

using namespace std;
using namespace boost::archive;

class BankingAccount {
public:
    pair<string,int> getIbanAndDeposit() const;
    tuple<string,string,int> getDetailedInformations() const; //valutare se aggiungere data dell'ultima transazione se ci si riesce TODO

    map<string,ChargeCard>* getChargeCardsList();

private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    string IBAN;
    int totalDepositAmount;
    string accountHolder;
    DateSetter dateSetter;

    map<string,Transaction*> transactions;
    map<string, ChargeCard> chargeCards;
};

#endif //MOBILE_BANKING_APP_BANKINGACCOUNT_H
