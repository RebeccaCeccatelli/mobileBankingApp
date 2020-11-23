//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_TRANSACTION_H
#define MOBILE_BANKING_APP_TRANSACTION_H

#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

#include "../general_purpose_classes/DateSetter.h"

using namespace std;
using namespace boost::archive;

class Transaction {
public:
    Transaction() {
        dateSetter.setDate();
    }
    virtual ~Transaction() = default;

    virtual void setAmount(int amount);

private:
    friend class boost::serialization::access;


    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    string category{"general"};
    string description{"not specified"};
    bool processed{false};
    int amountToTransfer;

    DateSetter dateSetter;
};


#endif //MOBILE_BANKING_APP_TRANSACTION_H
