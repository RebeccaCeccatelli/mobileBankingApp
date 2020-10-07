//
// Created by Rebecca on 01/10/2020.
//
#include "AlertsManager.h"

#include <iostream>
#include <string>
#include <filesystem>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;
namespace fs = std::filesystem;

void AlertsManager::setClientName(const string &cname) {
    clientName = cname;
}

void AlertsManager::display() {
    pullFromServer();

    cout << endl << "*** Alerts area. ***" << endl << "What would you like to do?" << endl;
    cout << "1) display all alerts." << endl << "2)display general alerts." << endl << "3)display personal alerts."
         << endl << "4)display unread alerts." << endl << "5) display specific alert. " << endl << "6)Save alert as file. "
         << endl << "7) Set alert as read." << endl << "0) Go back. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(this);
}

void AlertsManager::pullFromServer() {
    for (auto& it : fs::directory_iterator("../server/" + clientName + "/alerts"))
        alerts.emplace(Alert::deserialize(it.path()));
}

void AlertsManager::updateServer() const {
    cout << "Updating server..." << endl;
    for (const auto& alert : alerts)
        alert.second.serialize(clientName,"../server/");
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
        if (wantToSaveAsFile()){
            cout << "Saving file in alerts..." << endl;
            it->second.serialize(clientName);
        }
        if (wantToSetAsRead()) {
            cout << "Setting alert as read..." << endl;
            it->second.setRead();
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

bool AlertsManager::wantToSetAsRead() {
    cout << "Do you want to set it as read?" << endl;
    string input = getStringInput();

    if (input == "yes")
        return true;
    if (input == "no")
        return false;
    else {
        cout << "Input not correct. Try again. " << endl;
        return wantToSetAsRead();
    }
}
void AlertsManager::saveAsFile(const string &object) {
    const auto& it = alerts.find(object);
    if (it != alerts.end()) {
        cout << "Saving file in alerts... " << endl;
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
    }
    else if (input == "2"){
        displayGeneral();
    }
    else if (input == "3"){
        displayPersonal();
    }
    else if (input == "4"){
        displayUnread();
    }
    else if (input == "5"){
        cout << "Insert object: " << endl;
        displayMessage(getLineInput());
    }
    else if (input == "6"){
        cout << "Insert object: " << endl;
        saveAsFile(getLineInput());
    }
    else if (input == "7"){
        cout << "Insert object: " << endl;
        auto it = alerts.find(getLineInput());
        if (it != alerts.end())
            it->second.setRead();
        else
            cout << "not found." << endl;
    }
    else if (input == "0") {
        updateServer();
        setGoBack(true);
    }
    else
        correct = false;

    return correct;
}

void AlertsManager::tryAgain() {
    cout << "Uncorrect input. Try again. " << endl;
    display();
}

void AlertsManager::enableFailureRoutine() {
    cout << "More than five uncorrect inputs. No limit here. " << endl;
    display();
}


