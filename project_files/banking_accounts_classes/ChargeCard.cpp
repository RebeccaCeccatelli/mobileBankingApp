//
// Created by rebecca on 11/21/20.
//

#include "ChargeCard.h"

const int ChargeCard::MAX_LIMIT = 10.000;

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

const string &ChargeCard::getLatestTransaction() const {
    return relatedCardTransactions.crbegin()->first;
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
