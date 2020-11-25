//
// Created by rebecca on 11/21/20.
//

#include "BankingAccountView.h"

#include <iostream>
#include "../general_purpose_classes/utilityFunctions.h"

using namespace utilityFunctions;
using namespace std;

const string BankingAccountView::INFOS = "1";
const string BankingAccountView::CARDS = "2";
const string BankingAccountView::TRANSACTIONS = "3";
const string BankingAccountView::NEW = "4";
const string BankingAccountView::BACK = "0";

void BankingAccountView::display() {
    cout << endl << "*** Banking account " << bankingAccount->getIbanAndDeposit().first
        << ". What would you like to do? ***" << endl;
    cout << "1) Banking account's detailed informations. " << endl << "2) Associated charge cards. "
        << endl << "3) List of associated transactions. " << endl << "4) Create new transaction. "
        << endl << "0) Go back. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(getStringInput());
}

bool BankingAccountView::isCorrectInput(const string &input) {
    bool correct = true;
    if (input == BACK)
        setGoBack(true);
    else if (input == INFOS)
        displayDetailedInformations();
    else if (input == CARDS) {
        ChargeCardManagerView chargeCardView(bankingAccount->getChargeCardsList());
        chargeCardView.displayUserInterface();
    }
    else if (input == TRANSACTIONS)
        displayTransactions();
    else if (input == NEW) {
        createTransaction();
    }
    else
        correct = false;

    return correct;
}

void BankingAccountView::displayDetailedInformations() const {
    auto ibanAndDeposit = bankingAccount->getIbanAndDeposit();
    auto details = bankingAccount->getDetailedInformations();

    cout << endl << "*** Detailed informations. *** " << endl;
    cout << "- IBAN: " << ibanAndDeposit.first << endl << "- Total deposit available: " << ibanAndDeposit.second
        << endl << "- Account holder: " << get<0>(details) << endl << "- Creation date: " << get<1>(details)
        << endl << "- Number of associated cards: " << get<2>(details) << endl;
}


