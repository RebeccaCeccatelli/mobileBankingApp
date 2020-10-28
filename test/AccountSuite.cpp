//
// Created by rebecca on 10/28/20.
//

#include "gtest/gtest.h"

#include "../project_files/Account.h"

TEST(AccountSuite, areCorrectCredentialsTest) {
    Account testingAccount("1234567","12345","anything");

    ASSERT_FALSE(testingAccount.areCorrectCredentials("01234567","1234500"));
    ASSERT_FALSE(testingAccount.areCorrectCredentials("0000000","12345"));
    ASSERT_FALSE(testingAccount.areCorrectCredentials("1234567","00000"));

    ASSERT_TRUE(testingAccount.areCorrectCredentials("1234567","12345"));
}