//
// Created by rebecca on 10/19/20.
//

#include "PhoneRecharge.h"

#include <fstream>
#include <algorithm>

pair<string, string> PhoneRecharge::getRecipient() const {
    return make_pair(mobileOperator,telephoneNumber);
}

void PhoneRecharge::serializeInReadableFormat(const string &pathInfo) const {
    string date = getDate();
    replace(date.begin(),date.end(),*" ",*"_");
    auto newEnd = remove_if(date.begin(),date.end(),[](char c){return (c == '/'|| c == ':');});
    date.erase(newEnd,date.end());

    string path = "../saved_files/" + pathInfo + "/transactions/p_recharge" + date;

    ofstream oFile(path);
    oFile << "*** Phone recharge ***" << "\n\n- Amount: " << getAmount() << "\n- Mobile operator: " << mobileOperator
        << "\n- Telephone number: " << telephoneNumber << "\n- Made on: " << getDate();
    oFile.close();
}

void PhoneRecharge::setRecipient(string mobOperator, string num) {
    mobileOperator = move(mobOperator);
    telephoneNumber = move(num);
}
