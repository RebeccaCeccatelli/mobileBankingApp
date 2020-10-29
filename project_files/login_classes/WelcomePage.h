//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_WELCOMEPAGE_H
#define MOBILE_BANKING_APP_WELCOMEPAGE_H

#include <string>

#include "AccessManagerView.h"
#include "../general_purpose_classes/InputManager.h"

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

    static const string LOGIN;
    static const string EXIT;
};

#endif //MOBILE_BANKING_APP_WELCOMEPAGE_H
