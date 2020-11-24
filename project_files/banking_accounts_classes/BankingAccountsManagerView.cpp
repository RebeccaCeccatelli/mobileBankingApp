//
// Created by rebecca on 11/21/20.
//

#include "BankingAccountsManagerView.h"

#include <iostream>

#include "../general_purpose_classes/utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

const string BankingAccountsManagerView::BACK = "0";

template<typename Archive>
void BankingAccountsManagerView::serialize(Archive &ar, const unsigned int version) {
    ar & bankingAccounts;
}

void BankingAccountsManagerView::display() {
    cout << endl << "*** This is the list of your banking accounts. ***" << endl;
    if (bankingAccounts.empty())
        cout << "Empty. " << endl;
    else {
        for (const auto& bankingAccount : bankingAccounts){
            auto mainInformations = bankingAccount.second.getMainInformations();
            cout << bankingAccount.first << ") IBAN: " << mainInformations.first << ", total deposit: "
                << mainInformations.second << endl;
        }
    }
    cout << "Enter the corresponding number to see further details, (0) to go back: " << endl;
    manageInput(getStringInput());
}

bool BankingAccountsManagerView::isCorrectInput(const string &input) {
    bool correct = true;
    if (input == BACK)
        setGoBack(true);
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
