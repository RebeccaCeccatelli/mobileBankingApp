//
// Created by Rebecca on 30/09/2020.
//

#include "Reminder.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Reminder::Reminder() {
    setUserTitle();
    setUserText();
    setDate();
}

Reminder::Reminder(string tit, string tex, string date, bool s) : title{move(tit)}, text{move(tex)}, saved{s} {
    setDate(move(date), 1);
}

void Reminder::display() {
    cout << "-Title: " << title << endl;
    cout << "-Text: " << text << endl;
    cout << "-Last update: " << date.second << endl;
    cout << "-Saved: ";
    if (isSaved())
        cout << "yes";
    else
        cout << "no";
}

const string &Reminder::getTitle() const {
    return title;
}

bool Reminder::isSaved() const {
    return saved;
}

void Reminder::setSaved() {
    saved = true;
}

void Reminder::serialize(const string &cname, string mainDirectory) const {
    string path = move(mainDirectory) + cname + "/reminders/" + title;
    ofstream oFile (path);

    oFile << "-Title: " << title;
    oFile << "\n\n-Text: " << text;
    oFile << "\n\n-Last update: " << date.second;
    oFile << "\n\n-Saved: ";
    if (isSaved())
        oFile << "yes";
    else
        oFile << "no";

    oFile.close();
}

pair<string,Reminder> Reminder::deserialize(const string &extractedPath) {
    ifstream iFile (extractedPath);

    string line, title, text, lastUpdate;
    bool saved{false};

    int it = 0;
    while (getline(iFile, line,'-') && it <=4) {
        if (it == 1) {
            line.erase(0, 7);
            line.erase(line.end() - 2, line.end());
            title = line;
        }
        if (it == 2 ){
            line.erase(0,6);
            line.erase(line.end()-2,line.end());
            text = line;
        }
        if (it == 3){
            line.erase(0, 13);
            line.erase(line.end()-2,line.end());
            lastUpdate = line;
        }
        if (it == 4){
            line.erase(0,7);
            if (line == "yes")
                saved = true;
        }
        it++;
    }
    iFile.close();

    return make_pair(title, Reminder(title, text, lastUpdate, saved));
}

void Reminder::setUserTitle() {
    cout << "Insert title (type '/' to confirm): " << endl;
    cin.ignore();
    getline(cin,title,'/');
}

void Reminder::setUserText() {
    cout << "Insert text (type '/' to confirm): " << endl;
    cin.ignore();
    getline(cin,text,'/');
}


