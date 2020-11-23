//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNT_H
#define MOBILE_BANKING_APP_BANKINGACCOUNT_H

#include <map>
#include <list>
#include <string>

#include "Transaction.h"
#include "ChargeCardView.h"
#include "../general_purpose_classes/DateSetter.h"

using namespace std;

class BankingAccount {
private:
    DateSetter dateSetter;
    string IBAN;
    string accountHolder;
    int totalDepositAmount;

    map<string,Transaction&> transactions;
    ChargeCardView chargeCardView;
};


#endif //MOBILE_BANKING_APP_BANKINGACCOUNT_H
