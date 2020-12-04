//
// Created by rebecca on 10/27/20.
//

#include "gtest/gtest.h"

#include "../project_files/login_classes/AccessManager.h"

TEST(AccessManagerSuite, CheckCredentialsTest){
    AccessManager accessManager("yes");

    accessManager.setTitolarCode("7777777");
    accessManager.setPIN("77777");
    ASSERT_TRUE(accessManager.checkCredentials());

    string newTitolarCode = "13255", newPIN = "00011";
    accessManager.setTitolarCode(newTitolarCode);
    accessManager.setPIN(newPIN);
    ASSERT_FALSE(accessManager.checkCredentials());

    accessManager.addAccount(newTitolarCode,newPIN,"andrea_agnoletti");
    ASSERT_TRUE(accessManager.checkCredentials());
}