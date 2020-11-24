//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H
#define MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H

#include <list>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/list.hpp>

#include "../general_purpose_classes/InputManager.h"
#include "BankingAccount.h"
#include "BankingAccountView.h"

using namespace std;
using namespace boost::archive;

class BankingAccountsManagerView : public InputManager {
public:
    virtual ~BankingAccountsManagerView() = default;
private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    void display() override{}
    bool isCorrectInput(const string &input) override{}

    //attributes
    list<BankingAccount> bankingAccounts;
    BankingAccountView bankingAccountView{nullptr};
};


#endif //MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H
