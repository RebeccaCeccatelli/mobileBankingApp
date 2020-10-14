//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_WELCOMEPAGE_H
#define MOBILE_BANKING_APP_WELCOMEPAGE_H

#include <string>
#include "gtest/gtest.h"

#include "AccessManager.h"
#include "InputManager.h"
#include "Interface.h"

using namespace std;

class WelcomePage : public InputManager, public Interface {
    FRIEND_TEST(WelcomePageSuite, isCorrectInputTest);

private:
    void display() override;

    bool isCorrectInput(string input) override;
    void tryAgain() override;
    void enableFailureRoutine() override;

    static void exit();

    AccessManager accessManager;
};

#endif //MOBILE_BANKING_APP_WELCOMEPAGE_H
