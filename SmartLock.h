//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_SMARTLOCK_H
#define MOBILE_BANKING_APP_SMARTLOCK_H

#include "InputManager.h"

class SmartLock : public InputManager {
public:
    void wantToRemember();

protected:
    bool isCorrectInput() override;

    void tryAgain() override;

    void enableFailureRoutine() override;

private:
    bool remembered{false};
    bool firstLogin{true};
};

#endif //MOBILE_BANKING_APP_SMARTLOCK_H
