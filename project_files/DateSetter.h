//
// Created by rebecca on 10/21/20.
//

#ifndef MOBILE_BANKING_APP_DATESETTER_H
#define MOBILE_BANKING_APP_DATESETTER_H

#include <string>

using namespace std;

class DateSetter {
protected:
    void setDate(string settedDate = "", char mode = 0);

    string convertDateToString() const;
    tm convertDateToTm() const;

    pair<tm,string> date;
};


#endif //MOBILE_BANKING_APP_DATESETTER_H
