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
    SmartLock() = default;
    SmartLock(unsigned int titCode, string cname, bool r) : titolarCode{titCode}, clientNickname{move(cname)},
        remembered{r} {}

    bool wantToRemember();

    const unsigned int getTitolarCode() const;
    void setTitolarCode();

    const string& getNickname() const;

    void reset();

    static SmartLock deserialize();

protected:
    bool isCorrectInput() override;
    void tryAgain() override;
    void enableFailureRoutine() override;

private:
    void setClientNickname();
    void setRemembered(bool rem);

    void serialize() const;

    unsigned int titolarCode{0};
    string clientNickname{"client"};

    bool remembered{false};
};

#endif //MOBILE_BANKING_APP_SMARTLOCK_H
