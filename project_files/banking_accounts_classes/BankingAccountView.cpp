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
const string BankingAccountView::WIRE_TRANSFER = "t";
const string BankingAccountView::RECHARGE = "r";

void BankingAccountView::display() {
    cout << endl << "*** Banking account " << bankingAccount->getIban()
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
        ChargeCardManagerView chargeCardManagerView(bankingAccount->getChargeCardsList());
        chargeCardManagerView.displayUserInterface();
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
    auto IBAN = bankingAccount->getIban();
    auto deposit = bankingAccount->getDeposit();
    auto details = bankingAccount->getDetailedInformations();

    cout << endl << "*** Detailed informations. *** " << endl;
    cout << "- IBAN: " << IBAN << endl << "- Total deposit available: " << deposit
        << endl << "- Account holder: " << get<0>(details) << endl << "- Creation date: " << get<1>(details) << endl
        << "- Number of associated cards: " << get<2>(details) << endl << "- Latest transaction made on: " << get<3>(details) << endl;
}

void BankingAccountView::displayTransactions() const {
//aggiungere possibilità di 1.vedere tutte(data implicito),
//2.vedere per giorno, 3.vedere per tipologia
}

void BankingAccountView::createTransaction() {
    cout << "*** New transaction. ***" << endl << "You can create a wire transfer (t) or a phone recharge (r). Choose one: ";
    string input = getStringInput();
    if (input == WIRE_TRANSFER)
        createWireTransfer();
    else if(input == RECHARGE)
        createPhoneRecharge();
    else{
        cout << "Your input is not correct. Try again. " << endl;
        createTransaction();
    }
}

void BankingAccountView::createWireTransfer() {
    auto userInformations = gatherWireTransferInfo();

    if(bankingAccount->createWireTransfer(userInformations)){
        cout << "Wire transfer successfully received. " << endl << "Your banking account deposit now is: "
        << bankingAccount->getDeposit() << ". " << endl;
        notifyIfLowDeposit();
    }
    else{
        cout << "Wire transfer negated. You asked to recharge " << get<3>(userInformations)
             << " euros but your banking account deposit is just " << bankingAccount->getDeposit()
             << " euros. " << endl << "Not sufficient. " << endl;
    }

}

void BankingAccountView::createPhoneRecharge() {
    auto userInformations = gatherPhoneRechargeInfo();

    if(bankingAccount->createPhoneRecharge(userInformations)){
        cout << "Phone recharge successfully received." << endl << "Your banking account deposit now is: "
        << bankingAccount->getDeposit() << "." << endl;
        notifyIfLowDeposit();
    }
    else {
        cout << "Phone recharge negated. You asked to recharge " << get<2>(userInformations)
             << " euros but your banking account deposit is just " << bankingAccount->getDeposit()
             << " euros. " << endl << "Not sufficient. " << endl;
    }
}

void BankingAccountView::notifyIfLowDeposit() {
    if (bankingAccount->isLowDeposit())
        cout << "Alert! Your deposit is lower than 50 euros now. " << endl;
}

tuple<string, string, int> BankingAccountView::gatherPhoneRechargeInfo() {
    cout << "Creating new phone recharge... " << endl;
    tuple<string, string, int> userInformations;

    cout << "Insert mobile operator (type '/' to confirm): " << endl;
    get<0>(userInformations) = getLineInput();
    cout << "Insert telephone number to recharge (type '/' to confirm): " << endl;
    get<1>(userInformations) = getLineInput();
    cout << "Insert amount to recharge: " << endl;
    get<2>(userInformations) = getNumInput();

    return userInformations;
}

tuple<string, string, string, int> BankingAccountView::gatherWireTransferInfo() {
    cout << "Creating new wire transfer... " << endl;
    tuple<string,string,string,int> userInformations;

    cout << "Insert recipient's IBAN (type '/' to confirm): " << endl;
    get<0>(userInformations) = getLineInput();
    cout << "Insert recipient's full name (type '/' to confirm): " << endl;
    get<1>(userInformations) = getLineInput();
    cout << "Insert reason of payment (type '/' to confirm): " << endl;
    get<2>(userInformations) = getLineInput();
    cout << "Insert amount to transfer: " << endl;
    get<3>(userInformations) = getNumInput();

    return userInformations;
}


