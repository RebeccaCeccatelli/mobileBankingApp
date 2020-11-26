//
// Created by rebecca on 11/26/20.
//

#ifndef MOBILE_BANKING_APP_COMPARE_H
#define MOBILE_BANKING_APP_COMPARE_H

#include <string>

using namespace std;

struct Compare {
    bool operator()(const string& left, const string& right) const;
};


#endif //MOBILE_BANKING_APP_COMPARE_H
