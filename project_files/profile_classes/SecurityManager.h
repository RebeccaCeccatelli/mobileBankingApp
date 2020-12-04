//
// Created by rebecca on 10/28/20.
//

#ifndef MOBILE_BANKING_APP_SECURITYMANAGER_H
#define MOBILE_BANKING_APP_SECURITYMANAGER_H

#include <string>

using namespace std;

class Account;

class SecurityManager {
public:
    SecurityManager(string question, string answer, bool digKey, Account *account);
    SecurityManager() = default;

    void setAccountReference(Account* account);

    void serialize(const string& cname) const;
    SecurityManager deserialize(const string& extractedPath);

    const string& getQuestion() const;
    bool checkAnswer(const string& answer) const;
    bool isDigitalKey() const;
    bool checkCurrentPIN(const string& input) const;

    void changeDigitalKey();
    void changeSecurityQuestion(string question, string answer);
    void setNewPin(string newPIn);

private:
    bool digitalKey{false};
    pair<string,string> securityQuestion{make_pair("none", "none")};

    Account* accountReference{nullptr};

    //constant
    static const string YES;
};


#endif //MOBILE_BANKING_APP_SECURITYMANAGER_H
