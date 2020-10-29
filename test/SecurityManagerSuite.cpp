//
// Created by rebecca on 10/28/20.
//

#include "gtest/gtest.h"

#include "../project_files/profile_classes/SecurityManager.h"

class SecurityManagerSuite : public testing::Test {

protected:
    virtual void SetUp(){
        settedSecurityManager = new SecurityManager("Quanti giorni ha novembre?", "30",false);
    }

    virtual void TearDown(){
        delete settedSecurityManager;
    }

    SecurityManager* settedSecurityManager;
};

TEST_F(SecurityManagerSuite, checkAnswerTest) {

    EXPECT_FALSE(settedSecurityManager->checkAnswer("31"));

    EXPECT_TRUE(settedSecurityManager->checkAnswer("30"));
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
