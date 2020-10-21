//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_WELCOMEPAGE_H
#define MOBILE_BANKING_APP_WELCOMEPAGE_H

#include <string>
//#include "gtest/gtest.h"

#include "AccessManager.h"
#include "InputManager.h"

using namespace std;

class WelcomePage : public InputManager {
    //FRIEND_TEST(WelcomePageSuite, isCorrectInputTest);

    void display() override;

    bool isCorrectInput(const string &input) override;
    void enableFailureRoutine() override;

    static void exit();

    AccessManager accessManager;
};

#endif //MOBILE_BANKING_APP_WELCOMEPAGE_H
