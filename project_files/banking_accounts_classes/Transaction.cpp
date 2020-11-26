//
// Created by rebecca on 10/19/20.
//

#include "Transaction.h"

using namespace std;


void Transaction::setAmount(int amount) {
    amountToTransfer = amount;
}

const string &Transaction::getDate() const {
    return dateSetter.getDate();
}


