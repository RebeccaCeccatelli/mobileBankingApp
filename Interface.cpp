//
// Created by rebecca on 10/7/20.
//

#include "Interface.h"

void Interface::displayUserInterface() {
    while (!isGoBack())
        display();
    resetGoBack();
}

void Interface::setGoBack(bool l) {
    goBack = l;
}

bool Interface::isGoBack() const {
    return goBack;
}

void Interface::resetGoBack() {
    goBack = false;
}

