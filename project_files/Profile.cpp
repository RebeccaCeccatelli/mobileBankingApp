//
// Created by rebecca on 10/15/20.
//

#include "Profile.h"

#include <iostream>
#include <fstream>

#include "utilityFunctions.h"

using namespace utilityFunctions;
using namespace std;

Profile::Profile(string name, string addr, string mail, string num, bool news) : cname {move(name)},
    residentialAddress{move(addr)}, email {move(mail)}, telephoneNumber{move(num)},
    newsletter{news} {}

void Profile::serialize(const string &name) const {
    string path = "../server/" + name + "/profile/personal_informations";
    ofstream oFile (path);

    oFile << "-Client name: " << cname;
    oFile << "\n\n-Residential address: " <<  residentialAddress;
    oFile << "\n\n-Email: " << email;
    oFile << "\n\n-Telephone number: " << telephoneNumber;
    oFile << "\n\n-Inscribed to newsletter: ";
    if (newsletter)
        oFile << "yes";
    else
        oFile << "no";

    oFile.close();
}

Profile Profile::deserialize(const string &extractedPath) {
    ifstream iFile (extractedPath);

    string line, name, addr, mail, num;
    bool news{false};

    int it = 0;
    while (getline(iFile,line,'-') && it<=5){
        if (it == 1){
            line.erase(0,13);
            line.erase(line.end()-2,line.end());
            name = line;
        }
        if (it == 2){
            line.erase(0,21);
            line.erase(line.end()-2,line.end());
            addr = line;
        }
        if(it == 3){
            line.erase(0,7);
            line.erase(line.end()-2,line.end());
            mail = line;
        }
        if (it == 4){
            line.erase(0,18);
            line.erase(line.end()-2,line.end());
            num = line;
        }
        if (it == 5){
            line.erase(0,25);
            if (line == "yes")
                news = true;
        }
        it++;
    }
    iFile.close();

    return Profile(name,addr,mail,num,news);
}

void Profile::display() {
    cout << endl << "*** Personal informations. ***" << endl;
    cout << "-Client name: " << cname << " (1)" << endl;
    cout << "-Residential address: " <<  residentialAddress << " (2)" << endl;
    cout << "-Email: " << email << " (3)" << endl;
    cout << "-Telephone number: " << telephoneNumber << " (4)" << endl;
    cout << "-Inscribed to newsletter: ";
    if (newsletter)
        cout << "yes" << " (5)" << endl;
    else
        cout << "no" << " (5)" << endl;
    cout << "Enter the corresponding number to modify the information, (0) to go back." << endl;

    manageInput(getStringInput());
}

bool Profile::isCorrectInput(const string &input) {
    bool correct = true;

    if (input == "1" || input == "2" || input == "3" || input == "4") {
        cout << "Insert new: ";
        string newSetting = getLineInput();

        if (input == "1")
            cname = newSetting;
        else if (input == "2")
            residentialAddress = newSetting;
        else if (input == "3")
            email = newSetting;
        else if (input == "4")
            telephoneNumber= newSetting;
    }
    else if (input == "5")
        changeNewsletterSettings();
    else if (input == "0")
        setGoBack(true);
    else
        correct = false;

    return correct;
}

void Profile::tryAgain() {
    display();
}


void Profile::enableFailureRoutine() {
    cout << "There is no maximum limit here, you can try again. " << endl;
    display();
}

void Profile::changeNewsletterSettings() {
    newsletter = !newsletter;
}
