//
// Created by rebecca on 10/19/20.
//

#include "CardTransaction.h"

const string &CardTransaction::getCardNumber() const {
    return cardNumber;
}

const string &CardTransaction::getLocation() const {
    return detectedLocation;
}

string CardTransaction::getCategorization() const {
    string cat;
    if (categorization == Categorization::withdrawal)
        cat = "withdrawal ";
    else
        cat = "payment";
    return cat;
}
