//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_CHARGECARDVIEW_H
#define MOBILE_BANKING_APP_CHARGECARDVIEW_H

#include <list>

#include "../general_purpose_classes/InputManager.h"
#include "ChargeCard.h"

class ChargeCardView : public InputManager {
public:

    virtual ~ChargeCardView() = default;

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    list<ChargeCard> chargeCards;
};


#endif //MOBILE_BANKING_APP_CHARGECARDVIEW_H
