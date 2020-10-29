//
// Created by rebecca on 10/28/20.
//

#include "gtest/gtest.h"
#include <vector>

#include "../project_files/AlertsManager.h"

class AlertsManagerSuite : public testing::Test {
protected:
    virtual void SetUp(){
        alertsManager.addAlert("alert1","message1",false,false,"everyday");
        alertsManager.addAlert("alert2","message2",false,true,"everyday");
        alertsManager.addAlert("alert3","message3",true,false,"everyday");
        alertsManager.addAlert("alert4","message4",true,true,"everyday");
        alertsManager.addAlert("alert5","message5",false,false,"everyday");
        alertsManager.addAlert("alert6","message6",false,true,"everyday");
    }

    AlertsManager alertsManager;
};

TEST_F(AlertsManagerSuite, returnAllTest) {

    auto vector = alertsManager.returnAll();
    EXPECT_EQ(vector.size(),6);

    alertsManager.addAlert("alert7","message7",false,false,"everyday");
    vector = alertsManager.returnAll();
    EXPECT_EQ(vector.size(),7);
}

TEST_F(AlertsManagerSuite, returnGeneralTest) {
    auto vector = alertsManager.returnGeneral();

    EXPECT_EQ(vector.size(),3);

    bool found = any_of(vector.begin(),vector.end(),[](const string& alert){return alert == "alert2";});
    EXPECT_FALSE(found);

    found = any_of(vector.begin(),vector.end(),[](const string& alert){return alert == "alert1";});
    EXPECT_TRUE(found);
}

TEST_F(AlertsManagerSuite, returnPersonalTest) {
    auto vector = alertsManager.returnPersonal();

    EXPECT_EQ(vector.size(),3);

    bool found = any_of(vector.begin(),vector.end(),[](const string& alert){return alert == "alert6";});
    EXPECT_TRUE(found);
}

TEST_F(AlertsManagerSuite, returnUnreadTest) {
    auto vector = alertsManager.returnUnread();

    ASSERT_EQ(vector.size(),4);

    bool found = any_of(vector.begin(),vector.end(),[](const string& alert){return alert == "alert5";});
    ASSERT_TRUE(found);

    found = any_of(vector.begin(),vector.end(),[](const string& alert){return alert == "alert3";});
    ASSERT_FALSE(found);
}

TEST_F(AlertsManagerSuite, setReadTest) {
    auto vector = alertsManager.returnUnread();
    //verify initial conditions
    ASSERT_EQ(vector.size(),4);
    bool found = any_of(vector.begin(),vector.end(),[](const string& alert){return alert == "alert5";});
    ASSERT_TRUE(found);

    //act
    alertsManager.setRead("alert5");

    vector = alertsManager.returnUnread();
    found = any_of(vector.begin(),vector.end(),[](const string& alert){return alert == "alert5";});
    //assert
    ASSERT_FALSE(found);

    //act
    alertsManager.setRead("alert1");
    vector = alertsManager.returnUnread();
    //assert
    ASSERT_EQ(vector.size(),2);
}

TEST_F(AlertsManagerSuite,saveAsFileTest) {

    EXPECT_TRUE(alertsManager.saveAsFile("alert2"));

    EXPECT_FALSE(alertsManager.saveAsFile("nothing"));
}

TEST_F(AlertsManagerSuite, returnSpecificTest) {
    pair<bool,const Alert*> searchResult;

    searchResult = alertsManager.returnSpecific("alert4");

    ASSERT_TRUE(searchResult.first);
    ASSERT_NE(searchResult.second, nullptr);

    searchResult = alertsManager.returnSpecific("newAlert");

    ASSERT_FALSE(searchResult.first);
    ASSERT_EQ(searchResult.second,nullptr);

    alertsManager.addAlert("newAlert","newMessage",false,false,"everyday");
    searchResult = alertsManager.returnSpecific("newAlert");

    ASSERT_TRUE(searchResult.first);
    ASSERT_NE(searchResult.second, nullptr);
}