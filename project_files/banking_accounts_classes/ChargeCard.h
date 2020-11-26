//
// Created by rebecca on 11/21/20.
//

#ifndef MOBILE_BANKING_APP_CHARGECARD_H
#define MOBILE_BANKING_APP_CHARGECARD_H

#include <string>
#include <map>
#include <vector>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
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
    pair<string,CardType> getNumberAndType() const;
    bool isActive() const;
    pair<int, int> getLimits() const;
    const string& getLatestTransaction() const;
    bool setLimit(int newLimit);
    void changeState();

    vector<const CardTransaction*> returnSelected(RequestedTransactions request, const string& filter = "");
private:
    friend class boost::serialization::access;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version);

    string cardNumber;
    CardType cardType;
    bool active{true};
    int monthlyLimit{500};

    map<string,CardTransaction,Compare> relatedCardTransactions;

    //class constant
    static const int MAX_LIMIT;
};


#endif //MOBILE_BANKING_APP_CHARGECARD_H
