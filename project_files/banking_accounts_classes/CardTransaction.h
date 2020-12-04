//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_CARDTRANSACTION_H
#define MOBILE_BANKING_APP_CARDTRANSACTION_H

#include <string>
#include <boost/serialization/string.hpp>
#include <boost/serialization/base_object.hpp>

#include "Transaction.h"

using namespace std;
using namespace boost::archive;

enum class Categorization {
    withdrawal,
    payment
};

class CardTransaction : public Transaction {
public:
    friend class ChargeCardView;

    const string& getCardNumber() const;
    const string& getLocation() const;
    string getCategorization() const;

private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & boost::serialization::base_object<Transaction>(*this);

        ar & cardNumber;
        ar & detectedLocation;
        ar & categorization;
    }

    //attributes
    string cardNumber;
    string detectedLocation;
    Categorization categorization;
};

#endif //MOBILE_BANKING_APP_CARDTRANSACTION_H
