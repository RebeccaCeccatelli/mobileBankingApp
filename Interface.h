//
// Created by rebecca on 10/7/20.
//

#ifndef MOBILE_BANKING_APP_INTERFACE_H
#define MOBILE_BANKING_APP_INTERFACE_H


class Interface {
public:
    void displayUserInterface();

protected:
    virtual void display() = 0;
    void setGoBack(bool l);

private:
    bool isGoBack() const;
    void resetGoBack();

    bool goBack{false};
};


#endif //MOBILE_BANKING_APP_INTERFACE_H
