//
// Created by rebecca on 10/29/20.
//

#include "RemindersManager.h"

#include <filesystem>

namespace fs = std::filesystem;

void RemindersManager::setClientName(const string &cname) {
    clientName = cname;
}

void RemindersManager::pullFromServer() {
    for (auto& it : fs::directory_iterator("../server/" + clientName + "/reminders"))
        reminders.emplace(Reminder::deserialize(it.path()));
}

void RemindersManager::updateServer() const {
    for (const auto& reminder : reminders)
        reminder.second.serialize(clientName,"../server/");
}

bool RemindersManager::removeReminder(const string &title) {
    bool found{false};

    auto it = reminders.find(title);
    if (it != reminders.end()) {
        reminders.erase(it);

        fs::remove("../my_files/" + clientName + "/reminders/" + title);
        fs::remove("../server/" + clientName + "/reminders/" + title);
        found = true;
    }
    return found;
}

void RemindersManager::createReminder(const string &title, string text) {
    reminders.emplace(title,Reminder(title,move(text)));
}

vector<string> RemindersManager::returnAll() const {
    vector<string> all;

    for (const auto& reminder : reminders)
        all.push_back(reminder.first);

    return all;
}

pair<bool,const Reminder*> RemindersManager::returnSpecific(const string& title) const {
    bool found{false};
    const Reminder* reminder{nullptr};

    const auto it = reminders.find(title);

    if (it != reminders.end()) {
        reminder = &it->second;
        found = true;
    }

    return make_pair(found, reminder);
}

bool RemindersManager::saveAsFile(const string &title) {
    bool found{false};

    const auto it = reminders.find(title);

    if (it != reminders.end()) {
        it->second.setSaved();
        it->second.serialize(clientName);
        found = true;
    }
    return found;
}
