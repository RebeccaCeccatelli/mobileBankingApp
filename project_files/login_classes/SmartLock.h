//
// Created by rebecca on 10/27/20.
//

#ifndef MOBILE_BANKING_APP_SMARTLOCK_H
#define MOBILE_BANKING_APP_SMARTLOCK_H

#include <string>

using namespace std;

class SmartLock {
public:
    SmartLock() = default;
    SmartLock(string titCode, string cname, bool r) : titolarCode{move(titCode)}, clientNickname{move(cname)},
        remembered{r} {}

    void setClientNickname(string cname);
    const string &getClientNickname() const;
    void setTitolarCode(const string& titCode);
    const string& getTitolarCode();
    void setRemembered(bool rem);
    bool isRemembered() const;

    void serialize() const;
    void reset();

    static SmartLock deserialize();

private:
    //attributes
    string titolarCode{"0"};
    string clientNickname{"client"};
    bool remembered{false};

    //class constant
    static const string YES;
};


#endif //MOBILE_BANKING_APP_SMARTLOCK_H
