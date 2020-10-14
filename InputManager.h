//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_INPUTMANAGER_H
#define MOBILE_BANKING_APP_INPUTMANAGER_H

#include <string>

using namespace std;

class InputManager {
protected:
    void manageInput(string input = "");

    virtual bool isCorrectInput(string input) = 0;
    virtual void tryAgain() = 0;
    virtual void enableFailureRoutine() = 0;

private:
    int attempts{1};
};

#endif //MOBILE_BANKING_APP_INPUTMANAGER_H
