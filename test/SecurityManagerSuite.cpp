//
// Created by rebecca on 10/28/20.
//

#include "gtest/gtest.h"

#include "../project_files/profile_classes/SecurityManager.h"
#include "../project_files/login_classes/Account.h"

class SecurityManagerSuite : public testing::Test {

protected:
    virtual void SetUp(){
        account = new Account("1234567","12345","Carlo Servetti");
        settedSecurityManager = new SecurityManager("Quanti giorni ha novembre?", "30",
            false, account);
    }

    virtual void TearDown(){
        delete settedSecurityManager;
        delete account;
    }

    SecurityManager* settedSecurityManager;
    Account* account;
};

TEST_F(SecurityManagerSuite, checkAnswerTest) {

    EXPECT_FALSE(settedSecurityManager->checkAnswer("31"));

    EXPECT_TRUE(settedSecurityManager->checkAnswer("30"));
}

TEST_F(SecurityManagerSuite, checkCurrentPINTest) {

    EXPECT_EQ(account->getPIN(),"12345");

    EXPECT_TRUE(settedSecurityManager->checkCurrentPIN("12345"));
}

TEST_F(SecurityManagerSuite, changeDigitalKeyTest) {
    EXPECT_FALSE(settedSecurityManager->isDigitalKey());
    //act
    settedSecurityManager->changeDigitalKey();
    //assert
    EXPECT_TRUE(settedSecurityManager->isDigitalKey());
}

TEST_F(SecurityManagerSuite, changeSecurityQuestionTest) {
    //verify default settings before testing
    EXPECT_TRUE(settedSecurityManager->checkAnswer("30"));
    //act
    settedSecurityManager->changeSecurityQuestion("Quanti giorni ha marzo?","31");
    //assert
    ASSERT_EQ(settedSecurityManager->getQuestion(), "Quanti giorni ha marzo?");
    ASSERT_TRUE(settedSecurityManager->checkAnswer("31"));
}

TEST_F(SecurityManagerSuite, setNewPinTest) {
    //verify preconditions
    EXPECT_TRUE(settedSecurityManager->checkCurrentPIN("12345"));

    settedSecurityManager->setNewPin("55555");

    ASSERT_FALSE(settedSecurityManager->checkCurrentPIN("12345"));
    ASSERT_TRUE(settedSecurityManager->checkCurrentPIN("55555"));

    ASSERT_EQ(account->getPIN(),"55555");
}
