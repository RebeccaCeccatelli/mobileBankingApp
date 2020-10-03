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

void RemindersManager::displayAllTitles() {
    for (const auto& reminder : reminders)
        cout << "- " << reminder.first << endl;
    displayUserInterface();
}

void RemindersManager::createReminder() {
    Reminder newReminder;
    reminders.emplace(newReminder.getTitle(),newReminder);
    newReminder.serialize(clientName);

}

void RemindersManager::removeReminder(const string& title) {
    auto it = reminders.find(title);
    if (it != reminders.end()) {
        reminders.erase(it);
        cout << "Reminder " << title << " removed. " << endl;
    }
    else
        cout << "Reminder " << title << " not found." << endl;
}

void RemindersManager::displayReminder(const string& title) {

    auto it = reminders.find(title);
    if (it!=reminders.end())
        it->second.display();
    else
        cout << "Reminder" << title << " not found. " << endl;
}

void RemindersManager::displayUserInterface() {
    getFromServer();
    cout << "*** Reminders. ***" << endl << "What would you like to do?" << endl;
    cout << "1) Display titles' list. " << endl << "2) Display reminder. " << endl << "3) Create reminder. "
         << endl << "4) Remove reminder. " << endl << "5) Extract reminder from file. " << endl << "6) save file." << endl;

    cout << "Choose action (enter the corrisponding number): " << endl;
    manageInput(this);
    updateServer();
}

bool RemindersManager::isCorrectInput() {
    bool correct = true;
    string input = getStringInput();

    if (input == "1")
        displayAllTitles();
    else if (input == "2")
        displayReminder(insertTitle());
    else if (input == "3") {
        createReminder();
        displayUserInterface();
    }
    else if (input == "4")
        removeReminder(insertTitle());
    else if (input == "5"){
        deserialize(insertTitle());
        displayUserInterface();
    }
    else if (input == "6"){
        cout << "Insert title: " << endl;

        auto it = reminders.find(getLineInput());
        if (it!= reminders.end()) {
            cout << "Saving file." << endl;
            it->second.serialize(clientName);//forse grazie a filesystem si può anche fare a meno di usare clientName TODO
        }
        else
            cout << "not found. " << endl;
    }

    else
        correct = false;

    return correct;
}

void RemindersManager::tryAgain() {
    displayUserInterface();
}

void RemindersManager::enableFailureRoutine() {
    cout << "More than five uncorrect inputs. There is no maximum limit here, you can try again. " << endl;
    displayUserInterface();
}

string RemindersManager::insertTitle() {
    cout << "Insert reminder's title: " << endl;
    string tmp;
    getline(cin,tmp, '/');
    return tmp;
}

void RemindersManager::setClientName(const string &cname) {
    clientName = cname;
}

void RemindersManager::deserialize(const string &extractedPath) {

    ifstream iFile (extractedPath);

    string line, title, text, lastUpdate;
    int it = 0;
    while (getline(iFile, line,'-') && it <=3) {
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
            line.erase(0, 15);
            lastUpdate = line;
        }
        it++;
    }
    reminders.emplace(title,Reminder(title,text,lastUpdate));
}

void RemindersManager::getDirectoryEntries() {
    for (auto& it : fs::directory_iterator("../server/" + clientName + "/reminders"))
        deserialize(it.path());
}

void RemindersManager::getFromServer() {
    getDirectoryEntries();
}

void RemindersManager::updateServer() {
    cout << "Updating server..." << endl;
    for (const auto& reminder : reminders)
        reminder.second.serialize(clientName,"../server/");
}
// metodi getfromserver e updateserver