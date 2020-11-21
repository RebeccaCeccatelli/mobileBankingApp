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

vector<string> AlertsManager::returnSelected(requestedAlerts request) const {
    vector<string> list;

    for (const auto& alert : alerts) {
        if (request == requestedAlerts::all)
            list.push_back(alert.first);

        else if (request == requestedAlerts::general) {
            if (!alert.second.isPersonal())
                list.push_back(alert.first);
        }
        else if (request == requestedAlerts::personal) {
            if (alert.second.isPersonal())
                list.push_back(alert.first);
        }
        else if (request == requestedAlerts::unread) {
            if (!alert.second.isRead())
                list.push_back(alert.first);
        }
    }
    return list;
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

