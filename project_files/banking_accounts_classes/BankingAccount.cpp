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
    ar & chargeCardView;
}