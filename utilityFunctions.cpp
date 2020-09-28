//
// Created by Rebecca on 28/09/2020.
//

#include "utilityFunctions.h"

#include <iostream>
#include <string>

const string utilityFunctions::getStringInput() {
    string input;
    cin >> input;
    return input;
}

const unsigned int utilityFunctions::getNumInput() {
    unsigned int num;
    cin >> num;
    return num;
}
