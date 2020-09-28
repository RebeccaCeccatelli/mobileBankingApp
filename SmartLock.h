//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_SMARTLOCK_H
#define MOBILE_BANKING_APP_SMARTLOCK_H

#include "InputManager.h"

#include <string>

using namespace std;

class SmartLock : public InputManager {
public:
    bool wantToRemember();

    const unsigned int getTitolarCode() const;
    void setTitolarCode();

    const string& getName() const;

    void reset();

protected:
    bool isCorrectInput() override;
    void tryAgain() override;
    void enableFailureRoutine() override;

private:
    void setClientNickname();
    void setRemembered(bool rem);

    unsigned int titolarCode{0};
    string clientNickname;

    bool remembered{false};
};

#endif //MOBILE_BANKING_APP_SMARTLOCK_H
