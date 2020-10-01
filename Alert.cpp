//
// Created by Rebecca on 01/10/2020.
//

#include "Alert.h"

#include <fstream>
#include <iostream>
#include <ctime>

void Alert::serialize(const string &cname) {
    string path = "../files/" + cname + "/alerts/" + title;
    ofstream oFile (path);

    oFile << "-Title: " << title << endl << endl;
    oFile << "-Message: " << message << endl << endl;
    oFile << "-Arrival date: " << arrivalDate.first << endl << endl;
    oFile << "-Read: " << read << endl << endl;

    oFile.close();
}

void Alert::convertDatefromTmtoString() {
    strftime(arrivalDate.first,80,"%x %X",&arrivalDate.second);
    puts(arrivalDate.first);
}
void Alert::setTitle() {
    string tmp;
    cout << "Set title: " << endl;
    getline(cin,tmp,'/');
    title = tmp;
}
void Alert::setText() {
    string tmp;
    cout << "set text: " << endl;
    getline(cin,tmp,'/');
    message = tmp;
}

void Alert::setDate() {
    cout << "Automatically setting date... " << endl;
    time_t rawTime;
    time(&rawTime);
    arrivalDate.second = *localtime(&rawTime);
    convertDatefromTmtoString();
}

Alert::Alert() {
    setTitle();
    setText();
    setDate();
}
