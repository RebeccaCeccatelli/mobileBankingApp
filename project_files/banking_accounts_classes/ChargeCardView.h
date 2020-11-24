//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_CHARGECARDVIEW_H
#define MOBILE_BANKING_APP_CHARGECARDVIEW_H

#include <list>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/list.hpp>

#include "../general_purpose_classes/InputManager.h"
#include "ChargeCard.h"

using namespace std;
using namespace boost::archive;

class ChargeCardView : public InputManager {
public:
    virtual ~ChargeCardView() = default;

private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    void display() override;
    bool isCorrectInput(const string &input) override;

    list<ChargeCard> chargeCards;
};


#endif //MOBILE_BANKING_APP_CHARGECARDVIEW_H
