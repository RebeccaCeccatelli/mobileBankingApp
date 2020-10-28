//
// Created by rebecca on 10/28/20.
//

#include "gtest/gtest.h"

#include "../project_files/SmartLock.h"

TEST (SmartLockSuite, ResetTest){
    //arrange
    SmartLock settedSmartLock("3214567","Giacomo",true);
    //act
    settedSmartLock.reset();
    //assert
    EXPECT_EQ(settedSmartLock.getTitolarCode(),"0");
    EXPECT_EQ(settedSmartLock.getClientNickname(),"client");
    EXPECT_EQ(settedSmartLock.isRemembered(),false);
}
