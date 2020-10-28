//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_PROFILEMANAGERVIEW_H
#define MOBILE_BANKING_APP_PROFILEMANAGERVIEW_H

#include <string>

#include "InputManager.h"
#include "ProfileView.h"
#include "SecurityManagerView.h"
#include "BankBranch.h"

using namespace std;

class ProfileManagerView : public InputManager {
public:
    void setClientName(const string& cname);

private:
    void pullFromServer();
    void updateServer();

    void display() override;

    bool isCorrectInput(const string &input) override;

    //attributes
    ProfileView profileView;
    BankBranch bankBranch;
    SecurityManagerView securityManagerView;

    string clientName;
    bool first{true};    //rendere più chiaro l'uso di questo booleano FIXME
};


#endif //MOBILE_BANKING_APP_PROFILEMANAGERVIEW_H
