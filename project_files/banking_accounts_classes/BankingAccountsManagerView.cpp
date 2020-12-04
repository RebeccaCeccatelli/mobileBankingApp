//
// Created by rebecca on 11/21/20.
//

#include "BankingAccountsManagerView.h"

#include <iostream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "../general_purpose_classes/utilityFunctions.h"
#include "BankingAccountView.h"

using namespace std;
using namespace utilityFunctions;

void BankingAccountsManagerView::setClientName(const string &cname) {
    clientName = cname;
}

void BankingAccountsManagerView::display() {
    pullFromServer();

    cout << endl << "*** This is the list of your banking accounts. ***" << endl;
    if (bankingAccounts.empty())
        cout << "Empty. " << endl;
    else {
        for (const auto& bankingAccount : bankingAccounts){
            auto mainInformations = make_pair(bankingAccount.second.getIban(),bankingAccount.second.getDeposit());
            cout << bankingAccount.first << ") IBAN: " << mainInformations.first << ", total deposit: "
                << mainInformations.second << endl;
        }
    }
    cout << "Enter the corresponding number to see further details, (0) to go back: " << endl;
    manageInput(getStringInput());
}

bool BankingAccountsManagerView::isCorrectInput(const string &input) {
    bool correct = true;
    if (input == BACK) {
        setGoBack(true);
    }
    else {
        auto it = bankingAccounts.find(input);
        if (it != bankingAccounts.end()){
            BankingAccountView bankingAccountView(&it->second);
            bankingAccountView.displayUserInterface();
        }
        else
            correct = false;
    }
    updateServer();

    return correct;
}

void BankingAccountsManagerView::pullFromServer() {
    ifstream iFile("../server/" + clientName + "/banking_accounts.txt");
    text_iarchive ia(iFile);
    ia >> *this;
    iFile.close();
}

void BankingAccountsManagerView::updateServer() const {
    cout << "Updating server... " << endl;
    ofstream oFile("../server/" + clientName + "/banking_accounts.txt");
    text_oarchive oa(oFile);
    oa << *this;
    oFile.close();
}
