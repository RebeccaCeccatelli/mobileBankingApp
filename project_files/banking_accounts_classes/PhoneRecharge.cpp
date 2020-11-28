//
// Created by rebecca on 10/19/20.
//

#include "PhoneRecharge.h"

void PhoneRecharge::setRecipient(string mobOperator, string num) {
    mobileOperator = move(mobOperator);
    telephoneNumber = move(num);
}

BOOST_CLASS_EXPORT_GUID(PhoneRecharge, "PhoneRecharge"); //controllare che polimorfismo funzioni TODO

