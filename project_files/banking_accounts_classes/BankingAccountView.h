//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H
#define MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H

#include "../general_purpose_classes/InputManager.h"
#include "BankingAccount.h"

class BankingAccountView : public InputManager {
public:
    explicit BankingAccountView(BankingAccount *bAccount) : bankingAccount{bAccount} {}

    virtual ~BankingAccountView() = default;

private:
    void display() override{}
    bool isCorrectInput(const string &input) override{}

    //attribute
    BankingAccount* bankingAccount;
};


#endif //MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H
