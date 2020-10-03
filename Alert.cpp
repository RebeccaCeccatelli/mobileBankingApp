//
// Created by Rebecca on 01/10/2020.
//

#include "Alert.h"

#include <fstream>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void Alert::serialize(const string &cname) {
    string path = "../my_files/" + cname + "/alerts/" + object;
    ofstream oFile (path);

    oFile << "-Title: " << object;
    oFile << "-\n\nMessage: " << message;
    oFile << "-\n\nArrival date: " << arrivalDate.second;
    oFile << "-\n\nRead: ";
    if (isRead())
        oFile << "yes" << endl;
    else
         oFile << "no" << endl;

    oFile.close();
}

void Alert::convertDatefromTmtoString() {
    strftime(arrivalDate.second,80,"%x %X",&arrivalDate.first);
}

void Alert::setDate() {
    time_t rawTime;
    time(&rawTime);
    arrivalDate.first = *localtime(&rawTime);
    convertDatefromTmtoString();
}

Alert::Alert(string obj, string mex, bool pers) : object{move(obj)}, message{move(mex)}, personal{pers} {
    setDate();
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
