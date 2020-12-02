//
// Created by Rebecca on 30/09/2020.
//

#include "RemindersManagerView.h"

#include <string>
#include <iostream>
#include <algorithm>

#include "../general_purpose_classes/utilityFunctions.h"

using namespace std;
using namespace utilityFunctions;

const string RemindersManagerView::DISPLAY_ALL = "1";
const string RemindersManagerView::DISPLAY_SPECIFIC = "2";
const string RemindersManagerView::CREATE = "3";
const string RemindersManagerView::REMOVE = "4";

void RemindersManagerView::setClientName(const string &cname) {
    remindersManager.setClientName(cname);
}

void RemindersManagerView::pullFromServer() {
  remindersManager.pullFromServer();
}

void RemindersManagerView::updateServer() const {
    cout << "Updating server..." << endl;
    remindersManager.updateServer();
}

void RemindersManagerView::display() {
    pullFromServer();

    cout << endl << "*** Reminders. ***" << endl << "What would you like to do?" << endl;
    cout << "1) Display all reminders. " << endl << "2) Display specific reminder. " << endl
         <<"3) Create reminder. " << endl << "4) Remove reminder. " << endl << "0) Go back. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(getStringInput());
}

bool RemindersManagerView::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == DISPLAY_ALL)
        showList(remindersManager.returnAll());
    else if (input == DISPLAY_SPECIFIC)
        showSpecificReminder(insertTitle());
    else if (input == CREATE)
        createReminder();
    else if (input == REMOVE)
        removeReminder(insertTitle());

    else if (input == BACK) {
        updateServer();
        setGoBack(true);
    }

    else
        correct = false;

    return correct;
}

void RemindersManagerView::createReminder() {
    cout << "Creating new reminder... " << endl;

    string title = insertTitle();
    remindersManager.createReminder(title,insertText());
    cout << "Setting date automatically... " << endl;

    showSpecificReminder(title);
}

void RemindersManagerView::removeReminder(const string& title) {
    if (remindersManager.removeReminder(title))
        cout << "Reminder " << title << " removed. " << endl;
    else
        cout << "Reminder not found." << endl;
}

void RemindersManagerView::showList(const vector<string> & selectedReminders) {

    for (const auto& title : selectedReminders)
        cout << "- " << title << endl;
}

void RemindersManagerView::showSpecificReminder(const string& title) {
    pair<bool,const Reminder*> searchResult = remindersManager.returnSpecific(title);

    if (searchResult.first) {
        if (wantToSaveAsFile())
            saveAsFile(title);

        displayReminder(searchResult.second);
    }
    else
        cout << "Reminder " << title << " not found. " << endl;
}

bool RemindersManagerView::wantToSaveAsFile() {
    cout << "This reminder is not saved yet. Do you want to save it as a file?" << endl;
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

void RemindersManagerView::saveAsFile(const string &title) {
    if (remindersManager.saveAsFile(title)) {
        cout << "Saving " << title << " as file in directory reminders... " << endl;
    }
    else
        cout << "Reminder" << title << " not found. " << endl;
}

void RemindersManagerView::displayReminder(const Reminder *reminder) {
    cout << "-Title: " << reminder->title << endl;
    cout << "-Text: " << reminder->text << endl;
    cout << "-Last update: " << reminder->dateSetter.getDate() << endl;
    cout << "-Saved: ";
    if (reminder->isSaved())
        cout << "yes";
    else
        cout << "no";
}

string RemindersManagerView::insertTitle() {
    cout << "Insert reminder's title: (type '/' to confirm): " << endl;
    return getLineInput();
}

string RemindersManagerView::insertText() {
    cout << "Insert reminder's title: (type '/' to confirm): " << endl;
    return getLineInput();
}

