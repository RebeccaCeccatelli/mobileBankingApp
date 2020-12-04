//
// Created by rebecca on 11/21/20.
//

#include "ChargeCardManagerView.h"

#include <iostream>

#include "../general_purpose_classes/utilityFunctions.h"
#include "ChargeCardView.h"

using namespace utilityFunctions;
using namespace std;

void ChargeCardManagerView::display() {
    cout << endl << "*** List of associated cards. ***" << endl;
    if (chargeCards->empty())
        cout << "Empty. " << endl;
    else {
        for (const auto& chargeCard : *chargeCards){
            auto mainInformations = chargeCard.second.getNumberAndType();
            cout << chargeCard.first << ") Card number: " << mainInformations.first << ", type: ";
            if (mainInformations.second == CardType::debit)
                cout << "debit. " << endl;
            else
                cout << "credit. " << endl;
        }
    }
    cout << "Enter the corresponding number to see further details, (0) to go back: " << endl;
    manageInput(getStringInput());
}

bool ChargeCardManagerView::isCorrectInput(const string &input) {
    bool correct = true;
    if (input == BACK)
        setGoBack(true);
    else {
        auto it = chargeCards->find(input);
        if (it != chargeCards->end()){
            ChargeCardView chargeCardView(&it->second);
            chargeCardView.displayUserInterface();
        }
        else
            correct = false;
    }

    return correct;
}
