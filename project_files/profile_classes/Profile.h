//
// Created by rebecca on 10/28/20.
//

#ifndef MOBILE_BANKING_APP_PROFILE_H
#define MOBILE_BANKING_APP_PROFILE_H

#include <string>

using namespace std;

class Profile {
public:
    Profile() = default;
    Profile(string name, string addr, string mail, string num, bool news) : cname{move(name)},
        residentialAddress{move(addr)}, email{move(mail)}, telephoneNumber{move(num)}, newsletter{news} {}

    void serialize(const string &name) const;
    static Profile deserialize(const string& extractedPath);

    void setClientName(string name);
    const string& getName() const;
    void setResidentialAddress(string address);
    const string& getResidentialAddress() const;
    void setEmail(string mail);
    const string& getEmail() const;
    void setTelephoneNumber(string number);
    const string& getTelephoneNumber() const;

    void changeNewsletterSettings();
    bool isNewsletter();


private:
    string cname {"client"};
    string residentialAddress {"unknown"};
    string email {"unknown"};
    string telephoneNumber{"unknown"};
    bool newsletter {true};

    //constant
    static const string YES;
};


#endif //MOBILE_BANKING_APP_PROFILE_H
