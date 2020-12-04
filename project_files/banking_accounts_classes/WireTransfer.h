//
// Created by rebecca on 10/19/20.
//

#ifndef MOBILE_BANKING_APP_WIRETRANSFER_H
#define MOBILE_BANKING_APP_WIRETRANSFER_H

#include <string>
#include <boost/serialization/string.hpp>
#include <boost/serialization/base_object.hpp>

#include "Transaction.h"

using namespace std;
using namespace boost::archive;

class WireTransfer : public Transaction {
public:
    explicit WireTransfer(int amount) :
        Transaction(amount, "wire transfer") {}
    WireTransfer() = default;

    void setSender(string name, string IBAN);
    void setRecipient (string name, string IBAN);
    void setReasonOfPayment(string reason);

    const pair<string,string>& getSender() const;
    const pair<string,string>& getRecipient() const;
    const string& getReasonOfPayment() const;

    void serializeInReadableFormat(const string &cname) const;

private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & boost::serialization::base_object<Transaction>(*this);

        ar & sender.first, ar & sender.second;
        ar & recipient.first, ar & recipient.second;
        ar & reasonOfPayment;
    }

    //attributes
    pair <string,string> sender{"",""};
    pair <string,string> recipient{"",""};
    string reasonOfPayment;
};

#endif //MOBILE_BANKING_APP_WIRETRANSFER_H
