//
// Created by Rebecca on 30/09/2020.
//

#include "Reminder.h"

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <locale>

using namespace std;

Reminder::Reminder() {
    setUserTitle();
    setUserText();
    setLastUpdate(0);
}

Reminder::Reminder(const string &tit, const string &tex,const string& date) {
    title = tit;
    text = tex;
    setLastUpdate(1, date);
}

void Reminder::display() {
    cout << "-Title: " << title << endl;
    cout << "-Text: " << text << endl;
    cout << "-Creation date: " << convertDateToString();
}

void Reminder::setUserTitle() {
    cout << "Set title (insert '/' to confirm): " << endl;
    getline(cin,title,'/');
}

void Reminder::setUserText() {
    cout << "Set text (insert '/' to confirm): " << endl;
    getline(cin,text,'/');
}

const string &Reminder::getTitle() const {
    return title;
}

const string Reminder::convertDateToString() const {
    char buffer[80];
    strftime(buffer, 80, "%x %X", &lastUpdate.first);
    string stringDate(buffer);
    return stringDate;
}

tm Reminder::convertDateToTm() const {
    locale loc;
    auto& tmget = use_facet <time_get<char>>(loc);
    ios::iostate state;
    string format = "%x %X";

    istringstream  iss {lastUpdate.second};

    tm tmDate;
    tmget.get(iss, std::time_get<char>::iter_type(), iss,
              state, &tmDate, format.data(), format.data() + format.length());
    return tmDate;
}


void Reminder::setLastUpdate(char mode, const string& date) {
    if (mode == 0) {
        time_t rawTime;
        time(&rawTime);
        lastUpdate.first = *localtime(&rawTime);

        lastUpdate.second = convertDateToString();
        cout << "Date automatically setted. " << endl;
    }
    if (mode == 1) {
        lastUpdate.second = date;
        lastUpdate.first = convertDateToTm();
    }
}

void Reminder::serialize(const string &cname) const {
    string path = "../files/" + cname + "/reminders/" + title;
    ofstream oFile (path);

    oFile << "-Title: " << title;
    oFile << "\n\n-Text: " << text;
    oFile << "\n\n-Creation date: " << convertDateToString();

    oFile.close();
}
