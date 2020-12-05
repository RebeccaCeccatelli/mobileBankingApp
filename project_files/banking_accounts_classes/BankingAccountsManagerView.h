//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H
#define MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H

#include <map>
#include <boost/serialization/map.hpp>

#include "../general_purpose_classes/InputManager.h"
#include "../profile_classes/SecurityManagerView.h"
#include "BankingAccount.h"

using namespace std;
using namespace boost::archive;

class BankingAccountsManagerView : public InputManager {
public:
    virtual ~BankingAccountsManagerView() = default;

    void setClientName(const string& cname);
    void setSMViewReference(const SecurityManagerView* smView);

private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & bankingAccounts;
    }

    void display() override;
    bool isCorrectInput(const string &input) override;

    void pullFromServer();
    void updateServer() const;

    //attributes
    map<string,BankingAccount> bankingAccounts;
    string clientName;
    const SecurityManagerView* securityManagerView{nullptr};
};


#endif //MOBILE_BANKING_APP_BANKINGACCOUNTSMANAGERVIEW_H
