//
// Created by Rebecca on 01/10/2020.
//
#include "AlertsManager.h"

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;
namespace fs = std::filesystem;

void AlertsManager::setClientName(const string &cname) {
    clientName = cname;
}

AlertsManager::AlertsManager() {
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
    getDirectoryEntries();

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
        displayMessage(getLineInput());
    }
    else if (input == "6"){
        cout << "Insert object: " << endl;
        saveAsFile(getLineInput());
        displayScreen();
    }
    else if (input == "7"){
        cout << "Insert object: " << endl;
        auto it = alerts.find(getLineInput());
        if (it != alerts.end())
            it->second.setRead();    //valutare possibilità di rimettere anche unread e farglielo ricordare.
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

void AlertsManager::deserialize(const string& extractedPath) {
    ifstream iFile(extractedPath);

    string line, object, message, arrivalDate;
    bool r{false}, pers{false};

    int it = 0;
    while (getline(iFile,line,'-') && it<=5){
        if (it == 1){
            line.erase(0,8);
            line.erase(line.end()-2,line.end());
            object = line;
        }
        if (it == 2){
            line.erase(0,9);
            line.erase(line.end()-2,line.end());
            message = line;
        }
        if(it == 3){
            line.erase(0,14);
            line.erase(line.end()-2,line.end());
            arrivalDate = line;
        }
        if (it == 4){
            line.erase(0,6);
            line.erase(line.end()-2,line.end());
            if (line == "yes")
                r = true;
        }
        if (it == 5){
            line.erase(0,10);
            if (line == "yes")
                pers = true;
        }
        it++;
    }
    Alert newAlert(object,message,r,pers,arrivalDate);
    alerts.emplace(object,newAlert);
    newAlert.serialize(clientName);
}

void AlertsManager::getDirectoryEntries() {
    for (auto& it : fs::directory_iterator("../server/" + clientName + "/alerts"))
        deserialize(it.path());
}

AlertsManager::~AlertsManager() {
    updateServer();
}

void AlertsManager::updateServer() const {
    cout << "Updating server..." << endl;
    for (const auto& alert : alerts)
        alert.second.serialize(clientName,"../server/");
}
