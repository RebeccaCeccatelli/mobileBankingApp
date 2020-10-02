//
// Created by Rebecca on 01/10/2020.
//
#include "AlertsManager.h"

#include <iostream>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

void AlertsManager::setClientName(const string &cname) {
    clientName = cname;
}

AlertsManager::AlertsManager() {

    alerts.emplace("Christmas holidays", Alert("Christmas holidays","Banks will be closed during holidays."));
    alerts.emplace ("New credit card",Alert("New credit card", "We inform you that your new credit card has arrived.",true));
    alerts.emplace("Changes to privacy settings", Alert("Changes to privacy settings", "We modified privacy settings. We invite you to reconsider them."));
    alerts.emplace("Large withdrawal", Alert("Large withdrawal","You made a very large withdrawal recently. Check it.",true));

}

void AlertsManager::displayAll() {
    for (const auto& alert : alerts)
        cout << "- " << alert.first << endl;
}

void AlertsManager::displayGeneral() {
    for (const auto& alert : alerts) {
        if (!alert.second.isPersonal())
            cout << "- " << alert.first << endl;
    }
}

void AlertsManager::displayPersonal() {
    for (const auto& alert : alerts) {
        if (alert.second.isPersonal())
            cout << "- " << alert.first << endl;
    }
}

void AlertsManager::displayUnread() {
    for (const auto& alert : alerts) {
        if (!alert.second.isRead())
            cout << "- " << alert.first << endl;
    }
}

void AlertsManager::displayMessage(const string &object) {
    auto it = alerts.find(object);
    if (it != alerts.end()) {
        it->second.setRead();
        if (wantToSaveAsFile()){
            cout << "Saving file in alerts..." << endl;
            it->second.serialize(clientName);
        }
        it->second.display();
    }
    else
        cout << "Alert not found. " << endl;
}

bool AlertsManager::wantToSaveAsFile() {
    cout << "Do you want to save it as a file?" << endl;
    string input = getStringInput();

    if (input == "yes")
        return true;
    if (input == "no")
        return false;
    else {
        cout << "Input not correct. Try again. " << endl;
        return wantToSaveAsFile();
    }
}

void AlertsManager::displayScreen() {
    cout << "*** Alerts area. " << endl << "What would you like to do? Insert corresponding number. " << endl;
    cout << "1) display all" << endl << "2)display general" << endl << "3)display personal"
        << endl << "4)display unread." << endl << "5) display specific message" << endl << "6)Save file. "
        << endl << "7) Set message as read." << endl;

    manageInput(this);
}

void AlertsManager::saveAsFile(const string &object) {
    auto it = alerts.find(object);   //controllare senso di const auto& it
    if (it != alerts.end()) {
        cout << "Saving file... " << endl;
        it->second.serialize(clientName);
    }
    else
        cout << "Alert not found. " << endl;
}

bool AlertsManager::isCorrectInput() {
    bool correct = true;
    string input = getStringInput();

    if (input == "1"){
        displayAll();
        displayScreen();
    }
    else if (input == "2"){
        displayGeneral();
        displayScreen();
    }
    else if (input == "3"){
        displayPersonal();
        displayScreen();
    }
    else if (input == "4"){
        displayUnread();
        displayScreen();
    }
    else if (input == "5"){
        cout << "Insert object: " << endl;
        string tmp;
        cin.ignore();
        getline(cin,tmp,'/');
        displayMessage(tmp);
    }
    else if (input == "6"){
        cout << "Insert object: " << endl;
        string tmp;
        cin.ignore();
        getline(cin,tmp, '/');
        saveAsFile(tmp);
        displayScreen();
    }
    else if (input == "7"){
        cout << "Insert object: " << endl;
        string tmp;
        cin.ignore();
        getline(cin,tmp, '/');
        auto it = alerts.find(tmp);
        if (it != alerts.end())
            it->second.setRead();
        else
            cout << "not found." << endl;
    }
    else
        correct = false;
    return correct;
}

void AlertsManager::tryAgain() {
    cout << "Uncorrect input. Try again. " << endl;
    displayScreen();
}

void AlertsManager::enableFailureRoutine() {
    cout << "More than five uncorrect inputs. No limit here. " << endl;
    displayScreen();
}
