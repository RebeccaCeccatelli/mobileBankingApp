//
// Created by Rebecca on 01/10/2020.
//

#include "Alert.h"

#include <fstream>
#include <string>

using namespace std;

Alert::Alert(string obj, string mex, bool r, bool pers, string date) : object{move(obj)}, message{move(mex)},
    read{r}, personal{pers} {
    dateSetter.setDate(move(date),1);
}

void Alert::serialize(const string &cname, string mainDirectory) const {
    string path = move(mainDirectory)+ cname + "/alerts/" + object;
    ofstream oFile (path);

    oFile << "-Object: " << object;
    oFile << "\n\n-Message: " << message;
    oFile << "\n\n-Arrival date: " << dateSetter.getDate();
    oFile << "\n\n-Read: ";
    if (isRead())
        oFile << "yes";
    else
         oFile << "no";
    oFile << "\n\n-Personal: ";
    if (personal)
        oFile << "yes";
    else
        oFile << "no";

    oFile.close();
}

pair<string, Alert> Alert::deserialize(const string& extractedPath) {
    ifstream iFile(extractedPath);

    string line, object, message, arrivalDate;
    bool r{false}, pers{false};

    int it = 0;
    while (getline(iFile,line,'-') && it<=5){
        if (it == 1){
            line.erase(0,8);
            line.erase(line.end()-2,line.end());
            object = line;
        }
        if (it == 2){
            line.erase(0,9);
            line.erase(line.end()-2,line.end());
            message = line;
        }
        if(it == 3){
            line.erase(0,14);
            line.erase(line.end()-2,line.end());
            arrivalDate = line;
        }
        if (it == 4){
            line.erase(0,6);
            line.erase(line.end()-2,line.end());
            if (line == "yes")
                r = true;
        }
        if (it == 5){
            line.erase(0,10);
            if (line == "yes")
                pers = true;
        }
        it++;
    }
    iFile.close();

    return make_pair(object, Alert(object,message,r,pers,arrivalDate));
}

void Alert::setRead() {
    if (!isRead())
        read = true;
}

bool Alert::isRead() const {
    return read;
}

bool Alert::isPersonal() const {
    return personal;
}
