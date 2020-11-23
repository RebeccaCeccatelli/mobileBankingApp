//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_WIRETRANSFER_H
#define MOBILE_BANKING_APP_WIRETRANSFER_H

#include <string>

#include "Transaction.h"

using namespace std;

class WireTransfer : public Transaction {
public:
    void setRecipient (string name, string IBAN);
    //getMaximum amount...

private:
    pair <string,string> sender;
    pair <string,string> recipient;
    string reasonOfPayment;
};


#endif //MOBILE_BANKING_APP_WIRETRANSFER_H
