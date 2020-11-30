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
const string ChargeCardView::SORT_BY_DATE = "sd";
const string ChargeCardView::FILTER_DATE = "fd";
const string ChargeCardView::FILTER_CATEGORY = "fc";
const string ChargeCardView::YES = "yes";
const string ChargeCardView::NO = "no";

void ChargeCardView::display() {
    cout << endl << "*** Card number: " << chargeCard->getNumberAndType().first
        << ". ***" << endl << "What would you like to do?" << endl;
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
    auto numberAndType = chargeCard->getNumberAndType();
    auto bankingAccount = chargeCard->getAssociatedBankingAccount();
    cout << endl << "*** Detailed informations. *** " << endl;
    cout << "- Number: " << numberAndType.first << endl << "- Type: ";
    if (numberAndType.second == CardType::debit)
        cout << "debit " << endl;
    else
        cout << "credit " << endl;
    cout << "- Associated banking account: " << bankingAccount.first << ", " << bankingAccount.second << endl;
    cout << "- Latest transaction made on: " << chargeCard->getLatestTransaction() << endl;
    cout << "- Monthly limit: " << chargeCard->getLimits().first << endl << "- State: ";
    if (chargeCard->isActive())
        cout << "active " << endl;
    else
        cout << "deactivated " << endl;

    if(wantToSaveAsFile()){
        chargeCard->serializeInReadableFormat();
        cout << "Saved. " << endl;
    }
}

void ChargeCardView::displayTransactions() const {
    string input = decideSortingLogic();

    if (input == BACK){
        return;
    }
    else if (input == SORT_BY_DATE){
        auto list = chargeCard->returnSelected(RequestedTransactions::all);
        showList(list);
    }
    else if (input == FILTER_DATE){
        auto list = chargeCard->returnSelected(RequestedTransactions::specificDate, insertFilter(input));
       showList(list);
    }
    else if (input == FILTER_CATEGORY) {
        auto list = chargeCard->returnSelected(RequestedTransactions::specificCategory,insertFilter(input));
        showList(list);
    }
    else{
        cout << "Your input is not correct. Try again. " << endl;
        displayTransactions();
    }
}

void ChargeCardView::showList(const vector<const CardTransaction *> &selectedTransactions) {
    if (selectedTransactions.empty())
        cout << "The list is empty. " << endl;
    else {
        for (auto cardTransaction : selectedTransactions)
            showSpecificTransaction(cardTransaction);
    }
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

void ChargeCardView::showSpecificTransaction(const CardTransaction *cardTransaction){
    cout << "- Amount: " << cardTransaction->getAmount() << " euros || ";
    if (cardTransaction->categorization == Categorization::payment)
        cout << "Payment || ";
    else
        cout << "Withdrawal || ";
    cout << "Time: " << cardTransaction->getDate() << ", Place: "
        << cardTransaction->detectedLocation << " || " << cardTransaction->getCategory() << " || ";
    if (cardTransaction->isProcessed())
        cout << " processed " << endl;
    else
        cout << "still not processed " << endl;
}

string ChargeCardView::insertFilter(const string& request) {
    if (request == FILTER_DATE)
        cout << "Please, insert a specific date in format mm/dd/yy: " << endl;
    else if (request == FILTER_CATEGORY)
        cout << "Please, insert a category between '...', '...': " << endl; //inserire categorie alla fine FIXME
    auto filter = getStringInput();

    return filter;
}

string ChargeCardView::decideSortingLogic() {
    cout << endl << "- Sort all by date (sd). "  << endl << "- Filter by requested date (fd). " << endl <<
         "- Filter by category (fc). " << endl << "- Go back (0). " << endl;
    string input = getStringInput();

    return input;
}

bool ChargeCardView::wantToSaveAsFile() {
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
