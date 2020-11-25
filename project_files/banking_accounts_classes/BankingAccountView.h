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
    void display() override;
    bool isCorrectInput(const string &input) override;

    //helper methods
    void displayDetailedInformations() const;//aggiungere anche numero carte e data ultima transazione TODO
    void displayTransactions() const{}//aggiungere possibilità di 1.vedere tutte(data implicito), 2.vedere per giorno, 3.vedere per tipologia TODO
    void createTransaction(){} //vedi remindersmanagerview createReminder() //TODO

    //attribute
    BankingAccount* bankingAccount{nullptr};

    //class constants
    static const string INFOS;
    static const string CARDS;
    static const string TRANSACTIONS;
    static const string NEW;
    static const string BACK;
};


#endif //MOBILE_BANKING_APP_BANKINGACCOUNTVIEW_H
