//
// Created by rebecca on 10/19/20.
//

#include "WireTransfer.h"

void WireTransfer::setRecipient(string name, string IBAN) {
    recipient.first = move(name);
    recipient.second = move(IBAN);
}

void WireTransfer::setSender(string name, string IBAN) {
    sender.first = move(name);
    sender.second = move(IBAN);
}

BOOST_CLASS_EXPORT_GUID(WireTransfer, "WireTransfer"); //controllare che polimorfismo funzioni TODO

