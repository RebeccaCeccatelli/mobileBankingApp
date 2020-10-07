//
// Created by rebecca on 10/7/20.
//

#include "Interface.h"

void Interface::setGoBack(bool l) {
    goBack = l;
}

bool Interface::isGoBack() const {
    return goBack;
}

void Interface::resetGoBack() {
    goBack = false;
}

void Interface::displayUserInterface(Interface* specificClass) {
    while (!specificClass->isGoBack())
        specificClass->display();
    specificClass->resetGoBack();
}
