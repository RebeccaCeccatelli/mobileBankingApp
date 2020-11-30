//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H
#define MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H

#include "../general_purpose_classes/InputManager.h"
#include "BankingAccount.h"

class BankingAccountView : public InputManager {
public:
    BankingAccountView(BankingAccount *bAccount) : bankingAccount{bAccount} {}

    virtual ~BankingAccountView() = default;

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    //helper methods
    void displayDetailedInformations() const;
    void displayTransactions() const; //TODO
    void createTransaction();
    void createWireTransfer();
    void createPhoneRecharge();
    void notifyIfLowDeposit();
    static tuple<string,string,int> gatherPhoneRechargeInfo();
    static tuple<string,string,string,int> gatherWireTransferInfo();

    static bool wantToSaveAsFile();
    static string decideSortingLogic();
    static string insertFilter(const string& request);
    static void showList(const vector<Transaction *> &selectedTransactions);
    static void showTransactionGeneralities(const Transaction* transaction);
    static void showTransactionDetails(const Transaction* transaction);
    static int goForFurtherDetails(int count);



    //attribute
    BankingAccount* bankingAccount{nullptr};

    //class constants
    static const string INFOS;
    static const string CARDS;
    static const string TRANSACTIONS;
    static const string NEW;
    static const string BACK;
    static const string WIRE_TRANSFER;
    static const string RECHARGE;
    static const string YES;
    static const string NO;
    static const string SORT_BY_DATE;
    static const string FILTER_DATE;
    static const string FILTER_CATEGORY;
};


#endif //MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H
