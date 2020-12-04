//
// Created by rebecca on 10/19/20.
//

#include "WireTransfer.h"

#include <fstream>
#include <algorithm>

void WireTransfer::setSender(string name, string IBAN) {
    sender.first = move(name);
    sender.second = move(IBAN);
}

void WireTransfer::setRecipient(string name, string IBAN) {
    recipient.first = move(name);
    recipient.second = move(IBAN);
}

void WireTransfer::setReasonOfPayment(string reason) {
    reasonOfPayment = move(reason);
}

const pair<string, string> &WireTransfer::getSender() const {
    return sender;
}

const pair<string, string> &WireTransfer::getRecipient() const {
    return recipient;
}

const string &WireTransfer::getReasonOfPayment() const {
    return reasonOfPayment;
}

void WireTransfer::serializeInReadableFormat(const string &cname) const {
    string date = getDate();
    replace(date.begin(),date.end(),*" ",*"_");
    auto newEnd = remove_if(date.begin(),date.end(),[](char c){return (c == '/'|| c == ':');});
    date.erase(newEnd,date.end());

    string path = "../saved_files/" + cname + "/banking_accounts/b_account" + sender.second
            + "/transactions/w_transfer" + date;

    ofstream oFile(path);
    oFile << "*** Wire transfer *** " << "\n\n- Amount: " << getAmount() << "\n- Sender: " << sender.first
        << ", " << sender.second << "\n- Recipient: " << recipient.first << ", " << recipient.second
        << "\n- Reason of payment: " << reasonOfPayment << "\n- Date: " << getDate();
    oFile.close();
}
