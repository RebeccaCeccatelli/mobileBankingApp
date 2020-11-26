//
// Created by rebecca on 11/21/20.
//

#include "BankingAccount.h"
#include "PhoneRecharge.h"
#include "WireTransfer.h"

const int BankingAccount::THRESHOLD = 50;
const int BankingAccount::COMMISSIONS = 2;

template<typename Archive>
void BankingAccount::serialize(Archive &ar, const unsigned int version) {
    ar & dateSetter;
    ar & IBAN;
    ar & accountHolder;
    ar & totalDepositAmount;
    ar & transactions; //verificare che deserializzi correttamente anche le chiavi TODO
    ar & chargeCards;
}

map<string,ChargeCard> *BankingAccount::getChargeCardsList() {
    return &chargeCards;
}

tuple<string, string, int,string> BankingAccount::getDetailedInformations() const {
    int numberOfCards = chargeCards.size();
    string creationDate = dateSetter.getDate();
    string latestTransaction = transactions.crbegin()->first;
    return make_tuple(accountHolder,move(creationDate),numberOfCards,move(latestTransaction));
}

bool BankingAccount::createPhoneRecharge(const tuple<string,string,int> &userInformations) {
    bool accepted = false;
    if (subtractAmount(get<2>(userInformations))){
        accepted = true;
        addPhoneRechargeToTransactions(userInformations);
    }
    return accepted;
}

bool BankingAccount::subtractAmount(int amount, bool commissions) {
    bool available = false;
    if(commissions)
        amount += COMMISSIONS;
    if (amount <= totalDepositAmount) {
        totalDepositAmount -= amount;
        available = true;
    }
    return available;
}

void BankingAccount::addPhoneRechargeToTransactions(const tuple<string, string, int> &userInformations) {
    auto phoneRecharge = new PhoneRecharge(userInformations);

    transactions.emplace(phoneRecharge->getDate(),phoneRecharge);
}

bool BankingAccount::isLowDeposit() const {
    bool low = false;
    if (totalDepositAmount <= THRESHOLD)
        low = true;
    return low;
}

const string& BankingAccount::getIban() const {
    return IBAN;
}

int BankingAccount::getDeposit() const {
    return totalDepositAmount;
}

bool BankingAccount::createWireTransfer(const tuple<string, string, string, int> &userInformations) {
    bool accepted = false;
    if(subtractAmount(get<3>(userInformations),true)){
        accepted = true;
        addWireTransferToTransactions(userInformations);
    }
    return accepted;
}

void BankingAccount::addWireTransferToTransactions(const tuple<string, string, string, int> &userInformations) {
    auto wireTransfer = new WireTransfer(get<3>(userInformations));
    wireTransfer->setSender(accountHolder,IBAN);
    wireTransfer->setRecipient(get<1>(userInformations),get<0>(userInformations));

    transactions.emplace(wireTransfer->getDate(),wireTransfer);
}
