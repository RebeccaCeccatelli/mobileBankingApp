//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_UTILITYFUNCTIONS_H
#define MOBILE_BANKING_APP_UTILITYFUNCTIONS_H

#include <string>

#include "InputManager.h"

using namespace std;

namespace utilityFunctions {
    //constants
    const string YES = "yes";
    const string NO = "no";
    const string LOGIN = "login";
    const string EXIT = "exit";

    //input methods
    string getStringInput();
    unsigned int getNumInput();
    string getLineInput();
}

#endif //MOBILE_BANKING_APP_UTILITYFUNCTIONS_H
