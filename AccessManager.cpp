//
// Created by Rebecca on 28/09/2020.
//

#include "AccessManager.h"

#include <iostream>
#include <string>

using namespace std;

void AccessManager::login() {
    cout << "*** Login page ***" << endl;
    cout << "Insert your titolar code: " << endl;

}

const string &AccessManager::getName() const {
    return clientName;
}
