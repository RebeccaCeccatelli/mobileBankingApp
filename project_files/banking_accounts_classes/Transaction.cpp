//
// Created by rebecca on 10/19/20.
//

#include "Transaction.h"

using namespace std;


void Transaction::setAmount(int amount) {
    amountToTransfer = amount;
}

template<typename Archive>
void Transaction::serialize(Archive &ar, const unsigned int version) {
    ar & category;
    ar & description;
    ar & processed;
    ar & amountToTransfer;
    ar & dateSetter;
}
