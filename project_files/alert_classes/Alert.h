
//
// Created by Rebecca on 01/10/2020.
//

#ifndef MOBILE_BANKING_APP_ALERT_H
#define MOBILE_BANKING_APP_ALERT_H

#include <string>

#include "../general_purpose_classes/DateSetter.h"

using namespace std;

class Alert {
    friend class AlertsManagerView;

public:
    Alert(string obj, string mex, bool r, bool pers, string date);

    void serialize(const string &cname, string mainDirectory = "../my_files/") const;
    static pair<string, Alert> deserialize(const string& extractedPath);

    void setRead();
    bool isRead() const;
    bool isPersonal() const;

private:
    //attributes
    string object;
    string message;
    bool read;
    bool personal;

    DateSetter dateSetter;
};

#endif //MOBILE_BANKING_APP_ALERT_H
