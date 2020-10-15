//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_PROFILE_H
#define MOBILE_BANKING_APP_PROFILE_H

#include <string>

#include "InputManager.h"
#include "Interface.h"

using namespace std;

class Profile : public InputManager, public Interface {
public:
    Profile(string name, string addr, string mail, string num, bool news);

    void serialize(const string &name) const;
    static Profile deserialize(const string& extractedPath);

private:
    void display() override;

    bool isCorrectInput(string input) override;
    void enableFailureRoutine() override;
    void tryAgain() override;

    void changeNewsletterSettings();

    string cname;
    string residentialAddress;
    string email;
    bool newsletter;
    string telephoneNumber;
};


#endif //MOBILE_BANKING_APP_PROFILE_H
