//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_TRANSACTION_H
#define MOBILE_BANKING_APP_TRANSACTION_H

#include <string>

#include "DateSetter.h"

using namespace std;

class Transaction : public DateSetter {
public:
    virtual void display() = 0;
    virtual void setAmount(int amount) = 0;
    virtual void setProcessed(bool rec) = 0;

private:
    string particular;
    string category{"general"};
    string description{"unknown"};
    bool processed{false};
    int amountToTransfer;
};


#endif //MOBILE_BANKING_APP_TRANSACTION_H
