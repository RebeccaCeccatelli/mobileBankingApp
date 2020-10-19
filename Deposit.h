//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_DEPOSIT_H
#define MOBILE_BANKING_APP_DEPOSIT_H

#include "Transaction.h"

class Deposit : public Transaction {
public:
    void display() override;

    void setAmount(int amount) override;

    void setProcessed(bool rec) override;
};


#endif //MOBILE_BANKING_APP_DEPOSIT_H
