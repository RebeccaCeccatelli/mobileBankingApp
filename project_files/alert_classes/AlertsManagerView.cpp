//
// Created by Rebecca on 01/10/2020.
//
#include "AlertsManagerView.h"

#include <iostream>
#include <string>
#include <filesystem>

#include "../general_purpose_classes/utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;
namespace fs = std::filesystem;

const string DISPLAY_ALL = "1";
const string DISPLAY_GENERAL = "2";
const string DISPLAY_PERSONAL = "3";
const string DISPLAY_UNREAD = "4";
const string DISPLAY_SPECIFIC = "5";
const string SAVE = "6";
const string SET_READ = "7";
const string BACK = "0";
const string YES = "yes";
const string NO = "no";

void AlertsManagerView::setClientName(const string &cname) {
    alertsManager.setClientName(cname);
}

void AlertsManagerView::pullFromServer() {
    alertsManager.pullFromServer();
}

void AlertsManagerView::updateServer() const {
    cout << "Updating server..." << endl;
    alertsManager.updateServer();
}

void AlertsManagerView::display() {
    pullFromServer();

    cout << endl << "*** Alerts area. ***" << endl << "What would you like to do?" << endl;
    cout << "1) display all alerts." << endl << "2)display general alerts." << endl << "3)display personal alerts."
         << endl << "4)display unread alerts." << endl << "5) display specific alert. " << endl << "6)Save alert as file. "
         << endl << "7) Set alert as read." << endl << "0) Go back. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(getStringInput());
}

bool AlertsManagerView::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == DISPLAY_ALL){
        showList(alertsManager.returnAll());
    }
    else if (input == DISPLAY_GENERAL){
        showList(alertsManager.returnGeneral());
    }
    else if (input == DISPLAY_PERSONAL){
        showList(alertsManager.returnPersonal());
    }
    else if (input == DISPLAY_UNREAD){
        showList(alertsManager.returnUnread());
    }
    else if (input == DISPLAY_SPECIFIC){
        showSpecificAlert(insertObject());
    }
    else if (input == SAVE){
        saveAsFile(insertObject());
    }
    else if (input == SET_READ)
        setAsRead(insertObject());
    else if (input == BACK) {
        updateServer();
        setGoBack(true);
    }
    else
        correct = false;

    return correct;
}

void AlertsManagerView::showList(const vector<string>& selectedAlerts) {

    for (const auto& object : selectedAlerts)
        cout << "- " << object << endl;
}

void AlertsManagerView::showSpecificAlert(const string &object) {
    pair<bool,const Alert*> searchResult = alertsManager.returnSpecific(object);

    if (searchResult.first) {
        if (wantToSetAsRead())
            setAsRead(object);

        if (wantToSaveAsFile())
            saveAsFile(object);

        displayAlert(searchResult.second);
    }
    else
        cout << "Alert " << object << "not found. " << endl;
}

bool AlertsManagerView::wantToSaveAsFile() const {
    cout << "Do you want to save it as a file?" << endl;
    string input = getStringInput();

    if (input == YES)
        return true;
    if (input == NO)
        return false;
    else {
        cout << "Your input is not correct. Try again. " << endl;
        return wantToSaveAsFile();
    }
}

void AlertsManagerView::saveAsFile(const string &object) {
    if (alertsManager.saveAsFile(object)) {
        cout << "Saving " << object << " as file in directory alerts... " << endl;
    }
    else
        cout << "Alert" << object << " not found. " << endl;
}

bool AlertsManagerView::wantToSetAsRead() const {
    cout << "Do you want to set it as read?" << endl;
    string input = getStringInput();

    if (input == YES)
        return true;
    if (input == NO)
        return false;
    else {
        cout << "Your input is not correct. Try again. " << endl;
        return wantToSetAsRead();
    }
}

void AlertsManagerView::setAsRead(const string &object) {
    if (alertsManager.setRead(object))
        cout << "Setting alert " << object << " as read..." << endl;
    else
        cout << "Alert not found." << endl;
}

void AlertsManagerView::displayAlert(const Alert* alert) {
    cout << "-Title: " << alert->object << endl;
    cout << "-Message: " << alert->message << endl;
    cout << "-Arrival date: " << alert->dateSetter.getDate() << endl;
    cout << "-Read: ";
    if (alert->isRead())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    cout << "-Personal: ";
    if (alert->isPersonal())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

string AlertsManagerView::insertObject() {
    cout << "Insert alert's object: (type '/' to confirm: " << endl;
    return getLineInput();
}
