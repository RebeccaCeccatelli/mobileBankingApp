//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_WIRETRANSFER_H
#define MOBILE_BANKING_APP_WIRETRANSFER_H

#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/base_object.hpp>

#include "Transaction.h"

using namespace std;
using namespace boost::archive;

class WireTransfer : public Transaction {
public:
    void setRecipient (string name, string IBAN);
    //getMaximum amount...

private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    pair <string,string> sender;
    pair <string,string> recipient;
    string reasonOfPayment;
};


#endif //MOBILE_BANKING_APP_WIRETRANSFER_H
