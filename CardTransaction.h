//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_CARDTRANSACTION_H
#define MOBILE_BANKING_APP_CARDTRANSACTION_H

#include "Transaction.h"

class CardTransaction : public Transaction {
public:
    void display() override;

    void setAmount(int amount) override;

    void setProcessed(bool rec) override;

    //...
private:
    string cardNumber;
    string tipology; //forse enum, withdrawal or payment
    string detectedLocation;
};


#endif //MOBILE_BANKING_APP_CARDTRANSACTION_H
