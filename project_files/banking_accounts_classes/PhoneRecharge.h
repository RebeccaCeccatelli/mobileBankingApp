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

#include "Transaction.h"

using namespace std;
using namespace boost::archive;

class PhoneRecharge : public Transaction {
public:
    explicit PhoneRecharge(tuple<string,string,int> userInformations) :
        Transaction(get<2>(userInformations), "phone recharge", "telephony") {

        setRecipient(get<0>(userInformations),get<1>(userInformations));
    }

    PhoneRecharge() = default;

    pair<string,string> getRecipient() const;

    void serializeInReadableFormat(const string& pathInfo) const;
private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & boost::serialization::base_object<Transaction>(*this);
        ar & mobileOperator;
        ar & telephoneNumber;
    }

    void setRecipient(string mobOperator, string num);

    //attributes
    string mobileOperator;
    string telephoneNumber;
};


#endif //MOBILE_BANKING_APP_PHONERECHARGE_H
