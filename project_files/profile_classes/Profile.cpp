//
// Created by rebecca on 10/28/20.
//

#include "Profile.h"

#include <fstream>
#include <string>

using namespace std;

const string Profile::YES = "yes";

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
            if (line == YES)
                news = true;
        }
        it++;
    }
    iFile.close();

    return Profile(name, addr, mail, num, news);
}

void Profile::setClientName(string name) {
    cname = move(name);
}

const string &Profile::getName() const {
    return cname;
}

void Profile::setResidentialAddress(string address) {
    residentialAddress = move(address);
}

const string &Profile::getResidentialAddress() const {
    return residentialAddress;
}

void Profile::setEmail(string mail) {
    email = move(mail);
}

const string &Profile::getEmail() const {
    return email;
}

void Profile::setTelephoneNumber(string number) {
    telephoneNumber = move(number);
}

const string &Profile::getTelephoneNumber() const {
    return telephoneNumber;
}

void Profile::changeNewsletterSettings() {
    newsletter = !newsletter;
}

bool Profile::isNewsletter() {
    return newsletter;
}
