//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_INPUTMANAGER_H
#define MOBILE_BANKING_APP_INPUTMANAGER_H

#include <string>

#include "Interface.h"

using namespace std;

class InputManager : public Interface {
public:
    virtual ~InputManager() = default;

protected:
    void manageInput(const string &input = "");

    virtual bool isCorrectInput(const string &input) = 0;
    virtual void tryAgain();
    virtual void enableFailureRoutine();

private:
    int attempts{1};

    //constant
    static const unsigned int MAX_ATTEMPTS;
};

#endif //MOBILE_BANKING_APP_INPUTMANAGER_H
