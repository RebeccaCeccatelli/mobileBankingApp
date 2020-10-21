//
// Created by rebecca on 10/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKBRANCH_H
#define MOBILE_BANKING_APP_BANKBRANCH_H

#include <string>

using namespace std;

class BankBranch {
public:
    BankBranch() = default;
    BankBranch(string addr, string manager, string num) : address{move(addr)}, assignedManager{move(manager)},
        telephoneNumber{move(num)} {}

    static BankBranch deserialize(const string& exctractedPath);

    void display();

private:
    string address;
    string assignedManager;
    string telephoneNumber;
};


#endif //MOBILE_BANKING_APP_BANKBRANCH_H
