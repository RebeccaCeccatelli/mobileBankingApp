//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_PROFILEMANAGERVIEW_H
#define MOBILE_BANKING_APP_PROFILEMANAGERVIEW_H

#include <string>

#include "../general_purpose_classes/InputManager.h"
#include "ProfileView.h"
#include "SecurityManagerView.h"
#include "BankBranchView.h"

using namespace std;

class ProfileManagerView : public InputManager {
public:
    virtual ~ProfileManagerView() = default;

    void setClientName(const string& cname);

private:
    void pullFromServer();
    void updateServer();

    void display() override;
    bool isCorrectInput(const string &input) override;

    //attributes
    ProfileView profileView;
    BankBranchView bankBranch;
    SecurityManagerView securityManagerView;

    string clientName;
    bool first{true};    //rendere più chiaro l'uso di questo booleano FIXME

    //class constants
    static const string PROFILE;
    static const string SECURITY_SETTINGS;
    static const string BANK_BRANCH;
    static const string BACK;
};


#endif //MOBILE_BANKING_APP_PROFILEMANAGERVIEW_H
