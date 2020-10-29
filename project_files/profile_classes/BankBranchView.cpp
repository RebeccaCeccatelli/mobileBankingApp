//
// Created by rebecca on 10/21/20.
//

#include "BankBranchView.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

BankBranchView BankBranchView::deserialize(const string &exctractedPath) {
    ifstream iFile(exctractedPath);

    string line, address, assignedManager, telephoneNumber;

    int it = 0;
    while (getline(iFile,line,'-') && it<=3){
        if (it == 1){
            line.erase(0,9);
            line.erase(line.end()-2,line.end());
            address = line;
        }
        if (it == 2){
            line.erase(0,18);
            line.erase(line.end()-2,line.end());
            assignedManager = line;
        }
        if(it == 3){
            line.erase(0,18);
            telephoneNumber = line;
        }
        it++;
    }

    iFile.close();

    return BankBranchView(address, assignedManager, telephoneNumber);
}

void BankBranchView::display() {
    cout << endl << "*** Your physical bank branch. *** " << endl;
    cout << "-Address: " << address << endl << "-Assigned manager: " << assignedManager << endl
        << "-Telephone number: " << telephoneNumber << endl;
}
