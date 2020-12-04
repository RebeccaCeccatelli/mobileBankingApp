//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_SMARTLOCKVIEW_H
#define MOBILE_BANKING_APP_SMARTLOCKVIEW_H

#include <string>

#include "../general_purpose_classes/InputManager.h"
#include "SmartLock.h"

using namespace std;

class SmartLockView : public InputManager {
public:
    SmartLockView(SmartLock *smart, const string &titCode) : smartLock{smart}, titolarCode{titCode} {}
    virtual ~SmartLockView() = default;

    bool wantToRemember();

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    //SmartLockView DOES NOT own this object
   SmartLock* smartLock;

   string titolarCode;
};

#endif //MOBILE_BANKING_APP_SMARTLOCKVIEW_H
