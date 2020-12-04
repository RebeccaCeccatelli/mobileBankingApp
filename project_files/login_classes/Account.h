//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_ACCOUNT_H
#define MOBILE_BANKING_APP_ACCOUNT_H

#include <list>
#include <string>
#include <boost/serialization/string.hpp>

#include "PersonalAreaView.h"

using namespace std;
using namespace boost::archive;

class Account {
public:
    Account(string titCode, string pin, string c) : acceptableCredentials{make_pair(move(titCode),move(pin))},
        clientName{move(c)} {}
    Account() = default;

    bool areCorrectCredentials(const string& titCode, const string& pin) const;
    void enter();

private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & acceptableCredentials.first;
        ar & acceptableCredentials.second;
        ar & clientName;
    }

    //attributes
    pair<string, string> acceptableCredentials;
    string clientName;
    PersonalAreaView personalAreaView;
};


#endif //MOBILE_BANKING_APP_ACCOUNT_H
