//
// Created by rebecca on 11/21/20.
//

#include "BankingAccountsManagerView.h"

#include <iostream>
#include <fstream>

#include "../general_purpose_classes/utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

const string BankingAccountsManagerView::BACK = "0";

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
        updateServer();
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

    return correct;
}

void BankingAccountsManagerView::pullFromServer() {
    ifstream iFile("../server/" + clientName + "/banking_accounts");
    text_iarchive ia(iFile);
    ia >> *this;
    iFile.close();
}

void BankingAccountsManagerView::setClientName(const string &cname) {
    clientName = cname;
}

void BankingAccountsManagerView::updateServer() const {
    cout << "Updating server... " << endl;
    ofstream oFile("../server/" + clientName + "/banking_accounts");
    text_oarchive oa(oFile);
    oa << *this;
    oFile.close();
}
