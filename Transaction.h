//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_TRANSACTION_H
#define MOBILE_BANKING_APP_TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
public:
    virtual void display() = 0;
    virtual void setAmount(int amount) = 0;
    virtual void setProcessed(bool rec) = 0;

    void setDate(char mode, string date);
    //...

private:
    string particular;
    pair<tm,string> date;
    string category{"general"};
    string description{"unknown"};
    bool processed{false};
    int amountToTransfer;

    string convertDateToString() const;

    tm convertDateToTm() const;
};


#endif //MOBILE_BANKING_APP_TRANSACTION_H
