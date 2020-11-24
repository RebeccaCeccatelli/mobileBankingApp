//
// Created by rebecca on 11/21/20.
//

#include "ChargeCardView.h"

bool ChargeCardView::isCorrectInput(const string &input) {
    return false;
}

void ChargeCardView::display() {

}

template<typename Archive>
void ChargeCardView::serialize(Archive &ar, const unsigned int version) {
    ar & chargeCards;
}
