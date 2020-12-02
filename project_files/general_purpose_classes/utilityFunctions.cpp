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

int utilityFunctions::getNumInput() {
    int num;
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

bool utilityFunctions::wantToSaveAsFile() {
    cout << "Do you want to save these informations in a readable format in your saved files?" << endl;
    string input = getStringInput();

    if (input == YES)
        return true;
    if (input == NO)
        return false;
    else {
        cout << "Your input is not correct. Try again. " << endl;
        return wantToSaveAsFile();
    }
}

string utilityFunctions::decideSortingLogic() {
    cout << endl << "- Sort all by date (sd). "  << endl << "- Filter by requested date (fd). " << endl <<
         "- Filter by category (fc). " << endl << "- Go back (0). " << endl;
    string input = getStringInput();

    return input;
}

string utilityFunctions::insertFilter(const string &request) {
    if (request == FILTER_DATE)
        cout << "Please, insert a specific date in format mm/dd/yy: " << endl;
    else if (request == FILTER_CATEGORY)
        cout << "Please, insert a category between:\ntransports, food, telephony, fuel, taxes, general, clothing, sports, health, restaurants, freetime. " << endl;
    auto filter = getStringInput();

    return filter;
}
