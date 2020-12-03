//
// Created by rebecca on 12/3/20.
//

#include "gtest/gtest.h"

#include "../project_files/banking_accounts_classes/Compare.h"

TEST(CompareSuite, operatorTest) {
    Compare compare;

    ASSERT_TRUE(compare("11/23/19 12:33:20", "11/23/20 12:33:20"));
    ASSERT_FALSE(compare("01/01/20 00:00:00","12/31/19 23:59:59"));
    ASSERT_FALSE(compare("12/03/20 10:55:30","12/03/20 10:55:30"));

    ASSERT_TRUE(compare("12/03/20 10:55:30","12/03/20 10:55:32"));
    ASSERT_FALSE(compare("11/29/20 18:34:56", "11/27/19 23:10:24"));
}

