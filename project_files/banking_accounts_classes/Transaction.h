//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_TRANSACTION_H
#define MOBILE_BANKING_APP_TRANSACTION_H

#include <string>
#include <boost/serialization/string.hpp>

#include "../general_purpose_classes/DateSetter.h"

using namespace std;
using namespace boost::archive;

class Transaction {
public:
    explicit Transaction(int amount,string descr = "not specified", string cat = "general",
        bool p = false) : amountToTransfer{amount}, category{move(cat)}, description{move(descr)},
        processed{p} {
        dateSetter.setDate();
    }
    Transaction() = default;
    virtual ~Transaction() = default;

    int getAmount() const;
    const string& getDate() const;
    const string& getDescription() const;
    const string& getCategory() const;
    bool isProcessed() const;

    bool isSpecificDate(const string& filter) const;
    bool isSpecificCategory(const string& filter) const;

private:
    friend class boost::serialization::access;
    template<typename Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & category;
        ar & description;
        ar & processed;
        ar & amountToTransfer;
        ar & dateSetter;
    }

    //attributes
    int amountToTransfer;
    string category;
    string description;
    bool processed;

    DateSetter dateSetter;
};


#endif //MOBILE_BANKING_APP_TRANSACTION_H
