//
// Created by Rebecca on 01/10/2020.
//

#include "Alert.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <locale>
#include <ctime>
#include <string>

using namespace std;

void Alert::serialize(const string &cname,const string& mainDirectory) const{
    string path = mainDirectory + cname + "/alerts/" + object;
    ofstream oFile (path);

    oFile << "-Object: " << object;
    oFile << "\n\n-Message: " << message;
    oFile << "\n\n-Arrival date: " << arrivalDate.second;
    oFile << "\n\n-Read: ";
    if (isRead())
        oFile << "yes";
    else
         oFile << "no";
    oFile << "\n\n-Personal: ";
    if (personal)
        oFile << "yes";
    else
        oFile << "no";

    oFile.close();
}

void Alert::setDate(char mode, const string &date) {
    if (mode == 0) {
        time_t rawTime;
        time(&rawTime);

    }
    if (mode == 1) {
        arrivalDate.second = date;
        arrivalDate.first = convertDateToTm();
    }
}

Alert::Alert(string obj, string mex, bool r, bool pers, string date) : object{move(obj)}, message{move(mex)},
                                                                       read{r}, personal{pers} {
    setDate(1, date);
}

bool Alert::isRead() const {
    return read;
}

bool Alert::isPersonal() const {
    return personal;
}

void Alert::setRead() {
    if (!isRead())
        read = true;
}

void Alert::display() {
    cout << "-Title: " << object << endl;
    cout << "-Message: " << message << endl;
    cout << "-Arrival date: " << arrivalDate.second << endl;
    cout << "-Read: ";
    if (isRead())
        cout << "yes" << endl;
    else
        cout << "no" << endl;

}

tm Alert::convertDateToTm() const {
    locale loc;
    auto& tmget = use_facet <time_get<char>>(loc);
    ios::iostate state;
    string format = "%x %X";

    istringstream  iss {arrivalDate.second};

    tm tmDate;
    tmget.get(iss, std::time_get<char>::iter_type(), iss,
              state, &tmDate, format.data(), format.data() + format.length());
    return tmDate;
}
