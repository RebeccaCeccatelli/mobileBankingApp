//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H
#define MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H

#include "../general_purpose_classes/InputManager.h"
#include "../profile_classes/SecurityManagerView.h"
#include "BankingAccount.h"

class BankingAccountView : public InputManager {
public:
    BankingAccountView(BankingAccount *bAccount, const SecurityManagerView *smView) :
        bankingAccount{bAccount}, securityManagerView{smView} {}
    virtual ~BankingAccountView() = default;

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    //helper methods
    void displayDetailedInformations() const;

    void displayTransactions() const;
    static void showList(const vector<Transaction *> &selectedTransactions);
    static void showTransactionGeneralities(const Transaction* transaction);
    static int goForFurtherDetails(int count);
    static void showTransactionDetails(const Transaction* transaction);

    void createTransaction();
    void createPhoneRecharge();
    void createWireTransfer();
    static tuple<string,string,int> gatherPhoneRechargeInfo();
    static tuple<string,string,string,int> gatherWireTransferInfo();

    void notifyIfLowDeposit();

    //attributes
    BankingAccount* bankingAccount{nullptr};
    const SecurityManagerView* securityManagerView{nullptr};

    //class constants
    static const string INFOS;
    static const string CARDS;
    static const string TRANSACTIONS;
    static const string NEW;
    static const string WIRE_TRANSFER;
    static const string RECHARGE;
};


#endif //MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H
