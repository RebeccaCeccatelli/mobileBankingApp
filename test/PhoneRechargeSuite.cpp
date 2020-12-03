//
// Created by rebecca on 12/3/20.
//

#include "gtest/gtest.h"

#include "../project_files/banking_accounts_classes/PhoneRecharge.h"

TEST(PhoneRechargeSuite, constructorTest){
    auto userInformations = make_tuple("iliad","3471820456",15);
    PhoneRecharge phoneRecharge(userInformations);

    ASSERT_EQ(phoneRecharge.getAmount(),15);
    ASSERT_EQ(phoneRecharge.getDescription(), "phone recharge");
    ASSERT_EQ(phoneRecharge.getCategory(),"telephony");

    ASSERT_EQ(phoneRecharge.getRecipient().first,"iliad");
    ASSERT_EQ(phoneRecharge.getRecipient().second,"3471820456");
}