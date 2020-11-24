//
// Created by rebecca on 10/19/20.
//

#include "WireTransfer.h"


void WireTransfer::setRecipient(string name, string IBAN) {
    recipient.first = move(name);
    recipient.second = move(IBAN);
}

template<typename Archive>
void WireTransfer::serialize(Archive &ar, const unsigned int version) {
    ar & boost::serialization::base_object<Transaction>(*this);
    ar & sender.first, ar & sender.second;
    ar & recipient.first, ar & recipient.second;
    ar & reasonOfPayment;
}

BOOST_CLASS_EXPORT_GUID(WireTransfer, "WireTransfer"); //controllare che polimorfismo funzioni TODO

