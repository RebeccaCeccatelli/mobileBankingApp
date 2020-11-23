//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H
#define MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H

#include <list>

#include "../general_purpose_classes/InputManager.h"
#include "BankingAccount.h"
#include "BankingAccountView.h"

class BankingAccountsManagerView : public InputManager {
public:
    virtual ~BankingAccountsManagerView() = default;
private:
    void display() override{}
    bool isCorrectInput(const string &input) override{}

    //attributes
    list<BankingAccount> bankingAccounts;
    BankingAccountView bankingAccountView{nullptr};
};


#endif //MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H
