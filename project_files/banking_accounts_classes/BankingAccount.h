//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_BANKINGACCOUNT_H
#define MOBILE_BANKING_APP_BANKINGACCOUNT_H

#include <map>
#include <string>
#include <boost/serialization/string.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp>

#include "Transaction.h"
#include "ChargeCardManagerView.h"
#include "ChargeCard.h"
#include "WireTransfer.h"
#include "PhoneRecharge.h"
#include "Compare.h"
#include "../general_purpose_classes/DateSetter.h"

using namespace std;
using namespace boost::archive;

class BankingAccount {
public:
    const string& getIban() const;
    int getDeposit() const;
    tuple<string,string,int,string> getDetailedInformations() const;
    map<string,ChargeCard>* getChargeCardsList();

    bool createPhoneRecharge(const tuple<string, string, int> &userInformations);
    bool createWireTransfer(const tuple<string, string, string, int> &userInformations);
    bool isLowDeposit() const;

    void serializeInReadableFormat() const;

    void addTransaction(Transaction* trans){
        transactions.emplace(trans->getDate(),trans);
    }
private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & dateSetter;
        ar & IBAN;
        ar & accountHolder;
        ar & totalDepositAmount;
        ar & chargeCards;

        ar.template register_type<CardTransaction>(); //explicit registration of derived classes
        ar.template register_type<WireTransfer>();
        ar.template register_type<PhoneRecharge>();

        ar & transactions;
    }

    //helper methods
    bool subtractAmount(int amount, bool commissions = false);
    void addPhoneRechargeToTransactions(const tuple<string, string, int> &userInformations);
    void addWireTransferToTransactions(const tuple<string, string, string, int> &userInformations);

    string IBAN;
    int totalDepositAmount;
    string accountHolder;
    DateSetter dateSetter;

    map<string,Transaction*,Compare> transactions;
    map<string, ChargeCard> chargeCards;

    //class constants
    static const int THRESHOLD;
    static const int COMMISSIONS;
};

#endif //MOBILE_BANKING_APP_BANKINGACCOUNT_H
