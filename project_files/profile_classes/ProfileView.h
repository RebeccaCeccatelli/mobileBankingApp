//
// Created by rebecca on 10/15/20.
//

#ifndef MOBILE_BANKING_APP_PROFILEVIEW_H
#define MOBILE_BANKING_APP_PROFILEVIEW_H

#include <string>

#include "../InputManager.h"
#include "../Interface.h"
#include "Profile.h"

using namespace std;

class ProfileView : public InputManager {
public:
    virtual ~ProfileView() = default;

    void serialize(const string &name) const;
    ProfileView deserialize(const string& extractedPath);

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    //attribute
    Profile profile;
};


#endif //MOBILE_BANKING_APP_PROFILEVIEW_H
