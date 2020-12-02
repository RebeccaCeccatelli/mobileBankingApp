//
// Created by rebecca on 11/21/20.
//

#include "ChargeCard.h"

#include <fstream>

const int ChargeCard::MAX_LIMIT = 10000;

pair<string, CardType> ChargeCard::getNumberAndType() const {
    return make_pair(cardNumber,cardType);
}

bool ChargeCard::isActive() const {
    return active;
}

pair<int, int> ChargeCard::getLimits() const {
    return make_pair(monthlyLimit,MAX_LIMIT);
}

bool ChargeCard::setLimit(int newLimit) {
    bool acceptable = false;

    if(newLimit <= MAX_LIMIT){
        monthlyLimit = newLimit;
        acceptable = true;
    }
    return acceptable;
}

void ChargeCard::changeState() {
    active = !active;
}

string ChargeCard::getLatestTransaction() const {
    string latestTransaction;
    if (!relatedCardTransactions.empty())
        latestTransaction = relatedCardTransactions.crbegin()->first;
    else
        latestTransaction = "no transactions";
    return latestTransaction;
}

vector<const CardTransaction *> ChargeCard::returnSelected(RequestedTransactions request, const string& filter) {
    vector<const CardTransaction*> list;

    for (const auto& transaction : relatedCardTransactions){
        if (request == RequestedTransactions::all)
            list.push_back(&transaction.second);
        else if (request == RequestedTransactions::specificDate){
            if (transaction.second.isSpecificDate(filter))
                list.push_back(&transaction.second);
        }
        else if (request == RequestedTransactions::specificCategory){
            if (transaction.second.isSpecificCategory(filter))
                list.push_back(&transaction.second);
        }
    }

    return list;
}

pair<string, string> ChargeCard::getAssociatedBankingAccount() const {
    return associatedBankingAccount;
}

void ChargeCard::serializeInReadableFormat() const {
    string path = "../saved_files/" + associatedBankingAccount.first + "/banking_accounts/b_account"
        + associatedBankingAccount.second + "charge_cards/info_card" + cardNumber;
    fstream oFile(path);

    oFile << "- Card number: " << cardNumber << "\n- Type: ";
    if(cardType == CardType::debit)
        oFile << "debit";
    else
        oFile << "credit";
    oFile << "\n- Associated banking account: " << associatedBankingAccount.first << ", " << associatedBankingAccount.second;
    oFile << "\n- Latest transaction made on: " << relatedCardTransactions.crbegin()->first << "\n- Monthly limit: "
        << monthlyLimit << "\n- State: ";
    if (active)
        oFile << "active";
    else
        oFile << "deactived";
    oFile.close();
}
