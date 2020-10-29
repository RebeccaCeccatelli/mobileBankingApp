//
// Created by rebecca on 10/28/20.
//

#include "AlertsManager.h"

#include <filesystem>

namespace fs = std::filesystem;

void AlertsManager::pullFromServer() {
    for (auto& it : fs::directory_iterator("../server/" + clientName + "/alerts"))
        alerts.emplace(Alert::deserialize(it.path()));
}

void AlertsManager::updateServer() const {
    for (const auto& alert : alerts)
        alert.second.serialize(clientName,"../server/");
}

void AlertsManager::setClientName(const string &cname) {
    clientName = cname;
}

bool AlertsManager::saveAsFile(const string &object) {
    bool found{false};

    const auto it = alerts.find(object);

    if (it != alerts.end()) {
        it->second.serialize(clientName);
        found = true;
    }
    return found;
}

bool AlertsManager::setRead(const string &object) {
    bool found{false};

    const auto it = alerts.find(object);

    if (it != alerts.end()) {
        it->second.setRead();
        found = true;
    }
    return found;
}

vector<string> AlertsManager::returnAll() const {
    vector<string> all;

    for (const auto& alert : alerts)
        all.push_back(alert.first);

    return all;
}

vector<string> AlertsManager::returnGeneral() const {
    vector<string> general;

    for (const auto& alert : alerts) {
        if (!alert.second.isPersonal())
            general.push_back(alert.first);
    }
    return general;
}

vector<string> AlertsManager::returnPersonal() const {
    vector<string> personal;

    for (const auto& alert : alerts) {
        if (alert.second.isPersonal())
            personal.push_back(alert.first);
    }
    return personal;
}

vector<string> AlertsManager::returnUnread() const {
    vector<string> unread;

    for (const auto& alert : alerts) {
        if (!alert.second.isRead())
            unread.push_back(alert.first);
    }
    return unread;
}

pair<bool,const Alert*> AlertsManager::returnSpecific(const string& object) const {
    bool found{false};
    const Alert* alert{nullptr};

    const auto it = alerts.find(object);

    if (it != alerts.end()) {
        alert = &it->second;
        found = true;
    }

    return make_pair(found,alert);
}

void AlertsManager::addAlert(const string& object, const string& message, bool r, bool pers, const string& date) {
    alerts.emplace(object, Alert(object,message,r,pers,date));
}
