//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_CHARGECARDMANAGERVIEW_H
#define MOBILE_BANKING_APP_CHARGECARDMANAGERVIEW_H

#include <string>
#include <map>

#include "../general_purpose_classes/InputManager.h"
#include "ChargeCard.h"
#include "ChargeCardView.h"

using namespace std;

class ChargeCardManagerView : public InputManager {
public:
    explicit ChargeCardManagerView(map<string,ChargeCard>* cards) : chargeCards{cards} {}

    ~ChargeCardManagerView() override = default;

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    //attribute
    map<string,ChargeCard>* chargeCards{nullptr};
};


#endif //MOBILE_BANKING_APP_CHARGECARDMANAGERVIEW_H
