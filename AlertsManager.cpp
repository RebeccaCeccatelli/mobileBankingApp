//
// Created by Rebecca on 01/10/2020.
//

#include "AlertsManager.h"

#include "AlertsManager.h"

void AlertsManager::createAlert() {
    Alert newAlert;
    newAlert.serialize(clientName);
}

void AlertsManager::setClientName(const string &cname) {
    clientName = cname;
}
