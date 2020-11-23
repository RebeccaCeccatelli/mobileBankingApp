//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_CARDTRANSACTION_H
#define MOBILE_BANKING_APP_CARDTRANSACTION_H

#include "Transaction.h"

enum class Categorization {
    withdrawal,
    payment
};

class CardTransaction : public Transaction {
public:

private:
    string cardNumber;
    string detectedLocation;
    Categorization categorization;
};


#endif //MOBILE_BANKING_APP_CARDTRANSACTION_H
