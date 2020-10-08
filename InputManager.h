//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_INPUTMANAGER_H
#define MOBILE_BANKING_APP_INPUTMANAGER_H

class InputManager {
protected:
    void manageInput();

    virtual bool isCorrectInput() = 0;
    virtual void tryAgain() = 0;
    virtual void enableFailureRoutine() = 0;

private:
    int attempts{1};
};

#endif //MOBILE_BANKING_APP_INPUTMANAGER_H
