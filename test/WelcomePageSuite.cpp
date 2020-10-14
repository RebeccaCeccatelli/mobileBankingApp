//
// Created by rebecca on 10/13/20.

#include "gtest/gtest.h"
#include "../WelcomePage.h"

TEST(WelcomePageSuite, isCorrectInputTest) {
    //Arrange
    WelcomePage welcomePage;
    //Act and Assert
    ASSERT_TRUE(welcomePage.isCorrectInput("login"));
    ASSERT_TRUE(welcomePage.isCorrectInput("exit"));
    ASSERT_FALSE(welcomePage.isCorrectInput("anything_else"));
    ASSERT_FALSE(welcomePage.isCorrectInput("123"));
}

