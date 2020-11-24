//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_PHONERECHARGE_H
#define MOBILE_BANKING_APP_PHONERECHARGE_H

#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>

#include "Transaction.h"

using namespace std;
using namespace boost::archive;

class PhoneRecharge : public Transaction {
public:
    void setRecipient(string mobOperator, string num);

private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    string mobileOperator;
    string telephoneNumber;
};


#endif //MOBILE_BANKING_APP_PHONERECHARGE_H
