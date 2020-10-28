//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_WELCOMEPAGE_H
#define MOBILE_BANKING_APP_WELCOMEPAGE_H

#include <string>

#include "AccessManagerView.h"
#include "InputManager.h"

using namespace std;

class WelcomePage : public InputManager {
public:
    virtual ~WelcomePage() = default;

private:
    void display() override;

    bool isCorrectInput(const string &input) override;
    void enableFailureRoutine() override;

    static void exit();

    AccessManagerView accessManagerView;
};

#endif //MOBILE_BANKING_APP_WELCOMEPAGE_H
