//
// Created by rebecca on 10/29/20.
//

#include "gtest/gtest.h"

#include "../project_files/reminder_classes/Reminder.h"

TEST(ReminderSuite, setSavedTest){
    Reminder reminder("testing","setSaved()");
    //verify initial settings before testing
    ASSERT_FALSE(reminder.isSaved());
    //act
    reminder.setSaved();
    //assert
    ASSERT_TRUE(reminder.isSaved());
}
