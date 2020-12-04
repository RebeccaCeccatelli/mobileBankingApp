//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_CHARGECARD_H
#define MOBILE_BANKING_APP_CHARGECARD_H

#include <string>
#include <vector>
#include <map>
#include <boost/serialization/string.hpp>
#include <boost/serialization/map.hpp>

#include "CardTransaction.h"
#include "Compare.h"

using namespace std;
using namespace boost::archive;

enum class CardType {
    credit,
    debit
};

enum class RequestedTransactions {
    all,
    specificDate,
    specificCategory
};

class ChargeCard {
public:
    bool setLimit(int newLimit);
    void changeState();

    pair<string,string> getAssociatedBankingAccount() const;
    pair<string,CardType> getNumberAndType() const;
    pair<int, int> getLimits() const;
    string getLatestTransaction() const;
    bool isActive() const;

    vector<const CardTransaction*> returnSelected(RequestedTransactions request, const string& filter = "");

    void serializeInReadableFormat() const;

private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & cardNumber;
        ar & cardType;
        ar & active;
        ar & monthlyLimit;
        ar & relatedCardTransactions;
        ar & associatedBankingAccount.first;
        ar & associatedBankingAccount.second;
    }

    //attributes
    string cardNumber;
    CardType cardType;
    bool active{true};
    int monthlyLimit{500};
    pair<string,string> associatedBankingAccount; //name,iban

    map<string,CardTransaction,Compare> relatedCardTransactions;

    //class constant
    static const int MAX_LIMIT;
};

#endif //MOBILE_BANKING_APP_CHARGECARD_H
