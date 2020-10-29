//
// Created by rebecca on 10/28/20.
//

#include "gtest/gtest.h"

#include "../project_files/Alert.h"

TEST(AlertSuite, setReadTest){
    Alert alert("testing","setRead()", false,false,"everyday");
    //verify initial settings before testing
    EXPECT_FALSE(alert.isRead());
    //act
    alert.setRead();
    //assert
    ASSERT_TRUE(alert.isRead());
}

