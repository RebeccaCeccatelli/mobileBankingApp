//
// Created by rebecca on 10/19/20.
//

#include "Transaction.h"

using namespace std;

int Transaction::getAmount() const {
    return amountToTransfer;
}

const string &Transaction::getDate() const {
    return dateSetter.getDate();
}

const string &Transaction::getDescription() const {
    return description;
}

const string &Transaction::getCategory() const {
    return category;
}

bool Transaction::isProcessed() const {
    return processed;
}

bool Transaction::isSpecificDate(const string &filter) const {
    if (filter == dateSetter.getDate().substr(0,8))
        return true;
    else
        return false;
}

bool Transaction::isSpecificCategory(const string &filter) const {
    if (filter == category)
        return true;
    else
        return false;
}
