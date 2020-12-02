//
// Created by rebecca on 11/25/20.
//

#ifndef MOBILE_BANKING_APP_CHARGECARDVIEW_H
#define MOBILE_BANKING_APP_CHARGECARDVIEW_H

#include <string>

#include "../general_purpose_classes/InputManager.h"
#include "ChargeCard.h"

using namespace std;

class ChargeCardView : public InputManager {
public:
    explicit ChargeCardView(ChargeCard* card) : chargeCard{card} {}
    ~ChargeCardView() override = default;

private:
    void display() override;
    bool isCorrectInput(const string &input) override;

    //helper methods
    void displayDetailedInformations() const;
    void displayTransactions() const;
    void modifyMaximumLimit();
    void changeCardState();
    static void showList(const vector<const CardTransaction *> &selectedTransactions);
    static void showSpecificTransaction(const CardTransaction* cardTransaction);

    //attribute
    ChargeCard* chargeCard{nullptr};

    //class constants
    static const string BACK;
    static const string INFOS;
    static const string TRANSACTIONS;
    static const string LIMIT;
    static const string STATE;
};


#endif //MOBILE_BANKING_APP_CHARGECARDVIEW_H
