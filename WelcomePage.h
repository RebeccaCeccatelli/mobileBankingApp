//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_WELCOMEPAGE_H
#define MOBILE_BANKING_APP_WELCOMEPAGE_H

#include "AccessManager.h"
#include "InputManager.h"
#include <string>

using namespace std;

class WelcomePage : InputManager {
public:
    void displayScreen();

private:
    bool isCorrectInput() override;

    void tryAgain() override;

    void enableFailureRoutine() override;

    static void exit();

    AccessManager accessManager;
};

#endif //MOBILE_BANKING_APP_WELCOMEPAGE_H
