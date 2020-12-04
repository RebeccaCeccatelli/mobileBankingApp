//
// Created by rebecca on 10/29/20.
//

#include "gtest/gtest.h"
#include <vector>

#include "../project_files/reminder_classes/RemindersManager.h"

using namespace std;

class RemindersManagerSuite : public testing::Test {
protected:
    virtual void SetUp(){
        remindersManager.createReminder("reminder1","text1");
        remindersManager.createReminder("reminder2","text2");
        remindersManager.createReminder("reminder3","text3");
    }

    RemindersManager remindersManager;
};

TEST_F(RemindersManagerSuite, returnAllTest) {
    auto vector = remindersManager.returnAll();
    EXPECT_EQ(vector.size(),3);

    remindersManager.createReminder("reminder4","text4");
    vector = remindersManager.returnAll();
    EXPECT_EQ(vector.size(),4);
}

TEST_F(RemindersManagerSuite, saveAsFileTest) {

    EXPECT_TRUE(remindersManager.saveAsFile("reminder2"));

    EXPECT_FALSE(remindersManager.saveAsFile("nothing"));
}

TEST_F(RemindersManagerSuite, returnSpecificTest) {
    pair<bool,const Reminder*> searchResult;

    searchResult = remindersManager.returnSpecific("reminder3");

    ASSERT_TRUE(searchResult.first);
    ASSERT_NE(searchResult.second, nullptr);

    searchResult = remindersManager.returnSpecific("newReminder");

    ASSERT_FALSE(searchResult.first);
    ASSERT_EQ(searchResult.second,nullptr);

    remindersManager.createReminder("newReminder","newText");
    searchResult = remindersManager.returnSpecific("newReminder");

    ASSERT_TRUE(searchResult.first);
    ASSERT_NE(searchResult.second, nullptr);
}
