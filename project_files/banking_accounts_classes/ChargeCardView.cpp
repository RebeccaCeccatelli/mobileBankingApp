//
// Created by rebecca on 11/25/20.
//

#include "ChargeCardView.h"

#include <iostream>
#include "../general_purpose_classes/utilityFunctions.h"

using namespace utilityFunctions;

const string ChargeCardView::BACK = "0";
const string ChargeCardView::INFOS = "1";
const string ChargeCardView::TRANSACTIONS = "2";
const string ChargeCardView::LIMIT = "3";
const string ChargeCardView::STATE = "4";

void ChargeCardView::display() {
    cout << endl << "*** Card number: " << chargeCard->getNumberAndType().first
        << ". What would you like to do? ***" << endl;
    cout << "1) Card's detailed informations. " << endl << "2) List of associated transactions. " << endl
    << "3) Modify maximum monthly limit. " << endl << "4) Activate/Deactivate card. " << endl << "0) Go back. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;
    manageInput(getStringInput());
}

bool ChargeCardView::isCorrectInput(const string &input) {
    bool correct = true;
    if (input == BACK)
        setGoBack(true);
    else if (input == INFOS) {
        displayDetailedInformations();
    }
    else if (input == TRANSACTIONS) {
        displayTransactions();
    }
    else if (input == LIMIT) {
        modifyMaximumLimit();
    }
    else if (input == STATE){
        changeCardState();
    }
    else
        correct = false;

    return correct;
}

void ChargeCardView::displayDetailedInformations() const {
    auto NumberAndType = chargeCard->getNumberAndType();

    cout << endl << "*** Detailed informations. *** " << endl;
    cout << "- Number: " << NumberAndType.first << endl << "- Type: ";
    if (NumberAndType.second == CardType::debit)
        cout << "debit " << endl;
    else
        cout << "credit " << endl;
    cout << "- Monthly limit: " << chargeCard->getLimits().first << endl << "- State: ";
    if (chargeCard->isActive())
        cout << "active " << endl;
    else
        cout << "deactivated " << endl;
}

void ChargeCardView::displayTransactions() const {
//todo
}

void ChargeCardView::modifyMaximumLimit() {
    cout << "Your actual limit: " << chargeCard->getLimits().first << ". Maximum acceptable limit: " <<
    chargeCard->getLimits().second << "." << endl;
    cout << "Set your new limit: ";
    if(chargeCard->setLimit(getNumInput()))
        cout << "New limit setted. " << endl;
    else
        cout << "You cannot set a limit bigger than the acceptable one. Not setted." << endl;
}

void ChargeCardView::changeCardState() {
    if(chargeCard->isActive())
        cout << "Card deactived. " << endl;
    else
        cout << "Card activated. " << endl;

    chargeCard->changeState();
}
