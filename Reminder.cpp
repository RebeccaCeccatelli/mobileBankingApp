//
// Created by Rebecca on 30/09/2020.
//

#include "Reminder.h"

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

Reminder::Reminder() {
    setTitle();
    setText();
    setCreationDate();
}

Reminder::Reminder(const string &tit, const string &tex) {
    title = tit;
    text = tex;
    setCreationDate();
}

void Reminder::display() {
    cout << "Title: " << title << endl;
    cout << "Text: " << text << endl;
    cout << "- Creation date: " << getCreationDate();
}

void Reminder::setTitle() {
    string tmp;
    cout << "Set title: " << endl;
    getline(cin,tmp,'/');
    title = tmp;
}

void Reminder::setText() {
    string tmp;
    cout << "set text: " << endl;
    getline(cin,tmp,'/');
    text = tmp;
}

const string &Reminder::getTitle() const {
    return title;
}

const string &Reminder::getText() const {
    return text;
}

const string Reminder::getCreationDate() const {
    return asctime(&lastUpdate);
}

void Reminder::setCreationDate() {
    cout << "Automatically setting date: ";
    time_t rawTime;
    time(&rawTime);
    lastUpdate = *localtime(&rawTime);
}

void Reminder::serialize(const string &cname) const {
    string path = "../files/" + cname + "/reminders/" + title;
    ofstream oFile (path);

    oFile << "-Title: " << getTitle();
    oFile << "\n\n-Text: " << getText();
    oFile << "\n\n-Creation date: " << getCreationDate();

    oFile.close();
}
