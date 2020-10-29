//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_ACCESSMANAGERVIEW_H
#define MOBILE_BANKING_APP_ACCESSMANAGERVIEW_H

#include <string>
#include <list>

#include "Account.h"
#include "AccountsManagerView.h"
#include "SmartLockView.h"
#include "../general_purpose_classes/InputManager.h"
#include "AccessManager.h"

using namespace std;

class AccessManagerView : public InputManager {
public:
    AccessManagerView();
    virtual ~AccessManagerView() = default;

    const string &getName() const;
    void login();

private:
    bool isCorrectInput(const string &input) override;
    void enableFailureRoutine() override;
    void display() override;

    //helper method
    string obtainTitolarCode();

    //attributes
    AccessManager accessManager;
    SmartLock smartLock;
};

#endif //MOBILE_BANKING_APP_ACCESSMANAGERVIEW_H
