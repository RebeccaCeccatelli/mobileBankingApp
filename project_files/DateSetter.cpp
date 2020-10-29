//
// Created by rebecca on 10/21/20.
//

#include "DateSetter.h"

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <locale>

using namespace std;

void DateSetter::setDate(string settedDate, char mode) {
    if (mode == 0) {
        time_t rawTime;
        time(&rawTime);
        date.first = *localtime(&rawTime);

        date.second = convertDateToString();
        cout << "Setting date automatically... " << endl;
    }
    if (mode == 1) {
        date.second = move(settedDate);
        date.first = convertDateToTm();
    }
}

string DateSetter::convertDateToString() const {
    char buffer[80];
    strftime(buffer, 80, "%x %X", &date.first);
    string stringDate(buffer);
    return stringDate;
}

tm DateSetter::convertDateToTm() const {
    locale loc;
    auto& tmget = use_facet <time_get<char>>(loc);
    ios::iostate state;
    string format = "%x %X";

    istringstream  iss {date.second};

    tm tmDate;
    tmget.get(iss, std::time_get<char>::iter_type(), iss,
              state, &tmDate, format.data(), format.data() + format.length());
    return tmDate;
}

const string &DateSetter::getStringDate() const {
    return date.second;
}
