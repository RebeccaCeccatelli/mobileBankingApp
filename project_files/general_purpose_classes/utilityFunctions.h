//
// Created by Rebecca on 28/09/2020.
//

#ifndef MOBILE_BANKING_APP_UTILITYFUNCTIONS_H
#define MOBILE_BANKING_APP_UTILITYFUNCTIONS_H

#include <string>

#include "InputManager.h"

using namespace std;

namespace utilityFunctions {

    string getStringInput();
    int getNumInput();
    string getLineInput();

    //used by BankingAccountView and ChargeCardView
    bool wantToSaveAsFile();
    string decideSortingLogic();
    string insertFilter(const string& request);

    string insertCurrentPIN();

    static const string BACK = "0";
    static const string YES = "yes";
    static const string NO = "no";
    static const string SORT_BY_DATE = "sd";
    static const string FILTER_DATE = "fd";
    static const string FILTER_CATEGORY = "fc";

}

#endif //MOBILE_BANKING_APP_UTILITYFUNCTIONS_H
