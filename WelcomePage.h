//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_WELCOMEPAGE_H
#define MOBILE_BANKING_APP_WELCOMEPAGE_H

#include <string>


#include "AccessManager.h"
#include "InputManager.h"
#include "Interface.h"

using namespace std;

class WelcomePage : public InputManager, public Interface {
private:
    void display() override;

    bool isCorrectInput() override;
    void tryAgain() override;
    void enableFailureRoutine() override;

    static void exit();

    AccessManager accessManager;
};

#endif //MOBILE_BANKING_APP_WELCOMEPAGE_H
