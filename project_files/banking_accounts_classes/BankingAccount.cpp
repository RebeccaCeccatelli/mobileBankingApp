//
// Created by rebecca on 11/21/20.
//

#include "BankingAccount.h"

template<typename Archive>
void BankingAccount::serialize(Archive &ar, const unsigned int version) {
    ar & dateSetter;
    ar & IBAN;
    ar & accountHolder;
    ar & totalDepositAmount;
    ar & transactions;
    ar & chargeCards;
}

pair<string, int> BankingAccount::getIbanAndDeposit() const{
    return make_pair(IBAN,totalDepositAmount);
}

map<string,ChargeCard> *BankingAccount::getChargeCardsList() {
    return &chargeCards;
}

tuple<string, string, int> BankingAccount::getDetailedInformations() const {
    int numberOfCards = chargeCards.size();
    string creationDate = dateSetter.getDate();
    return make_tuple(accountHolder,move(creationDate),numberOfCards);
}
