//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_PHONERECHARGE_H
#define MOBILE_BANKING_APP_PHONERECHARGE_H

#include <string>

#include "Transaction.h"

using namespace std;

class PhoneRecharge : public Transaction {
public:

    void setRecipient(string mobOperator, string num);
private:
    string mobileOperator;
    string telephoneNumber;
};


#endif //MOBILE_BANKING_APP_PHONERECHARGE_H
