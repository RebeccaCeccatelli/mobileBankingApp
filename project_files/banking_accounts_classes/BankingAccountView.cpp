//
// Created by rebecca on 11/21/20.
//

#include "BankingAccountView.h"

#include <iostream>
#include <cmath>

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
const string BankingAccountView::YES = "yes";
const string BankingAccountView::NO = "no";
const string BankingAccountView::SORT_BY_DATE = "sd";
const string BankingAccountView::FILTER_DATE = "fd";
const string BankingAccountView::FILTER_CATEGORY = "fc";

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

    if(wantToSaveAsFile()) {
        bankingAccount->serializeInReadableFormat();
        cout << "Saved. " << endl;
    }
}

void BankingAccountView::displayTransactions() const {
    string input = decideSortingLogic();

    if (input == BACK){
        return;
    }
    else if (input == SORT_BY_DATE){
        const auto list = bankingAccount->returnSelected(RequestedTransactions::all);
        showList(list);
    }
    else if (input == FILTER_DATE){
        const auto list = bankingAccount->returnSelected(RequestedTransactions::specificDate, insertFilter(input));
        showList(list);
    }
    else if (input == FILTER_CATEGORY) {
        const auto list = bankingAccount->returnSelected(RequestedTransactions::specificCategory,insertFilter(input));
        showList(list);
    }
    else{
        cout << "Your input is not correct. Try again. " << endl;
        displayTransactions();
    }
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
        cout << "Wire transfer successfully received and saved. " << endl << "Your banking account deposit now is: "
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
        cout << "Phone recharge successfully received and saved." << endl << "Your banking account deposit now is: "
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

bool BankingAccountView::wantToSaveAsFile() {
    cout << "Do you want to save these informations in a readable format in your saved files?" << endl;
    string input = getStringInput();

    if (input == YES)
        return true;
    if (input == NO)
        return false;
    else {
        cout << "Your input is not correct. Try again. " << endl;
        return wantToSaveAsFile();
    }
}

string BankingAccountView::decideSortingLogic() {
    cout << endl << "- Sort all by date (sd). "  << endl << "- Filter by requested date (fd). " << endl <<
         "- Filter by category (fc). " << endl << "- Go back (0). " << endl;
    string input = getStringInput();

    return input;
}

string BankingAccountView::insertFilter(const string& request) {
    if (request == FILTER_DATE)
        cout << "Please, insert a specific date in format mm/dd/yy: " << endl;
    else if (request == FILTER_CATEGORY)
        cout << "Please, insert a category between '...', '...': " << endl; //inserire categorie alla fine FIXME
    auto filter = getStringInput();

    return filter;
}

void BankingAccountView::showList(const vector<Transaction *> &selectedTransactions) {
    if (selectedTransactions.empty())
        cout << "The list is empty. " << endl;
    else {
        int count = 0;
        for (auto transaction : selectedTransactions) {
            cout << ++count << ") ";
            showTransactionGeneralities(transaction);
        }
        int requested = goForFurtherDetails(count);
        if (requested == -1)
            return;
        else
            showTransactionDetails(selectedTransactions[requested]);
    }
}

void BankingAccountView::showTransactionGeneralities(const Transaction *transaction) {
    cout << " Amount: " << transaction->getAmount();
    if (signbit(transaction->getAmount()))
        cout << " (outflow) ";
    else
        cout << " (income)";
    cout << " || Type: " << transaction->getDescription() << " || Date: " << transaction->getDate()
        << " || Category: " << transaction->getCategory() << " || ";
    if (transaction->isProcessed())
        cout << " processed. " << endl;
    else
        cout << " still not processed " << endl;
}

int BankingAccountView::goForFurtherDetails(int count) {
    cout << endl << "Enter the corresponding number to see further details, (0) to go back. " << endl;
    string input = getStringInput();

    if (input == BACK )
        return -1;
    else if (stoi(input) > count){
        cout << "Your input is not correct. Try again. " << endl;
        return goForFurtherDetails(count);
    }
    else
        return stoi(input)-1;
}

void BankingAccountView::showTransactionDetails(const Transaction *transaction) {
    showTransactionGeneralities(transaction);

    //metodo getDetails virtuale per tutti i tipi di transazioni con covarianza del tipo di ritorno
    //oppure viewer per transazioni con viewer specializzati TODO
}
