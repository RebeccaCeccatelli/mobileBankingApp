//
// Created by rebecca on 10/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKBRANCHVIEW_H
#define MOBILE_BANKING_APP_BANKBRANCHVIEW_H

#include <string>

using namespace std;

class BankBranchView {
public:
    BankBranchView() = default;
    BankBranchView(string addr, string manager, string num) : address{move(addr)}, assignedManager{move(manager)},
        telephoneNumber{move(num)} {}

    static BankBranchView deserialize(const string& exctractedPath);

    void display();

private:
    string address;
    string assignedManager;
    string telephoneNumber;
};


#endif //MOBILE_BANKING_APP_BANKBRANCHVIEW_H
