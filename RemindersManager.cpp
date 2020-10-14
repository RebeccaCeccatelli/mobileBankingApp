//
// Created by Rebecca on 30/09/2020.
//

#include "RemindersManager.h"

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "utilityFunctions.h"
#include <filesystem>

using namespace std;
using namespace utilityFunctions;

namespace fs = std::filesystem;

void RemindersManager::setClientName(const string &cname) {
    clientName = cname;
}

void RemindersManager::pullFromServer() {
    for (auto& it : fs::directory_iterator("../server/" + clientName + "/reminders"))
        reminders.emplace(Reminder::deserialize(it.path()));
}

void RemindersManager::updateServer() const {
    cout << "Updating server..." << endl;
    for (const auto& reminder : reminders)
        reminder.second.serialize(clientName,"../server/");
}

void RemindersManager::display() {
    pullFromServer();

    cout << endl << "*** Reminders. ***" << endl << "What would you like to do?" << endl;
    cout << "1) Display all reminders. " << endl << "2) Display specific reminder. " << endl
         <<"3) Create reminder. " << endl << "4) Remove reminder. " << endl << "0) Go back. " << endl;

    cout << "Choose action (enter the corresponding number): " << endl;

    manageInput(getStringInput());
}
bool RemindersManager::isCorrectInput(string input) {
    bool correct = true;

    if (input == "1")
        displayAll();
    else if (input == "2")
        displaySpecificReminder(insertTitle());
    else if (input == "3")
        createReminder();
    else if (input == "4")
        removeReminder(insertTitle());

    else if (input == "0") {
        updateServer();
        setGoBack(true);
    }

    else
        correct = false;

    return correct;
}

void RemindersManager::tryAgain() {
    display();
}

void RemindersManager::enableFailureRoutine() {
    cout << "There is no maximum limit here, you can try again. " << endl;
    display();
}

void RemindersManager::displayAll() {
    for (const auto& reminder : reminders)
        cout << "- " << reminder.first << endl;
}

void RemindersManager::displaySpecificReminder(const string& title) {
    auto it = reminders.find(title);
    if (it!=reminders.end()){
        if (!it->second.isSaved()) {
            if (wantToSaveAsFile()) {
                cout << "Saving reminder " << it->first << " as file in directory reminders..." << endl;
                it->second.setSaved();
                it->second.serialize(clientName);
            }
        }
        else
            cout << "This reminder is already saved. " << endl;
        it->second.display();
    }
    else
        cout << "Reminder not found. " << endl;
}

bool RemindersManager::wantToSaveAsFile() {
    cout << "This reminder is not saved yet. Do you want to save it as a file?" << endl;
    string input = getStringInput();

    if (input == "yes")
        return true;
    if (input == "no")
        return false;
    else {
        cout << "Your input is not correct. Try again. " << endl;
        return wantToSaveAsFile();
    }
}

void RemindersManager::createReminder() {
    cout << "Creating new reminder... " << endl;

    Reminder newReminder;
    reminders.emplace(newReminder.getTitle(),newReminder);
    displaySpecificReminder(newReminder.getTitle());
}

void RemindersManager::removeReminder(const string& title) {
    auto it = reminders.find(title);
    if (it != reminders.end()) {
        reminders.erase(it);

        fs::remove("../my_files/" + clientName + "/reminders/" + title);
        fs::remove("../server/" + clientName + "/reminders/" + title);

        cout << "Reminder " << title << " removed. " << endl;
    }
    else
        cout << "Reminder not found." << endl;
}

string RemindersManager::insertTitle() {
    cout << "Insert reminder's title: (type '/' to confirm): " << endl;
    return getLineInput();
}
