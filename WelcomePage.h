//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_WELCOMEPAGE_H
#define MOBILE_BANKING_APP_WELCOMEPAGE_H

#include "AccessManager.h"

#include <string>

using namespace std;

class WelcomePage {
public:
    void displayScreen();

private:
    void manageInput();
    bool isCorrectInput();

    static void exit();

    AccessManager accessManager;
};

#endif //MOBILE_BANKING_APP_WELCOMEPAGE_H
