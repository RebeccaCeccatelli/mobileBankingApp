//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_ACCOUNTSMANAGERVIEW_H
#define MOBILE_BANKING_APP_ACCOUNTSMANAGERVIEW_H

#include "../InputManager.h"

class AccountsManagerView : public InputManager {
public:
    virtual ~AccountsManagerView() = default;
    bool wantToSwitchAccount();

private:
    bool isCorrectInput(const string &input) override;
    void enableFailureRoutine() override;
    void display() override;

    bool answer{false};
};

#endif //MOBILE_BANKING_APP_ACCOUNTSMANAGERVIEW_H
