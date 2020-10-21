//
// Created by Rebecca on 28/09/2020.
//

#include "utilityFunctions.h"

#include <iostream>
#include <string>

string utilityFunctions::getStringInput() {
    string input;
    cin.ignore();
    cin >> input;
    return input;
}

unsigned int utilityFunctions::getNumInput() {
    unsigned int num;
    cin.ignore();
    cin >> num;
    return num;
}

string utilityFunctions::getLineInput() {
    string input;
    cin.ignore();
    getline(cin, input, '/');
    return input;
}
