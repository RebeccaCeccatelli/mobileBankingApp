//
// Created by rebecca on 10/19/20.
//

#include "PhoneRecharge.h"

#include <fstream>

void PhoneRecharge::setRecipient(string mobOperator, string num) {
    mobileOperator = move(mobOperator);
    telephoneNumber = move(num);
}

void PhoneRecharge::serializeInReadableFormat(const string &pathInfo) const {
    string path = "../saved_files/" + pathInfo + "/transactions/p_recharge" + getDate();

    ofstream oFile(path);
    oFile << "*** Phone recharge ***" << "\n\n- Amount: " << getAmount() << "\n- Mobile operator: " << mobileOperator
        << "\n- Telephone number: " << telephoneNumber << "\n- Made on: " << getDate();
    oFile.close();
}

